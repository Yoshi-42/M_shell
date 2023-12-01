/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouvrar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:25:20 by maouvrar          #+#    #+#             */
/*   Updated: 2023/02/10 08:26:19 by maouvrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && *(unsigned char *)s != (unsigned char)c)
	{
		s++;
		i++;
	}
	if (i == n)
		return (NULL);
	return ((char *)s);
}
