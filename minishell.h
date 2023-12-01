#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "libft/libft.h"

typedef struct s_env
{
	char **env_cpy;
	char *key;
	char *value;
} t_env;

typedef struct s_command
{
	char	**cmd;
	int		fd_i;
	int		fd_o;
	int		status;
	t_env	env;
}	t_command;


typedef struct s_list
{
	t_command 		*cmd;
	struct s_list	*next;
}	t_list;

/*		PARSING		*/
char	**parsing(char *cmd);
char	**split(char *cmd, char c, int actualw, int nextw);
char    **handle_quote(char **cmds);
char	**handle_dollard(char **cmds);
int		ft_isspace(char c);
int		long_doll(char *str);
char	*ft_resize(char *str, char **env);
char	*ft_insert(char *src, char *app, int start, int size);
char	*ft_replace_var(char *str, char **env);
char	**ft_parkour(char **cmd, char **env);

#endif