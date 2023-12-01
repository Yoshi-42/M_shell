/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 01:20:16 by artmarti          #+#    #+#             */
/*   Updated: 2023/11/30 01:20:18 by artmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// Fonction a remplacer par le ft_strlcpy de la libft pour respecter la norme 
// + remplacer strlen par ft_strlen
int	ft_strlcpy2(char *dst, char *src, int size)
{
	int	i;
	int	length;

	i = 0;
	length = ft_strlen(src);
	if (!dst || !src)
		return (0);
	if (size == 0)
		return (length);
	while ((src[i] != '\0') && (i < size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	if ((dst[0] == '\'' || dst[0] == '\"') && dst[1] == '\0')
		dst[0] = '\0';
	return (length);
}

int	ft_actualword(char *s, char c, int a)
{
	int	i;

	i = a;
	while (s[i] && s[i] == c)
		i++;
	return (i);
}

int	ft_nextword(char *s, char c, int a)
{
	int	i;
	int	b;

	i = a;
	b = 1;
	if (c == '\'' || c == '\"')
	{
		b = 2;
		i = a + 1;
	}
	while (s[i] && s[i] != c)
		i++;
	return (i + b);
}

int	ft_wordcount(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			if (s[i] == '\"')
				while (s[++i] != '\"')
					i = i;
			else if (s[i] == '\'')
				while (s[++i] != '\'')
					i = i;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

char	**split(char *s, char c, int actualw, int nextw)
{
	char	**cmds;
	int		cnt;
	int		j;

	j = 0;
	cnt = ft_wordcount(s, c);
	cmds = (char **)malloc(sizeof(char *) * (cnt + 1));
	while (j < cnt)
	{
		actualw = ft_actualword(s, c, nextw);
		if (s[actualw] == '\"')
			nextw = ft_nextword(s, '\"', actualw);
		else if (s[actualw] == '\'')
			nextw = ft_nextword(s, '\'', actualw);
		else
			nextw = ft_nextword(s, c, actualw);
		cmds[j] = malloc(sizeof(char) * ((nextw) - actualw));
		ft_strlcpy2(cmds[j], s + actualw, ((nextw) - actualw));
		j++;
	}
	cmds[j] = NULL;
	return (cmds);
}
