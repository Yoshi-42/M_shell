# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: artmarti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/30 15:10:00 by artmarti          #+#    #+#              #
#    Updated: 2023/11/30 15:10:06 by artmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc
FLAGS = -Wall -Wextra -Werror

RM = rm
RMFLAG = -f

SRCS = main.c parsing/ft_split.c parsing/handle_dollard.c parsing/handle_quote.c parsing/parsing.c history/handle_history.c

LIBFT = libft/libft.a

OBJS := $(SRCS:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME): do_libft $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT) -lreadline

clean:
	$(RM) $(RMFLAG) $(OBJS)
	make -C ./libft clean

fclean: clean
	$(RM) $(RMFLAG) $(NAME)

re: fclean all

do_libft :
	make -C ./libft all

debug :
	$(CC) $(FLAGS) -g -o $(NAME)debug $(SRCS) $(LIBFT) -lreadline

.PHONY : all clean fclean re gdb check
