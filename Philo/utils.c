/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <lgalstya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:52:56 by lgalstya          #+#    #+#             */
/*   Updated: 2022/10/29 13:13:42 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	now(void)
{
	struct timeval		time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	for_print(char *str, t_philo *p, char *color)
{
	pthread_mutex_lock(p->write);
	printf("%s%llu\t%d  %s", color, now() - p->start_time, p->index + 1, str);
	pthread_mutex_unlock(p->write);
}

void	ft_usleep(long long milisec)
{
	long long	skizb;

	skizb = now();
	while (now() - skizb <= milisec)
		usleep(100);
}

long	ft_atoi(const char *str)
{
	int		c;
	long	n;

	c = 0;
	n = 0;
	if (!str)
		return (0);
	while ((str[c] >= '\t' && str[c] <= '\r') || str[c] == ' ')
		c++;
	if (str[c] == '+')
		c++;
	while (str[c])
	{
		if (str[c] >= '0' && str[c] <= '9')
		{
			if (n > 2147483647)
				return (-1);
			n = (str[c] - '0') + (n * 10);
		}
		else
			return (-1);
		c++;
	}
	return (n);
}
