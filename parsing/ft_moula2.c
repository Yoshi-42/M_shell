/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moula2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonon <bgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:35:28 by bgonon            #+#    #+#             */
/*   Updated: 2023/12/03 19:36:39 by bgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	long_doll(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\"')
	{
		i++;
		if (str[i] == '$')
			return (i);
		if (ft_isspace(str[i]) == 1)
			return (i);
	}
	return (i);
}

char	*ft_resize(char *str, char **env)
{
	char	*buff;
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], str, ft_strlen(str)) == 0
			&& (env[i][ft_strlen(str)] == '='))
		{
			buff = ft_substr(env[i], ft_strlen(str) + 1, ft_strlen(env[i]));
			return (buff);
		}
		else
			i++;
	}
	return ("");
}
