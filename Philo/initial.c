/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <lgalstya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:29:13 by lgalstya          #+#    #+#             */
/*   Updated: 2022/10/29 13:14:23 by lgalstya         ###   ########.fr       */
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
		if (i == 1 && curr > 0 && curr <= 200)
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
	if (!argv[5])
		ph->num_of_eat = 0;
	return (1);
}

static void	forking(t_philo *pil, pthread_mutex_t *forks, int i)
{
	pil->index = i;
	if (i == pil->num_philo - 1)
	{
		pil->left = forks + i;
		pil->right = forks;
		return ;
	}
		pil->left = forks + i;
		pil->right = forks + (i + 1);
}

void	initial(t_arrays *arr, t_philo *ph)
{
	int	i;

	i = -1;
	ph->eat_counter = 0;
	ph->start_time = now();
	ph->timer = ph->start_time;
	arr->forks = malloc(sizeof(pthread_mutex_t) * ph-> num_philo);
	arr->philos = malloc(sizeof(t_philo) * ph->num_philo);
	arr->print_arr = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(arr->print_arr, NULL);
	while (++i < ph->num_philo)
		if (pthread_mutex_init(arr->forks + i, NULL))
			return ;
	i = -1;
	while (++i < ph->num_philo)
	{
		arr->philos[i] = *ph;
		arr->philos[i].write = arr->print_arr;
		forking(&arr->philos[i], arr->forks, i);
	}
}
