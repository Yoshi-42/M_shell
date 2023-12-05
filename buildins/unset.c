/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuberbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:07:42 by orauline          #+#    #+#             */
/*   Updated: 2023/12/05 19:08:43 by esuberbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
1. Verifier si la variable d'environnement existe
2. Ne rien faire si la variable d'environnement existe
3. Copier toutes les variables d'environnement sauf celle a supprimer
4. Allouer de la memoire pour la nouvelle table d'environnement
5. Copier les variables d'environnement dans la nouvelle table
6. Mettre a jour l'environnement en effacant l'environnement actuel et
en mettamt a jour la table
*/

static int	check_digit(char *str, t_env *env)
{
	if (ft_isdigit(str[0]) != 0)
	{
		env->flag_arg_error++;
		if (env->flag_arg_error == 1)
		{
			printf("unset: %s: invalid parameter name\n", str);
			return (1);
		}
	}
	return (0);
}

static void	remove_env_var(char *key, t_env *env)
{
	int	i;

	i = -1;
	while (env->env_cpy[++i])
	{
		if (ft_strcmp(key, env->env_cpy[i]) == 0)
		{
			free(env->env_cpy[i]);
			while (env->env_cpy[i + 1])
			{
				env->env_cpy[i] = env->env_cpy[i + 1];
				i++;
			}
			env->env_cpy[i] = NULL;
			return ;
		}
	}
}

static int	err_not_enough_args(void)
{
	printf("unset: not enough arguments\n");
	return (1);
}

// static int	err_invalid_params(char *cmds)
// {
// 	printf("unset: %s: invalid parameter name\n", cmds);
// 	return (1);
// }

int	m_unset(char **cmds, t_env *env)
{
	int	j;
	int	i;

	env->flag_arg_error = 0;
	if (!cmds[1])
		err_not_enough_args();
	j = 1;
	while (cmds[j])
	{
		check_digit(cmds[j], env);
		env->key = ft_strdup(cmds[j]);
		if (ft_strchr(env->key, '='))
		{
			i = -1;
			while (env->key[++i] != '=')
				;
			if (ft_strlen(env->key) + 1 == i)
				return (1);
			env->key[i] = '\0';
		}
		remove_env_var(env->key, env);
		j++;
	}
	return (1);
}
