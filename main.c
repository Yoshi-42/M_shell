/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:41:45 by artmarti          #+#    #+#             */
/*   Updated: 2023/12/01 13:41:46 by artmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

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
}	t_command;*/

int	m_exe(t_command cmd) //(char **cmd, char **envp)
{
	 pid_t	child_pid;
	 int	status;
	 //cmd.cmd = format(cmd.cmd);
	 child_pid = fork();
	if (child_pid == -1)
	{
		perror("Erreur de processus");
		return (-1);
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		execve(cmd.cmd[0], cmd.cmd, cmd.env.env_cpy);
		perror("Erreur d'exécution");
		exit(EXIT_FAILURE);
		return (-1);
	}
	else
	{
		waitpid(child_pid, &status, 0);
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		{
			printf("La commande FAILED end %d\n", WEXITSTATUS(status));
		}
	}
	return (0);
}

int	main(int argc, char ** argv, char **envp)
{	
	char		*cmd;
	char		**cmds;
//	t_command	f_cmd;

	(void)argc;
	(void)argv;
	(void)envp;
	while(1)
	{
		cmd = readline("m_shell$> ");
		cmds = parsing(cmd);
		if (cmds == NULL)
			return (0);
		//on split en tableau " " ' ' / Puis on gere les $ / split en list chainne pour les pipes
		//
		handle_history(cmd);
	}
	return (0);
}
