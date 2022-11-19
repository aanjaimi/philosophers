# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aanjaimi <aanjaimi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/23 01:09:43 by aanjaimi          #+#    #+#              #
#    Updated: 2022/04/15 06:37:03 by aanjaimi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = philo
NAME2 = philo_bonus
INC = man/philo.h bonus/philo_bonus.h
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
COMP_LINUX = -lpthread
SRCS = man/main.c \
		man/parse.c \
		man/philo.c \
		man/time.c \
		man/lifetime.c \
		man/forks.c
SRCS_B = bonus/main_bonus.c \
		bonus/check.c \
		bonus/ft_itoa.c \
		bonus/ft_strjoin.c \
		bonus/utils.c \
		bonus/philo_bonus.c \
		bonus/lifetime_bonus.c \
		bonus/forks_bonus.c
OBJS = $(SRCS:%.c=%.o)
OBJS_B = $(SRCS_B:%.c=%.o)
all:$(NAME1)
$(NAME1): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME1) $^ $(COMP_LINUX)

bonus:$(NAME2)
$(NAME2): $(OBJS_B)
	@$(CC) $(CFLAGS) -o $(NAME2) $^ $(COMP_LINUX)

%.o: %.c $(INC)
	@$(CC) $(CFLAGS) -c $< -o $@
	
clean :
	@$(RM) $(OBJS)
	@$(RM) $(OBJS_B)

fclean : clean
	@$(RM) $(NAME1)
	@$(RM) $(NAME2)

re : fclean all