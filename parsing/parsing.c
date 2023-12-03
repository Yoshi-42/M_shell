/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonon <bgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 00:49:31 by artmarti          #+#    #+#             */
/*   Updated: 2023/12/03 15:11:29 by bgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**parsing(char *cmd, char **env, int err)
{
	char	**cmds;

	cmds = split(cmd, ' ', 0, 0);
	cmds = ft_parkour(cmds, env, err);
	cmds = handle_quote(cmds);
	return (cmds);
}
