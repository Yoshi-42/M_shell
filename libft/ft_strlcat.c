/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouvrar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:50:40 by maouvrar          #+#    #+#             */
/*   Updated: 2023/02/10 08:20:58 by maouvrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	lend;

	j = 0;
	lend = ft_strlen(dest);
	if (size <= 0)
		return (ft_strlen(src));
	i = ft_strlen(dest);
	while (src[j] != '\0' && i < size - 1)
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	if (lend < size)
		dest[i] = 0;
	if (i >= size)
		return (size + ft_strlen(src));
	else
		return (lend + ft_strlen(src));
}
