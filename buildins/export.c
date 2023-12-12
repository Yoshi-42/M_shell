<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:32:17 by artmarti          #+#    #+#             */
/*   Updated: 2023/12/02 15:32:18 by artmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_place_space(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '=')
			return (i);
		i++;
	}
	return (-1);
}

int	check_exist(char *cmd, t_env *env, int n)
{
	int	i;

	i = 0;
	while (env->env_cpy[i] != NULL)
	{
		if (ft_strncmp(cmd, env->env_cpy[i], n) == 0)
			return (i);
		i++;
	}
	return (-1);
}

int	tabtab_strlen(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
		i++;
	return (i);
}

char	**tabtab_strjoin(char *cmd, char **env)
{
	int		len;
	char	**dest;
	int		i;

	i = 0;
	len = tabtab_strlen(env);
	dest = malloc(sizeof(char *) * (len + 2));
	while (env[i])
	{
		dest[i] = ft_strdup(env[i]);
		i++;
	}
	dest[i] = ft_strdup(cmd);
	dest[i + 1] = NULL;
	return (dest);
=======
#include "../minishell.h"

//vérifie si la clé est deja présente dans env
static int	key_already_in_env(char *arg, t_env *env)
{
	int		i;

	i = -1;
	get_key(arg, env);
	while (env->env_cpy[++i])
	{
		if (ft_strcmp(env->key, env->env_cpy[i]) == 0)
			return (1);
	}
	return (0);
}

// si l element existe
// free element dans env copy 
// remplace par le nouvel element
static void	update_key(char *arg, t_env *env)
{
	int		i;

	i = -1;
	while (env->env_cpy[++i])
	{
		if (ft_strcmp(env->key, env->env_cpy[i]) == 0)
		{
			free(env->env_cpy[i]);
			env->env_cpy[i] = ft_strdup(arg);
		}
	}
}

//ajoute la clé 
// if !check_equal 
//  ajoute l arg + ='' au dernier element de mon tableau de str 
// return 1 si pas de = ou = en fin de str
//sinon 
//  ajouter arg tel qu il est passé en param
static int	add_new_key(char *arg, t_env *env)
{
	if (check_equal(arg))
	{
		env->key = ft_strjoin(env->key, "=''");
		add_to_env(env->key, env);
		return (1);
	}
	else
	{
		add_to_env(arg, env);
		return (0);
	}
}

// check si il y a un digit au char[0]
//si la clé n'existe pas on l ajoute
//sinon si elle existe et qu'il n'y a pas de = on met a jour la cle
static void	update_env(char *arg, t_env *env)
{
	if (!check_errors(arg, env))
	{
		if (!key_already_in_env(arg, env))
		{
			add_new_key(arg, env);
		}
		else if (!check_equal(arg))
		{
			update_key(arg, env);
		}
	}
>>>>>>> export
}

int	m_export(char **cmds, t_env *env)
{
	int	j;

<<<<<<< HEAD
	j = 1;
=======
	j = 0;
	env->flag_arg_error = 0;
	if (!cmds)
		return (0);
>>>>>>> export
	if (!cmds[1])
		m_env(env->env_cpy);
	else
	{
		while (cmds[j])
		{
<<<<<<< HEAD
			if (ft_strchr(cmds[j], '=') != 0 && cmds[j][0] != '=')
			{
				if (check_exist(cmds[j], env, check_place_space(cmds[j])) >= 0)
					env->env_cpy[check_exist(cmds[j], env,
							check_place_space(cmds[j]))] = ft_strdup(cmds[j]);
				else
					env->env_cpy = tabtab_strjoin(cmds[j], env->env_cpy);
			}
=======
			printf("%s\n", env->env_cpy[j]);
>>>>>>> export
			j++;
		}
	}
	return (1);
}
