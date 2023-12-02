/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:41:36 by artmarti          #+#    #+#             */
/*   Updated: 2023/12/01 20:41:37 by artmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	m_exe(t_command cmd)
{
	pid_t	child_pid;
	int		status;
	char	*file;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Erreur de processus");
		return (-1);
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		file = ft_strjoin("/bin/", cmd.cmd[0]);
		execve(file, cmd.cmd, cmd.env.env_cpy);
		perror("Erreur d'exécution");
		exit(EXIT_FAILURE);
		return (-1);
	}
	else
	{
		waitpid(child_pid, &status, 0);
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
			printf("La commande FAILED end %d\n", WEXITSTATUS(status));
	}
	return (0);
}

void	exe_node(t_command cmd, int in, int out)
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
}

int	all_nodes_no_enter(t_command cmd, t_command cmd_exe, int p_i, int p_o)
{
	int	i;
	int	fd_out;
	int	flag;

	i = 0;
	flag = 0;
	if (p_o != -1)
	{
		exe_node(cmd_exe, p_i, p_o);
		flag++;
	}
	while (cmd.cmd[i] != NULL)
	{
		if (verfi_word(cmd.cmd[i], ">") || verfi_word(cmd.cmd[i], ">>"))
		{
			if (cmd.cmd[i + 1] == NULL)
				return (-1);
			if (verfi_word(cmd.cmd[i], ">"))
				fd_out = open(cmd.cmd[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
			else
				fd_out = open(cmd.cmd[i + 1], O_WRONLY | O_CREAT | O_APPEND, 0666);
			if (fd_out == -1)
				perror("ERREUR DE FICHIER");
			exe_node(cmd_exe, p_i, fd_out);
			flag++;
			close (fd_out);
		}
		i++;
	}
	if (flag == 0)
		exe_node(cmd_exe, p_i, 1);
	return (0);
}

int	all_nodes(t_command cmd, t_command cmd_exe, int p_i, int p_o)
{
	int	i;
	int	fd_in;
	int	flag;

	i = 0;
	flag = 0;
	if (p_i != -1)
	{
		all_nodes_no_enter(cmd, cmd_exe, p_i, p_o);
		flag++;
	}
	while (cmd.cmd[i] != NULL)
	{
		if (verfi_word(cmd.cmd[i], "<") || verfi_word(cmd.cmd[i], "<<"))
		{
			if (cmd.cmd[i + 1] == NULL)
				return (-1);
			if (verfi_word(cmd.cmd[i], "<"))
				fd_in = open(cmd.cmd[i + 1], O_RDONLY | O_CREAT, 0666);
			else
				fd_in = heredoc(cmd.cmd[i + 1]);
			if (fd_in == -1)
				perror("ERREUR DE FICHIER");
			all_nodes_no_enter(cmd, cmd_exe, fd_in, p_o);
			flag++;
			close (fd_in);
		}
		i++;
	}
	if (flag == 0)
		all_nodes_no_enter(cmd, cmd_exe, -1, p_o);
	return (0);
}

int	redirect(t_command cmd, int p_i, int p_o)
{
	t_command	*cmd_exe;

	cmd_exe = format_exe(cmd);
	//return (all_nodes(cmd, *cmd_exe, p_i, p_o));
	all_nodes(cmd, *cmd_exe, p_i, p_o);
	//free(cmd_exe);
	ft_free_command(cmd_exe);
	return (0);
}
