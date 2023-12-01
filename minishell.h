

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>



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