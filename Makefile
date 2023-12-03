# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgonon <bgonon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/30 15:10:00 by artmarti          #+#    #+#              #
#    Updated: 2023/12/03 19:49:11 by bgonon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc
FLAGS = -Wall -Wextra -Werror

RM = rm
RMFLAG = -f

SRCS = main.c debug.c parsing/ft_split.c parsing/handle_quote.c parsing/parsing.c history/handle_history.c buildins/buildin.c buildins/cd.c buildins/echo.c buildins/env.c buildins/export.c buildins/export_utils.c buildins/pwd.c buildins/unset.c buildins/exit.c parsing/ft_moula.c signal/signal.c parsing/ft_split_pipe.c pipe/pipe.c redir/redirect.c utils/ft_isspace.c redir/redirect_utils.c redir/heredoc.c redir/redirect_exe.c parsing/ft_moula2.c

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
