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
	printf("num_philo = %d\nt_die = %llu\nt_eat = %llu\nt_sleep = %llu\nnum_of_eat= %d\n", ph->num_philo, ph->t_die, ph->t_eat, ph->t_sleep, ph->num_of_eat);
	return (1);
}

//static void	forking(pthread_mutex_t *forks, t_philo *pil)
static void	forking(t_struct *pil, int i)
{
	if (pil->arr.philos[i].index == pil->phil.num_philo - 1)
	{
		pil->arr.philos[i].left = pil->arr.forks[pil->arr.philos[i].index];
		pil->arr.philos[i].right = pil->arr.forks[0];
	}
		pil->arr.philos[i].left = pil->arr.forks[pil->arr.philos[i].index];
		pil->arr.philos[i].right = pil->arr.forks[pil->arr.philos[i].index + 1];
}

void	initial(t_struct *pil)
{
	int				i;

	i = -1;
	pil->phil.start_time = now();
	pil->phil.timer = pil->phil.start_time;
	pil->arr.print_arr = malloc(sizeof(t_philo) * pil->phil.num_philo);
	pil->arr.forks = malloc(sizeof(pthread_mutex_t) * pil->phil.num_philo);
	pthread_mutex_init(pil->arr.print_arr, NULL);
	while (++i < pil->phil.num_philo)
		pthread_mutex_init(&pil->arr.forks[i], NULL);
	i = -1;
	while (++i < pil->phil.num_philo)
	{
		pil->phil.index = i;
		pil->arr.philos[i] = pil->phil;
		pil->arr.philos[i].write = pil->arr.print_arr;
		forking(pil, i);
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
