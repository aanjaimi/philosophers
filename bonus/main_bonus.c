/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanjaimi <aanjaimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:49:16 by aanjaimi          #+#    #+#             */
/*   Updated: 2022/05/03 16:04:38 by aanjaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_utils			utils;
	sem_t			*print;
	int				ret;

	if (ac < 5 || ac > 6 || !check_args(ac, av, &utils))
	{
		write(2, "Wrong arguments\n", 16);
		return (1);
	}
	if (!utils.nb_meals)
	{
		printf("Everyone ate well, even though no one ate\n");
		return (0);
	}
	ret = 1;
	sem_unlink("print");
	print = sem_open("print", O_CREAT, S_IRWXU | S_IRWXG, 1);
	if (!launch_children(&utils, print))
		ret = 0;
	sem_close(print);
	sem_unlink("print");
	return (ret);
	while (1)
		;
}
