NAME = minishell

CC = gcc
FLAGS = #-Wall -Wextra -Werror

RM = rm
RMFLAG = -f

BUILDINS = buildins/buildin.c buildins/cd.c buildins/echo.c buildins/env.c buildins/export_utils.c buildins/export.c buildins/pwd.c buildins/unset.c

SRCS = main.c debug.c

LIBFT = libft/libft.a

OBJS := $(SRCS:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME): do_libft $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(LIBFT) $(BUILDINS) $(SRCS)  -lreadline

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
