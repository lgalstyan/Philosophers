/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:52:56 by lgalstya          #+#    #+#             */
/*   Updated: 2022/10/18 16:39:46 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long long now()
{
	struct timeval		time;
	unsigned long long	res;
	gettimeofday(&time, NULL);
	res = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (res);
}

void	ft_usleep(unsigned long long milisec)
{
	unsigned long long skizb;

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

void	for_print(char *str, t_philo *p, char *color)
{
	pthread_mutex_lock(&p->print);
	printf("%s%llu %d %s", color, now() - p->start_time, p->index + 1, str);
	pthread_mutex_unlock(&p->print);
}
