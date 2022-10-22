/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:26:05 by lgalstya          #+#    #+#             */
/*   Updated: 2022/10/22 12:55:13 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_struct	tmp;

	if (argc < 5 || argc > 6 || !check_correct(&tmp.phil, argc, argv))
		return (0);
	tmp.arr.philos = malloc(sizeof(t_philo) * tmp.phil.num_philo);
	//arr = (t_philo *)malloc(sizeof(t_philo));
	//tmp->arr.forks = malloc(sizeof(pthread_mutex_t) * tmp->phil.num_philo);
	//fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!tmp.arr.philos)// || !fork)
		return (0);
	initial(&tmp);
	create_th(tmp.arr.philos);
	//sleep(1000);
	destructor(tmp.arr.philos, tmp.arr.forks);
	return (0);
	//mernelu jamanak jogel erba mernum chesht hashvarky
	//minchev hima jamanaky milinerov
	//grem im usleepy
	//utelu hashvark katarelu function
}
