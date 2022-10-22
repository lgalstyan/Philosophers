/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:26:05 by lgalstya          #+#    #+#             */
/*   Updated: 2022/10/18 16:46:34 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo			ph;
	t_philo			*arr;
	pthread_mutex_t	*fork;
	(void )argv;

	if (argc < 5 || argc > 6 || !check_correct(&ph, argc, argv))
		return (0);
	arr = malloc(sizeof(t_philo) * ph.num_philo);
	fork = malloc(sizeof(pthread_mutex_t) * ph.num_philo);
	if (!arr || !fork)
		return (0);
	initial(arr, ph, fork);
	create_th(arr);
	//sleep(1000);
	//free(arr);
	//free(fork);
	destructor(arr, fork);
	return (0);
	//mernelu jamanak jogel erba mernum chesht hashvarky
	//minchev hima jamanaky milinerov
	//grem im usleepy
	//utelu hashvark katarelu function
}
