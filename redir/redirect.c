/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonon <bgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:41:36 by artmarti          #+#    #+#             */
/*   Updated: 2023/12/03 19:28:11 by bgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	open_out(char *file, char *redirect)
{
	if (file == NULL)
		return (-1);
	if (verfi_word(redirect, ">"))
		return (open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777));
	else
		return (open(file, O_WRONLY | O_CREAT | O_APPEND, 0777));
}

int	all_nodes_no_enter(t_command *cmd, t_command *cmd_exe, int p_i, int p_o)
{
	int	i;
	int	fd_out;
	int	flag;

	i = 0;
	flag = 0;
	if (p_o != -1)
		exe_node(cmd_exe, p_i, p_o, &flag);
	while (cmd->cmd[i] != NULL)
	{
		if (verfi_word(cmd->cmd[i], ">") || verfi_word(cmd->cmd[i], ">>"))
		{
			fd_out = open_out(cmd->cmd[i + 1], cmd->cmd[i]);
			if (fd_out == -1)
				perror("ERREUR DE FICHIER");
			exe_node(cmd_exe, p_i, fd_out, &flag);
			close (fd_out);
		}
		i++;
	}
	if (flag == 0)
		exe_node(cmd_exe, p_i, 1, &flag);
	return (0);
}

int	open_enter(char *file, char *redirect)
{
	if (file == NULL)
		return (-1);
	if (verfi_word(redirect, "<"))
		return (open(file, O_RDONLY | O_CREAT, 0777));
	else
		return (heredoc(file));
}

int	all_nodes(t_command *cmd, t_command *cmd_exe, int p_i, int p_o)
{
	int	i;
	int	fd_in;
	int	flag;

	i = 0;
	flag = 0;
	if (p_i != -1 && ++flag > -1)
		all_nodes_no_enter(cmd, cmd_exe, p_i, p_o);
	while (cmd->cmd[i] != NULL)
	{
		if (verfi_word(cmd->cmd[i], "<") || verfi_word(cmd->cmd[i], "<<"))
		{
			fd_in = open_enter(cmd->cmd[i + 1], cmd->cmd[i]);
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

int	redirect(t_command *cmd, int p_i, int p_o)
{
	t_command	*cmd_exe;

	cmd_exe = format_exe(cmd);
	all_nodes(cmd, cmd_exe, p_i, p_o);
	cmd->status = cmd_exe->status;
	ft_freetabs(cmd_exe->cmd);
	ft_freetabs(cmd_exe->env.env_cpy);
	free(cmd_exe);
	return (0);
}
