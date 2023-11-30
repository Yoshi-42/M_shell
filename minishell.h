

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>



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

// Fonctions des buildins
void	m_exe_buildin(char **cmds, char **envp);
int	m_export(char **cmds, t_env *env);
void	m_cd(char **cmds);
void	m_echo_n(char **cmd);
char	*ft_strncat(char *dest, char *src, unsigned int nb);
void	m_env(char **envp);
int	check_digit(char *str);
int	count_args(char **str);
char	**envp_cpy(char **envp);
void m_pwd(void);
int m_unset(char **cmds, t_env *env);