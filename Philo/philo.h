/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:58:17 by lgalstya          #+#    #+#             */
/*   Updated: 2022/10/16 17:38:21 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				num_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				num_of_eat;
	int				index;
	int				eat_counter;
	pthread_mutex_t	left;
	pthread_mutex_t	right;
	pthread_mutex_t	print;
	pthread_t		th;
	unsigned long long		timer;
	unsigned long long		start_time;
}	t_philo;

unsigned long long now();
long	ft_atoi(const char *str);
void	ft_usleep(unsigned long long milisec);
int		check_correct(t_philo *ph, int argc, char **argv);
void	initial(t_philo *arr, t_philo pil, pthread_mutex_t *forks);
int		dielock(t_philo *arr);
void	for_print(char *str, t_philo *p, char *col);
int		create_th(t_philo *arr);
void	destructor(t_philo *arr, pthread_mutex_t *fork);
#endif
