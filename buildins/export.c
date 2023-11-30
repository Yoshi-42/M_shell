#include "minishell.h"

void	add_to_env(char *cmd, t_env *env)
{
	char	**updated_env;
	int		len;
	int		i;

	i = -1;
	len = -1;
	printf("cmd = %s\n", cmd);
	while (env->env_cpy[++len])
		;
	printf("len = %d\n", len);
	updated_env = malloc(sizeof(char *) * (len + 1));
	if (!updated_env)
		return ;
	updated_env[len] = ft_strdup(cmd);
	updated_env[len + 1] = NULL;
	while (env->env_cpy[++i])
		updated_env[i] = ft_strdup(env->env_cpy[i]);
	// i = -1;
	//while (env->env_cpy[++i])
	//	free(env->env_cpy[i]);
	// free(env->env_cpy);
	env->env_cpy = updated_env;
	//i = -1;
	//while (updated_env[++i])
	//	free(updated_env[i]);
	//free(updated_env);
}

int	m_export(char **cmds, t_env *env)
{
	int		i;
	int		j;
	int		found;
	char	*equal;
	char	*key_with_equal;

	i = -1;
	if (!cmds[1])
	{
		while (env->env_cpy[++i])
			printf("env[%d] = %s\n", i, env->env_cpy[i]);
	}
	else
	{
		j = 0;
		while (cmds[++j])
		{
			if (check_digit(cmds[j]))
			{
				printf("export: not an identifier: %s\n", cmds[j]);
				break ;
			}
			found = 0;
			//printf("cmd[%d] = %s\n", j, cmds[j]);
			env->key = ft_strdup(cmds[j]);
			i = -1;
			//equal_found
			if (ft_strchr(env->key, '='))
			{
				while (env->key[++i] != '=')
					;
				if (ft_strlen(env->key) + 1 == i)
					return (1);
				env->key[i] = '\0';
			}
			//equal_not_found
			else if (!ft_strchr(env->key, '='))
			{
				equal = "=''";
				printf("key before add equal: %s\n", env->key);
				printf("equal: %s\n", equal);
				while (env->key[++i] <= '=')
					;
				if (ft_strlen(env->key) + 2 == i)
					return (1);
				key_with_equal = ft_strncat(env->key, equal, ft_strlen(equal));
				env->key = key_with_equal;
				printf("key after add equal: %s\n", env->key);
				add_to_env(key_with_equal, env);
				//key[i] = '\0';
			}
			//printf("key = %s\n", key);
			i = -1;
			while (env->env_cpy[++i])
			{
				if (ft_strcmp(env->key, env->env_cpy[i]) == 0)
				{
					// printf("i pour free = %d\n", i);
					printf("env->env_cpy[%d] = %s\n", i, env->env_cpy[i]);
					//free(env->env_cpy[i]);
					env->env_cpy[i] = ft_strdup(cmds[j]);
					found = 1;
					//return (0);
				}
			}
			if (!found)
				add_to_env(cmds[j], env);
		}
	}
	return (0);
}

/* maintenant il faut gerer quand il y a plusieurs arguments
quand le premier caractere de key est compris entre 0 et 9 ->
export renvoie une erreur
erreur renvoyee :  "export: not an identifier: %s"
%s etant la chaine invalide
lorsque l'on rentre plusieurs parametres valides, ils s'ajoutent
aux variables d'environnement
exemple : export test1 test2 test3 -> dans export les cles
sont ajoutees les unes apres les autres
et leur valeur = '' chaine vide
check key : check first c != digit ; si il n'y a pas de =
add key=''; si = seul add key='' ; si = avec valeur add key en entier*/