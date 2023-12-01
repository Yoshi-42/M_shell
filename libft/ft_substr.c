/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouvrar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 08:02:52 by maouvrar          #+#    #+#             */
/*   Updated: 2023/02/10 08:32:25 by maouvrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ns;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	ns = malloc(sizeof(char) * (len + 1));
	if (!ns)
		return (0);
	i = 0;
	while (start + i < start + len && s[start + i] != 0)
	{
		ns[i] = s[start + i];
		i++;
	}
	ns[i] = '\0';
	return (ns);
}
