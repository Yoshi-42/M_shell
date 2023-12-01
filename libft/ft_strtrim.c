/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouvrar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 08:21:39 by maouvrar          #+#    #+#             */
/*   Updated: 2023/02/10 08:35:29 by maouvrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static int	is_contain(char c, const char *check)
{
	int	i;

	i = 0;
	while (check[i] != 0)
	{
		if (c == check[i])
			return (0);
		i++;
	}
	return (1);
}

static int	lentrim(const char *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	while (is_contain(s1[i], set) == 0)
		i++;
	j = 0;
	while (is_contain(s1[ft_strlen(s1)- j - 1], set) == 0)
		j++;
	if (i + j >= (int)ft_strlen(s1))
		return (0);
	return (ft_strlen(s1) - i - j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (is_contain(s1[i], set) == 0)
		i++;
	return (ft_substr(s1, i, lentrim(s1, set)));
}
