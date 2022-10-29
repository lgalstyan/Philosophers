/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <lgalstya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:26:05 by lgalstya          #+#    #+#             */
/*   Updated: 2022/10/27 17:50:38 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo		phil;
	t_arrays	*tmp;

	if (argc < 5 || argc > 6 || !check_correct(&phil, argc, argv))
	{
		write(1, "Wrong arguments\n", 16);
		return (0);
	}
	tmp = (t_arrays *)malloc(sizeof(t_arrays));
	if (!tmp)
		return (0);
	initial(tmp, &phil);
	create_th(tmp, phil);
	free(tmp);
	return (0);
}
