/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouvrar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 08:31:56 by maouvrar          #+#    #+#             */
/*   Updated: 2023/02/03 12:32:11 by maouvrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	j;

	if ((size_t) dest - (size_t) src >= n)
		ft_memcpy(dest, src, n);
	else
	{
		j = n - 1;
		while (j > 0)
		{
			*(char *)(dest + j) = *(char *)(src + j);
			j--;
		}
		*(char *)(dest + j) = *(char *)(src + j);
	}
	return (dest);
}
