/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouvrar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 08:44:47 by maouvrar          #+#    #+#             */
/*   Updated: 2023/02/10 08:36:13 by maouvrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	count_str(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != 0)
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
			if (s[i])
				count++;
		}
		i++;
	}
	count++;
	return (count);
}

static void	str_plited(const char *s, char **tab, char c, int size)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (k < size)
	{
		while (s[i] && s[i] == c)
			i++;
		j = i;
		while (s[j] && s[j] != c)
			j++;
		tab[k] = ft_substr(s, i, j - i);
		i = j;
		k++;
	}
	tab[k] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	if (*s == '\0')
	{
		tab = malloc(sizeof(char **) * 1);
		tab[0] = malloc(sizeof(char *) * 1);
		tab[0] = NULL;
		return (tab);
	}
	tab = malloc(sizeof(char *) * (count_str(s, c) + 1));
	if (!tab)
	{
		return (NULL);
	}
	str_plited(s, tab, c, count_str(s, c));
	return (tab);
}
