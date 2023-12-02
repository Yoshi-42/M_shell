/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orauline <orauline@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 21:03:58 by artmarti          #+#    #+#             */
/*   Updated: 2023/12/02 15:09:52 by orauline         ###   ########.fr       */
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

int	count_args(char **str)
{
	int		count;

	count = 0;
	if (str == NULL)
		return (0);
	while (str[count] != NULL)
	{
		count++;
	}
	return (count);
}

int	check_digit(char *str)
{
	if (str[0] && ft_isdigit(str[0]))
		return (1);
	return (0);
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
