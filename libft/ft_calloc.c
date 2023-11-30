/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouvrar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 07:54:09 by maouvrar          #+#    #+#             */
/*   Updated: 2023/02/10 08:30:20 by maouvrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t mem, size_t size)
{
	void	*tab;

	if (size == 0 || mem == 0)
		return (malloc(0));
	if (mem * size > 2147483648)
		return (NULL);
	tab = malloc(mem * size);
	if (!tab)
		return (NULL);
	ft_bzero(tab, mem * size);
	return (tab);
}
