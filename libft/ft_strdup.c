/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouvrar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 07:57:47 by maouvrar          #+#    #+#             */
/*   Updated: 2023/02/10 08:31:18 by maouvrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(char *s)
{
	char	*ns;
	int		i;

	ns = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!ns)
		return (0);
	i = 0;
	while (s[i] != 0)
	{
		ns[i] = s[i];
		i++;
	}
	ns[i] = 0;
	return (ns);
}
