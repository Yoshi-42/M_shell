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
}

int	m_export(char **cmds, t_env *env)
{
	int	j;

	j = 0;
	env->flag_arg_error = 0;
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
		while (cmds[++j])
			update_env(cmds[j], env);
	}
	return (1);
}
