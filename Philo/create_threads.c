/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:30:59 by lgalstya          #+#    #+#             */
/*   Updated: 2022/10/18 16:36:29 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*skittles(void *p)
{
	t_philo	*ph;

	ph = (t_philo *)p;
	if (ph->index % 2)
		ft_usleep(ph->t_eat - 10);
	while (1)
	{
		pthread_mutex_lock(&ph->left);
		for_print("has taken a left fork\n", ph, "\033[0;35m");
		pthread_mutex_lock(&ph->right);
		for_print("has taken a right fork\n", ph, "\033[0;34m");
		for_print("is eating\n", ph, "\033[1;33m");
		ft_usleep(ph->t_eat);
		++ph->eat_counter;
		ph->timer = now();
		pthread_mutex_unlock(&ph->right);
		pthread_mutex_unlock(&ph->left);
		for_print("is sleeping\n", ph, "\033[0;36m");
		ft_usleep(ph->t_sleep);
		for_print("is thinking\n", ph, "\033[0;32m");
	}
	return (0);
}

int	create_th(t_philo *arr)
{
	int	i;

	i = -1;
	while (++i < arr[0].num_philo)
	{
		if (pthread_create(&arr[i].th, NULL, &skittles, (void *)&arr[i]))
			return (0);
	}
	i = -1;
	while (++i < arr[0].num_philo)
		pthread_detach(arr[i].th);
	while (1)
	{
		if (!dielock(arr))
			return (0);
	}
	return (0);
}

int	dielock(t_philo *arr)
{
	  int	i;

	  i = 0;
	  while (i < arr[0].num_philo)
	  {
		  if (now() - arr[i].timer > (unsigned long long)arr[i].t_die)
		  {
		  	usleep(10);
			printf("%llu\t%d  is died\n", now() - arr[i].start_time, arr[i].index + 1);
		  	return (0);
		  }
		  ++i;
	  }
	  return (1);
}

int	finish_eating(t_philo *arr)
{
	int	i;

	i = 0;
	while (i < arr[0].num_philo)
	{
		if(arr[i].eat_counter < arr[i].num_of_eat)
			return (0);
		++i;
	}
	return (1);
}
