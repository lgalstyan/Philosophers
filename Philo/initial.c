/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:29:13 by lgalstya          #+#    #+#             */
/*   Updated: 2022/10/18 16:45:57 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_correct(t_philo *ph, int argc, char **argv)
{
	int	i;
	int	curr;

	i = 0;
	while (++i < argc)
	{
		curr = ft_atoi(argv[i]);
		if (i == 1 && curr >= 1 && curr <= 200)
			ph->num_philo = curr;
		else if (i == 2 && curr >= 60)
			ph->t_die = curr;
		else if (i == 3 && curr >= 60)
			ph->t_eat = curr;
		else if (i == 4 && curr >= 60)
			ph->t_sleep = curr;
		else if (i == 5 && curr > 0)
			ph->num_of_eat = curr;
		else
			return (0);
	}
	return (1);
}

static void	forking(pthread_mutex_t *forks, t_philo *pil)
{
	if (pil->index == pil->num_philo - 1)
	{
		pil->left = forks[pil->index];
		pil->right = forks[0];
	}
		pil->left = forks[pil->index];
		pil->right = forks[pil->index + 1];
}

void	initial(t_philo *arr, t_philo pil, pthread_mutex_t *forks)
{
	int				i;
	pthread_mutex_t	pr;

	i = -1;
	pthread_mutex_init(&pr, NULL);
	pil.start_time = now();
	pil.timer = pil.start_time;
	while (++i < pil.num_philo)
		pthread_mutex_init(&forks[i], NULL);
	i = -1;
	while (++i < pil.num_philo)
	{
		pil.index = i;
		arr[i] = pil;
		arr[i].print = pr;
		forking(forks, &arr[i]);
	}
}

void	destructor(t_philo *arr, pthread_mutex_t *fork)
{
	int	i;

	i = 0;
	while (i < arr[0].num_philo)
	{
		pthread_mutex_destroy(&fork[i]);
		pthread_mutex_destroy(&arr[i].left);
		pthread_mutex_destroy(&arr[i].right);
		++i;
	}
	free(arr);
	free(fork);	
}
