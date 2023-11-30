/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orauline <orauline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:04:27 by artmarti          #+#    #+#             */
/*   Updated: 2023/11/21 17:25:37 by orauline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	m_exe_buildin(char **cmds, char **envp)
{
	if (ft_strcmp(cmds[0], "echo") == 0)
		m_echo_n(cmds);
	else if (ft_strcmp(cmds[0], "cd") == 0)
		m_cd(cmds);
	else if (ft_strcmp(cmds[0], "pwd") == 0)
		m_pwd();
	else if (ft_strcmp(cmds[0], "export") == 0)
		m_export(cmds, env);
	else if (ft_strcmp(cmds[0], "unset") == 0)
		m_unset(cmds, env);
	else if (ft_strcmp(cmds[0], "env") == 0)
		m_env(envp);
	else if (ft_strncmp(cmds[0], "exit", 5) == 0)
		return (1);
	else
		return ;
}
