/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orauline <orauline@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:06:37 by orauline          #+#    #+#             */
/*   Updated: 2023/12/01 18:52:32 by orauline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	add_to_env(char *cmd, t_env *env)
{
	int		len;
	int		i;
	char	**updated_env;

	i = -1;
	len = 0;
	while (env->env_cpy[len++])
		;
	updated_env = malloc(sizeof(char *) * (len + 1));
	if (!updated_env)
		return ;
	updated_env[len] = ft_strdup(cmd);
	updated_env[len + 1] = NULL;
	while (env->env_cpy[++i])
		updated_env[i] = ft_strdup(env->env_cpy[i]);
	free(env->env_cpy);
	env->env_cpy = updated_env;
}

static int	is_valid_identifier(char *str)
{
	while (*str)
	{
		if (!((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z')
				|| *str == '_'))
			return (0);
		str++;
	}
	return (1);
}

static void	process_key(char *key, t_env *env)
{
	char	*equal;

	equal = ft_strchr(key, '=');
	if (!equal)
	{
		equal = "=''";
		key = ft_strncat(ft_strdup(key), equal, ft_strlen(equal));
		add_to_env(key, env);
		free(key);
	}
	else
	{
		*equal = '\0';
		add_to_env(key, env);
		*equal = '=';
	}
}

static void	update_env(char *cmd, t_env *env)
{
	int		i;
	char	*key;

	if (!is_valid_identifier(cmd))
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
	if (!cmds[1])
	{
		while (env->env_cpy[j])
			printf("env[%d] = %s\n", j++, env->env_cpy[j]);
	}
	else
	{
		while (cmds[++j])
			update_env(cmds[j], env);
	}
	return (0);
}
