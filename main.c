/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonon <bgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:41:45 by artmarti          #+#    #+#             */
/*   Updated: 2023/12/03 15:45:55 by bgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int	m_exe(t_command cmd) //(char **cmd, char **envp)
// {
// 	 pid_t	child_pid;
// 	 int	status;
// 	 //cmd.cmd = format(cmd.cmd);
// 	 child_pid = fork();
// 	if (child_pid == -1)
// 	{
// 		perror("Erreur de processus");
// 		return (-1);
// 		exit(EXIT_FAILURE);
// 	}
// 	else if (child_pid == 0)
// 	{
// 		execve(cmd.cmd[0], cmd.cmd, cmd.env.env_cpy);
// 		perror("Erreur d'exécution");
// 		exit(EXIT_FAILURE);
// 		return (-1);
// 	}
// 	else
// 	{
// 		waitpid(child_pid, &status, 0);
// 		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
// 		{
// 			printf("La commande FAILED end %d\n", WEXITSTATUS(status));
// 		}
// 	}
// 	return (0);
// }

int	get_status(t_command *cmd)
{
	int	i;

	i = 0;
	while (cmd[i].cmd != NULL)
		i++;
	return (cmd[i - 1].status);
}

int	main(int argc, char **argv, char **envp)
{	
	char		*cmd;
	char		**cmds;
	t_command	*pipe_cmd;
	t_env		env;
	int			err;

	(void)argc;
	(void)argv;
	signal(SIGINT, ft_ctrlc);
	signal(SIGQUIT, ft_ctrlslash);
	env.env_cpy = envp_cpy(envp);
	err = 0;
	while (1)
	{
		cmd = readline("m_shell$> ");
		if (cmd == NULL)
			break ;
		cmds = parsing(cmd, env.env_cpy, err);
		if (cmds == NULL)
			return (0);
		handle_history(cmd);
		err = 0;
		if (m_exe_buildin(cmds, &env) != 0)
			continue ;
		pipe_cmd = ft_create_nodes(cmds, env.env_cpy);
		fake_tree(pipe_cmd);
		err = get_status(pipe_cmd);
		ft_free_command(&pipe_cmd);
		ft_freetabs(cmds);
		free(cmd);
	}
	printf("Fin du programme\n");
	if (cmd)
		free(cmd);
	ft_freetabs(env.env_cpy);
	clear_history();
	return (0);
}
