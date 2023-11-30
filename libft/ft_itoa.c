/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouvrar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:06:18 by maouvrar          #+#    #+#             */
/*   Updated: 2023/02/10 08:37:09 by maouvrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	size_numb(int n)
{
	int	size;

	size = 1;
	if (n < 0)
	{
		size++;
		n = -n;
	}
	while (n >= 10)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*c;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = size_numb(n);
	c = malloc(sizeof(char) * (size + 1));
	if (!c)
		return (NULL);
	c[size] = 0;
	if (n < 0)
	{
		c[0] = '-';
		n = -n;
	}
	while (n >= 10)
	{
		c[size - 1] = n % 10 + 48;
		n = n / 10;
		size--;
	}
	if (n >= 0)
		c[size - 1] = n + 48;
	return (c);
}
