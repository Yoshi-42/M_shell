/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orauline <orauline@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:06:37 by orauline          #+#    #+#             */
/*   Updated: 2023/12/02 16:23:55 by orauline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	add_to_env(char *cmd, t_env *env)
{
	int		len;
	int		i;
	char	**updated_env;

	i = -1;
	len = -1;
	while (env->env_cpy[++len])
		;
	updated_env = malloc(sizeof(char *) * (len + 2));
	if (!updated_env)
	{
		free(updated_env);
		return ;
	}
	updated_env[len] = ft_strdup(cmd);
	updated_env[len + 1] = NULL;
	while (env->env_cpy[++i])
	{
		updated_env[i] = ft_strdup(env->env_cpy[i]);
		free(env->env_cpy[i]);
	}
	free(env->env_cpy);
	env->env_cpy = updated_env;
}

static void	process_key(char *key, t_env *env)
{
	char	*equal;
	char	*new_key;
	char	*temp;
	char	*equal_not_found;

	equal = ft_strchr(key, '=');
	if (!equal)
	{
		equal_not_found = "=''";
		new_key = ft_strncat(ft_strdup(key), equal_not_found, ft_strlen(equal_not_found));
		add_to_env(new_key, env);
		free(new_key);
	}
	else
	{
		temp = ft_strdup(key);
		*equal = '\0';
		add_to_env(temp, env);
		*equal = '=';
		free(temp);
	}
}

static void	update_env(char *cmd, t_env *env)
{
	int		i;
	char	*key;

	if (!cmd || check_digit(cmd))
	{
		printf("export: not an identifier: %s\n", cmd);
		return ;
	}
	i = -1;
	key = ft_strdup(cmd);
	process_key(key, env);
	while (env->env_cpy[++i])
	{
		if (ft_strcmp(key, env->env_cpy[i]) == 0)
		{
			free(env->env_cpy[i]);
			env->env_cpy[i] = ft_strdup(cmd);
			free(key);
			return ;
		}
	}
	free(key);
	add_to_env(cmd, env);
}

int	m_export(char **cmds, t_env *env)
{
	int	j;

	j = 0;
	if (!cmds)
		return (0);
	if (!cmds[1])
	{
		while (env->env_cpy[j])
		{
			printf("env[%d] = %s\n", j, env->env_cpy[j]);
			j++;
		}
	}
	else
	{
		j = 0;
		while (cmds[++j])
			update_env(cmds[j], env);
	}
	return (1);
}
