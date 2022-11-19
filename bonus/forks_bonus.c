/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanjaimi <aanjaimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:00:29 by aanjaimi          #+#    #+#             */
/*   Updated: 2022/04/13 15:31:30 by aanjaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	take_forks(t_philo *philo)
{
	if (*philo->stop == true)
		return (0);
	sem_wait(philo->forks);
	if (*philo->stop == true)
		return (0);
	sem_wait(philo->print);
	printf("%lums %zu has taken a fork\n", get_ts(philo->ts), philo->name);
	sem_post(philo->print);
	sem_wait(philo->forks);
	if (*philo->stop == true)
		return (0);
	sem_wait(philo->print);
	printf("%lums %zu has taken a fork\n", get_ts(philo->ts), philo->name);
	sem_post(philo->print);
	return (1);
}

sem_t	*init_forks(t_utils *utils)
{
	sem_t	*forks;

	sem_unlink("forks");
	forks = sem_open("forks", O_CREAT, S_IRWXU | S_IRWXG, utils->nb_philo);
	return (forks);
}
