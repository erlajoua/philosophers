# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/29 11:02:42 by erlajoua          #+#    #+#              #
#    Updated: 2021/04/29 11:02:42 by erlajoua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_three

SRCS =	display.c \
		error.c \
		ft_atoi.c  \
		ft_strlen.c \
		get_time.c \
		init_forks.c \
		init_params.c \
		init_philos.c \
		init_process.c \
		main.c \
		philo_eat.c \
		philo_sleep.c \
		philo_think.c \
		parsing.c

OBJS= $(addprefix srcs/,$(SRCS:.c=.o))

CC= gcc

CFLAGS= -Wall -Werror -Wextra

HEADER= -I includes

LIBS= -lpthread

.c.o:
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
