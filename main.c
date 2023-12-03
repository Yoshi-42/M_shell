/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonon <bgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:41:45 by artmarti          #+#    #+#             */
/*   Updated: 2023/12/03 19:59:10 by bgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_status(t_command *cmd)
{
	int	i;

	i = 0;
	while (cmd[i].cmd != NULL)
		i++;
	return (cmd[i - 1].status);
}

void	free_free(char **cmds, char *cmd, t_command *pipe_cmd)
{
	ft_free_command(&pipe_cmd);
	ft_freetabs(cmds);
	free(cmd);
}

char	**signal_signal(char **envp, int *err)
{
	signal(SIGINT, ft_ctrlc);
	signal(SIGQUIT, ft_ctrlslash);
	*err = 0;
	return (envp_cpy(envp));
}

int	end(char **env)
{
	ft_freetabs(env);
	rl_clear_history();
	return (0);
}

int	main(int argc, char **argv, char **envp)
{	
	char		*cmd;
	char		**cmds;
	t_command	*pipe_cmd;
	t_env		env;
	int			err;

	env.env_cpy = signal_signal(envp, &err);
	while (1 && argv && argc)
	{
		cmd = readline("m_shell$> ");
		if (cmd == NULL)
			break ;
		cmds = parsing(cmd, env.env_cpy, err);
		if (cmds == NULL)
			return (0);
		handle_history(cmd);
		if (m_exe_buildin(cmds, &env) != 0)
			continue ;
		pipe_cmd = ft_create_nodes(cmds, env.env_cpy);
		fake_tree(pipe_cmd);
		err = get_status(pipe_cmd);
		free_free(cmds, cmd, pipe_cmd);
	}
	return (end(env.env_cpy));
}
