/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orauline <orauline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:07:42 by orauline          #+#    #+#             */
/*   Updated: 2023/11/21 17:38:38 by orauline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
1. Verifier si la variable d'environnement existe
2. Ne rien faire si la variable d'environnement existe
3. Copier toutes les variables d'environnement sauf celle a supprimer
4. Allouer de la memoire pour la nouvelle table d'environnement
5. Copier les variables d'environnement dans la nouvelle table
6. Mettre a jour l'environnement en effacant l'environnement actuel et en mettamt a jour la table
7. Gerer le cas si la suppression a echoue avec perrror
*/

int m_unset(char **cmds, t_env *env)
{
	int	i;
	int	j;

	i = -1;
	if (!cmds[1])
		printf("unset: not enough arguments\n");
	else
	{
		j = 0;
		while (cmds[++j])
		{
			if (check_digit(cmds[j]))
			{
				printf("unset: %s: invalid parameter name\n", cmds[j]);
				break ;
			}
			env->key = ft_strdup(cmds[j]);
			i = -1;
			if (ft_strchr(env->key, '='))
			{
				while (env->key[++i] != '=')
					;
				if (ft_strlen(env->key) + 1 == i)
					return (1);
				env->key[i] = '\0';
			}
			while (env->env_cpy[++i])
			{
				if (ft_strcmp(env->key, env->env_cpy[i]) == 0)
					free(env->env_cpy[i]);
			}
		}
	}
	return (0);
}
