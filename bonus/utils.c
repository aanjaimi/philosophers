/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanjaimi <aanjaimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:55:28 by aanjaimi          #+#    #+#             */
/*   Updated: 2022/04/07 14:55:29 by aanjaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	unlock_sync(sem_t *sync, unsigned int nb_philos)
{
	size_t	i;

	i = 0;
	while (i < nb_philos)
	{
		sem_post(sync);
		i++;
	}
}

size_t	get_time(void)
{
	struct timeval	tp;
	size_t			milliseconds;

	gettimeofday(&tp, NULL);
	milliseconds = tp.tv_sec * 1000;
	milliseconds += tp.tv_usec / 1000;
	return (milliseconds);
}

void	ft_sleep(size_t ms)
{
	size_t	curr;
	size_t	end;

	curr = get_time();
	end = curr + ms;
	while (get_time() < end)
		usleep(100);
}
