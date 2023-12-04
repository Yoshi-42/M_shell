/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orauline <orauline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:06:37 by orauline          #+#    #+#             */
/*   Updated: 2023/12/04 15:28:30 by orauline         ###   ########.fr       */
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
	printf("cmd afeter updted env = %s\n", cmd);
	printf("updated env strdup = %s\n", updated_env[len]);
	updated_env[len + 1] = NULL;
	while (env->env_cpy[++i])
	{
		updated_env[i] = ft_strdup(env->env_cpy[i]);
		free(env->env_cpy[i]);
	}
	free(env->env_cpy);
	env->env_cpy = updated_env;
	printf("envcpy = %s\n", env->env_cpy[i]);
}

static void	process_key(char *key, t_env *env)
{
	char	*equal;
	char	*new_key;
	char	*temp;
	char	*equal_not_found;

	equal = ft_strchr(key, '=');
	printf("equal = %s\n", equal);
	if (!equal)
	{
		equal_not_found = "=''";
		new_key = ft_strncat(key, equal_not_found, ft_strlen(equal_not_found));
		printf("new_key after concat= %s\n", new_key);
		add_to_env(new_key, env);
		printf("new_key after add to env= %s\n", new_key);
		// free(new_key);
	}
	else
	{
		temp = ft_strdup(key);
		// *equal = '\0';
		add_to_env(temp, env);
		// *equal = '=';
		// free(temp);
	}
}

// static char *find_key(char *cmd)
// {
// 	char *key;
// 	int i;
// 	int j;

// 	i= -1;
// 	j = -1;
// 	key = ft_strdup(cmd);
// 	if (cmd[++i] != '=')
// 	{
// 		key[j] = cmd[i];
// 		key[j + 1] = '\0';
// 	}
// 	return (key);
// 	printf("find key value is ; key = %s\n", key);
// }

static void	update_env(char *cmd, t_env *env)
{
	int		i;
	char	*key;

	if (ft_isdigit(cmd[0]) != 0)
	{
		printf("export: not an identifier: %s\n", cmd);
		return ;
	}
	i = -1;
	key = find_key(cmd);
	printf("key value strdup cmd is: %s\n", key);
	process_key(key, env);
	printf("key value after process key is: %s\n", key);
	while (env->env_cpy[++i])
	{
		if (ft_strcmp(key, env->env_cpy[i]) == 0)
		{
			printf("key afeter strcmp= %s\n", key);
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
			printf("%s\n", env->env_cpy[j]);
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
