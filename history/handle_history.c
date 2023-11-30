/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:41:10 by artmarti          #+#    #+#             */
/*   Updated: 2023/11/03 09:41:58 by artmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strncpy_mdfy(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s2[i] != '\0' && i < n)
	{
		s1[i] = s2[i];
		++i;
	}
	while (i < n)
	{
		s1[i] = '\0';
		i++;
	}
	return (s1);
}

char	**change_order(char **history, char *cmd)
{
	int	i;

	i = 0;
	while (i < 99)
	{
		history[i] = history[i + 1];
		i++;
	}
	history[i] = malloc(sizeof(char) * (ft_strlen(cmd) + 1));
	history[i] = ft_strncpy_mdfy(history[i], cmd, (ft_strlen(cmd) + 1));
	return (history);
}

int	ft_check_empty(char *str, char c)
{
	size_t	i;
	size_t	a;

	i = 0;
	a = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			a++;
		i++;
	}
	if (a == i)
		return (1);
	else
		return (0);
}

void	add_history_bis(char *cmd, char **cmd_hist)
{
	static size_t	i = 0;
	size_t			y;

	y = i;
	if (i < 100)
	{
		cmd_hist[y] = malloc(sizeof(char) * (ft_strlen(cmd) + 1));
		cmd_hist[y] = ft_strncpy_mdfy(cmd_hist[y], cmd, (ft_strlen(cmd) + 1));
		y++;
	}
	else if (i >= 100)
	{
		cmd_hist = change_order(cmd_hist, cmd);
	}
	i = y;
}

void	handle_history(char *cmd)
{
	static char	*cmd_hist[100];

	if (cmd == NULL || ft_check_empty(cmd, ' ') == 1)
		return ;
	add_history(cmd);
	add_history_bis(cmd, cmd_hist);
}
