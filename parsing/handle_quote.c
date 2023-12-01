/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 00:46:29 by artmarti          #+#    #+#             */
/*   Updated: 2023/11/30 00:46:30 by artmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*del_quote(char *cmd)
{
	char	*str;
	int		i;

	i = 1;
	str = malloc(sizeof(char) * (ft_strlen(cmd) - 1));
	while (cmd[i + 1] != '\0')
	{
		str[i - 1] = cmd[i];
		i++;
	}
	str[i - 1] = '\0';
	return (str);
}

char	*check_quote(char *cmd)
{
	int		i;
	char	*str;

	i = 0;
	if (cmd[i] == '\'' || cmd[i] == '\"')
	{
		str = del_quote(cmd);
		return (str);
	}
	return (cmd);
}

char	**handle_quote(char **cmds)
{
	int		i;

	i = 0;
	while (cmds[i] != NULL)
	{
		cmds[i] = check_quote(cmds[i]);
		i++;
	}
	return (cmds);
}
