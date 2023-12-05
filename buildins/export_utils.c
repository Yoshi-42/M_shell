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

//ajoute l element a env copy 
void	add_to_env(char *cmd, t_env *env)
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
int	check_errors(char *str, t_env *env)
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
int	get_key(char *arg, t_env *env)
{
	int		i;

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
int	check_equal(char *arg)
{
	if (!ft_strchr(arg, '='))
		return (1);
	if (arg[ft_strlen(arg) - 1] == '=')
		return (1);
	return (0);
}
