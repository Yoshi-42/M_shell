/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 00:49:31 by artmarti          #+#    #+#             */
/*   Updated: 2023/11/30 00:49:32 by artmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**parsing(char *cmd, char **env)
{
	char	**cmds;

	cmds = split(cmd, ' ', 0, 0);
	cmds = ft_parkour(cmds, env);
	cmds = handle_quote(cmds);
	return (cmds);
}
