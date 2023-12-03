/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_exe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:34:47 by bgonon            #+#    #+#             */
/*   Updated: 2023/12/03 19:34:48 by bgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*is_bin(char *cmd)
{
	if (ft_strnstr(cmd, "/bin/", 5))
		return (cmd);
	else
		return (ft_strjoin("/bin/", cmd));
}

int	exe_error(int flag)
{
	if (flag == 0)
		perror("Erreur de processus");
	else
		perror("Erreur d'exécution");
	exit(EXIT_FAILURE);
	return (-1);
}

int	m_exe(t_command *cmd)
{
	pid_t	child_pid;
	int		status;
	char	*file;

	cmd->status = 0;
	child_pid = fork();
	if (child_pid == -1)
		return (exe_error(0));
	else if (child_pid == 0)
	{
		file = is_bin(cmd->cmd[0]);
		execve(file, cmd->cmd, cmd->env.env_cpy);
		return (exe_error(1));
	}
	else
	{
		waitpid(child_pid, &status, 0);
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		{
			cmd->status = 127;
			printf("La commande FAILED end %d\n", WEXITSTATUS(status));
		}
	}
	return (0);
}

void	exe_node(t_command *cmd, int in, int out, int *flag)
{
	int	origin_fd;
	int	ori_fd_in;

	origin_fd = dup(STDOUT_FILENO);
	ori_fd_in = dup(STDIN_FILENO);
	if (in > 0)
		dup2(in, 0);
	if (out > 0)
		dup2(out, 1);
	m_exe(cmd);
	dup2(origin_fd, 1);
	dup2(ori_fd_in, 0);
	*flag = *flag + 1;
}
