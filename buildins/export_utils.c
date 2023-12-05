/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuberbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 21:03:58 by artmarti          #+#    #+#             */
/*   Updated: 2023/12/05 18:34:22 by esuberbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**envp_cpy(char **envp)
{
	char	**env;
	int		len;
	int		i;

	i = -1;
	len = -1;
	while (envp[++len])
		;
	env = malloc(sizeof(char *) * (len + 1));
	if (!env)
		return (NULL);
	env[len] = NULL;
	while (envp[++i])
	{
		env[i] = ft_strdup(envp[i]);
	}
	return (env);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0' && j < nb)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}
