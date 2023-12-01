/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouvrar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 08:10:44 by maouvrar          #+#    #+#             */
/*   Updated: 2023/02/10 08:33:30 by maouvrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		size1;
	int		size2;
	char	*s3;

	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	s3 = malloc(sizeof(char) * (size1 + size2 + 1));
	if (!s3)
		return (0);
	i = 0;
	while (i < size1)
	{
		s3[i] = s1[i];
		i++;
	}
	while (i < size1 + size2)
	{
		s3[i] = s2[i - size1];
		i++;
	}
	s3[i] = 0;
	return (s3);
}
