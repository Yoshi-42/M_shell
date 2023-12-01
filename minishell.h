/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:36:57 by artmarti          #+#    #+#             */
/*   Updated: 2023/12/01 13:37:00 by artmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"

typedef struct s_env
{
	char	**env_cpy;
	char	*key;
	char	*value;
}	t_env;

typedef struct s_command
{
	char	**cmd;
	t_env	env;
}	t_command;

typedef struct s_list
{
	t_command		*cmd;
	struct s_list	*next;
}	t_list;

/*		PARSING		*/
char		**parsing(char *cmd, char **env);
char		**split(char *cmd, char c, int actualw, int nextw);
char		**handle_quote(char **cmds);
char		**handle_dollard(char **cmds);
char		**ft_parkour(char **cmd, char **env);
t_list		*pipe_split(char **cmds, char ***envp);
t_command	*ft_create_nodes(char **cmd, char **env);

/*		HISTORY		*/
void		handle_history(char *cmd);

/*		BUILDINS	*/
void		m_exe_buildin(char **cmds, t_env *env);
int			m_export(char **cmds, t_env *env);
void		m_cd(char **cmds);
void		m_echo_n(char **cmd);
char		*ft_strncat(char *dest, char *src, unsigned int nb);
void		m_env(char **envp);
int			check_digit(char *str);
int			count_args(char **str);
char		**envp_cpy(char **envp);
void		m_pwd(void);
int			m_unset(char **cmds, t_env *env);
int			ft_strcmp(char *s1, char *s2);
void		m_exit(char **cmds, char **envp);
char		**envp_cpy(char **envp);

/*		SIGNAL		*/
void		ft_ctrlc(int sign);
void		ft_ctrlslash(int sign);

/*		DEBUG		*/
void		print_tab(char **tableau);

/*		REDIR		*/
int			all_nodes(t_command cmd, t_command cmd_exe, int p_i, int p_o);
int			heredoc(char *eof);
int			redirect(t_command cmd, int p_i, int p_o);
t_command	*format_exe(t_command cmd);
int			verfi_word(const char *word, const char *verif);

/*		PIPE		*/
int			fake_tree(t_command *l_cmd);

/*		UTILS		*/
int			ft_isspace(char c);

#endif
