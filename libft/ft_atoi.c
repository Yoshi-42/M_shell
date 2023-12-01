/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouvrar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:51:20 by maouvrar          #+#    #+#             */
/*   Updated: 2023/02/16 10:22:47 by maouvrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	is_whitespace(char c)
{
	if (c == '\t' || c == ' ' || c == '\n')
		return (0);
	if (c == '\v' || c == '\f' || c == '\r')
		return (0);
	return (1);
}

int	ft_atoi(const char *n)
{
	int	i;
	int	sig;
	int	res;

	i = 0;
	res = 0;
	sig = 1;
	while (is_whitespace(n[i]) == 0)
		i++;
	if (n[i] == '-' || n[i] == '+')
	{
		if (n[i] == '-')
			sig = -1;
		i++;
	}
	while (ft_isdigit(n[i]) != 0 && n[i] != 0)
	{
		res = res * 10 + (n[i] - '0');
		i++;
	}
	return (res * sig);
}
