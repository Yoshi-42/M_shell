/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonon <bgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:04:27 by artmarti          #+#    #+#             */
/*   Updated: 2023/11/30 16:44:56 by bgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while(s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			return(s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	m_exe_buildin(char **cmds, char **envp)
{
	if (ft_strcmp(cmds[0], "echo") == 0)
		m_echo_n(cmds);
	else if (ft_strcmp(cmds[0], "cd") == 0)
		m_cd(cmds);
	else if (ft_strcmp(cmds[0], "pwd") == 0)
		m_pwd();
	else if (ft_strcmp(cmds[0], "env") == 0)
		m_env(envp);
	else if (ft_strcmp(cmds[0], "exit") == 0)
		m_exit(cmds, envp);
	else
		return ;
}

	// else if (ft_strcmp(cmds[0], "export") == 0)
	// 	m_export(cmds, envp); //c'etait env pas envp
	// else if (ft_strcmp(cmds[0], "unset") == 0)
	// 	m_unset(cmds, envp); //la meme