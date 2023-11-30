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

char	**parsing(char *cmd)
{
	char	**cmds;

	cmds = split(cmd, ' ', 0, 0);
	//Rajouter ici la gestion des $ pour eviter les confusions " et '
	cmds = handle_quote(cmds);
	return (cmds);
}
