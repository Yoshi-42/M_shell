/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moula.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonon <bgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:23:35 by artmarti          #+#    #+#             */
/*   Updated: 2023/12/03 19:37:04 by bgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_insert(char *src, char *app, int start, int size)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	dest = malloc(sizeof(char) * ((ft_strlen(src) + ft_strlen(app)) - (size)));
	while (i < start)
	{
		dest[i] = src[i];
		i++;
	}
	while (app[j])
	{
		dest[i] = app[j];
		i++;
		j++;
	}
	while (src[i - j + size + 1])
	{
		dest[i] = src[i - j + size + 1];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_replace_var(char *str, char **env, int i)
{
	int		size;
	char	*buff;
	char	*dest;
	char	*var;

	size = 0;
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1] != '?')
		{
			size = long_doll(&str[i + 1]);
			var = ft_substr(str, i + 1, size);
			buff = ft_resize(var, env);
			dest = ft_insert(str, buff, i, ft_strlen(var));
			str = ft_strdup(dest);
			i = 0;
			continue ;
		}
		i++;
	}
	free(var);
	free(buff);
	free(dest);
	return (str);
}

char	*ft_var_int(char *str, int err, int i, int j)
{
	char	*dest;
	char	*buff;
	int		size;

	size = -1;
	buff = ft_itoa(err);
	dest = malloc(sizeof(char) * (ft_strlen(buff) + ft_strlen(str) - 1));
	while (str[i + j])
	{
		if (str[i] == '$' && str[i + 1] == '?')
		{
			j = 0;
			while (buff[++size] != '\0')
				dest[i + size] = buff[size];
			j = j + 2;
		}
		dest[i + size] = str[i + j];
		i++;
	}
	dest[i + size] = '\0';
	free(buff);
	str = ft_strdup(dest);
	free(dest);
	return (str);
}

int	ft_search(char *str)
{
	int	i;

	i = 0;
	while (str[i + 1])
	{
		if (str[i] == '$' && str[i + 1] == '?')
			return (1);
		else
			i++;
	}
	return (0);
}

char	**ft_parkour(char **cmd, char **env, int err)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (ft_search(cmd[i]) && cmd[i][0] != '\'')
		{
			cmd[i] = ft_var_int(cmd[i], err, 0, 0);
		}
		if (ft_strchr(cmd[i], '$') && cmd[i][0] != '\'')
			cmd[i] = ft_replace_var(cmd[i], env, 0);
		i++;
	}
	return (cmd);
}
