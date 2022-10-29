/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <lgalstya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:30:59 by lgalstya          #+#    #+#             */
/*   Updated: 2022/10/27 18:06:09 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*skittles(void *param)
{
	t_philo	*ph;

	ph = (t_philo *)param;
	if (ph->index % 2)
		ft_usleep(ph->t_eat);
	while (1)
	{
		pthread_mutex_lock(ph->left);
		for_print("has taken a left fork\n", ph, "\033[0;35m");
		pthread_mutex_lock(ph->right);
		for_print("has taken a right fork\n", ph, "\033[0;34m");
		for_print("is eating\n", ph, "\033[1;33m");
		++ph->eat_counter;
		ft_usleep(ph->t_eat - 1);
		pthread_mutex_unlock(ph->left);
		pthread_mutex_unlock(ph->right);
		ph->timer = now();
		for_print("is sleeping\n", ph, "\033[0;36m");
		ft_usleep(ph->t_sleep - 1);
		for_print("is thinking\n", ph, "\033[0;32m");
	}
	return (0);
}

int	create_th(t_arrays *arr, t_philo ph)
{
	int	i;

	i = -1;
	while (++i < ph.num_philo)
		if (pthread_create(&arr->philos[i].th, NULL,
				&skittles, arr->philos + i))
			return (0);
	i = -1;
	while (++i < ph.num_philo)
		if (pthread_detach(arr->philos[i].th))
			return (0);
	while (1)
	{
		if (!dielock(arr) || (ph.num_of_eat && !finish_eating(arr->philos)))
			return (0);
	}
	return (0);
}

int	dielock(t_arrays *arr)
{
	int	i;

	i = 0;
	while (i < arr->philos[i].num_philo)
	{
		if (now() - arr->philos[i].timer > arr->philos[i].t_die)
		{
			usleep(10);
			printf("\x1b[31m%llu\t%d is died\n",
				now() - arr->philos[i].start_time, arr->philos[i].index + 1);
			return (0);
		}
		++i;
	}
	return (1);
}

int	finish_eating(t_philo *arr)
{
	int	i;

	i = -1;
	while (++i < arr[0].num_philo)
	{
		if (arr[i].eat_counter < arr[i].num_of_eat)
			return (0);
	}
	return (1);
}
