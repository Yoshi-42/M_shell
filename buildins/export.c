#include "../minishell.h"

//ajoute l element a env copy 
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

//verifie si le premier caractere est un digit
//si c'est le cas, le message d'erreur s'affcihe 
//a la premiere erreur rencontree 
static int check_errors(char *str, t_env *env)
{
	if (ft_isdigit(str[0]) != 0)
	{
		env->flag_arg_error++;
		if (env->flag_arg_error == 1)
		{
			printf("export: not an identifier: %s\n", str);
			return (1);
		}
	}
	return (0);
}

//stocke dans env->key tout ce qui est avant le = si il y a une valeur ou
//jusqau = si il y a pas de valeur
static int get_key(char *arg, t_env *env)
{
    int i;

    i = -1;
	env->key = ft_strdup(arg);
	if (!env->key)
		return (1);
	if (ft_strchr(env->key, '='))
	{
		while (env->key[++i] != '=')
			;
		if (ft_strlen(env->key) + 1 == i)
			return (1);
		env->key[i] = '\0';
	}
	return (0);
}

//verifie si il y a pas = ou si dernier caractere est =
static int	check_equal(char *arg)
{
	if (!ft_strchr(arg, '='))
		return (1);
	if (arg[ft_strlen(arg) - 1] == '=')
		return (1);
	return (0);
}

//vérifie si la clé est deja présente dans env
static int key_already_in_env(char *arg, t_env *env)
{
	int i;

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
static void update_key(char *arg, t_env *env)
{
	int i;

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
static void update_env(char *arg, t_env *env)
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
			printf("env %d = %s\n", j, env->env_cpy[j]);
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
