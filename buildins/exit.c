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

void	m_exit(char **cmds, char **envp)
{
	(void)cmds;
	(void)envp;
	//ft_free_all();
	exit(0);
}