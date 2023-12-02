/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:00:05 by artmarti          #+#    #+#             */
/*   Updated: 2023/12/01 15:00:05 by artmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	m_exit(char **cmds, char **envp)
{
	(void)cmds;
	(void)envp;
	ft_freetabs(cmds);
	ft_freetabs(envp);
	rl_clear_history();
	exit(0);
	return (1);
}
