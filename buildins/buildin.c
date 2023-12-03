/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonon <bgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:04:27 by artmarti          #+#    #+#             */
/*   Updated: 2023/12/03 15:23:28 by bgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (s1 == NULL)
		return (-1);
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int	m_exe_buildin(char **cmds, t_env *env)
{
	if (ft_strcmp(cmds[0], "echo") && ft_strcmp(cmds[1], "-n") == 0)
		return (m_echo_n(cmds));
	else if (ft_strcmp(cmds[0], "cd") == 0)
		return (m_cd(cmds));
	else if (ft_strcmp(cmds[0], "pwd") == 0)
		return (m_pwd());
	else if (ft_strcmp(cmds[0], "env") == 0)
		return (m_env(env->env_cpy));
	else if (ft_strcmp(cmds[0], "export") == 0)
		return (m_export(cmds, env));
	else if (ft_strcmp(cmds[0], "unset") == 0)
		return (m_unset(cmds, env));
	else if (ft_strcmp(cmds[0], "exit") == 0)
		return (m_exit(cmds, env->env_cpy));
	else
		return (0);
}

	// else if (ft_strcmp(cmds[0], "export") == 0)
	// 	m_export(cmds, envp); //c'etait env pas envp
	// else if (ft_strcmp(cmds[0], "unset") == 0)
	// 	m_unset(cmds, envp); //la meme