#include "../minishell.h"

//parcourir les chaines
//si $ entrer dans une fonction qui va parcourir a partir du $ jusqu'au prochain $ ou espace
//faire un strncmp de la chaine extraite avec chaque ligne de **env
// si on trouve on entre dans une nouvelle fonction

int	long_doll(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0 || str[i] != '$' || ft_isspace(str[i]))
		i++;
	return (i);
}

char	*ft_resize(char *str, char **env)
{
	char	*buff;
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], str, ft_strlen(str) - 1) && env[ft_strlen(str)] == '=')
		{
			buff = ft_substr(env[i], ft_strlen(str) + 1, ft_strlen(env[i]));
			return (buff);
		}
		else
			i++;
	}
	return ("");
}

char	*ft_insert(char *src, char *app, int start)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(sizeof(char) * ((ft_strlen(str) + ft_strlen(buff)) - ft_strlen(var)))
	while (dest[i])
	{
		while (i < start)
		{
			dest[i] = src[i];
			i++;
		}
		while (app[j])
		{
			dest[i] = app[j];
			i++;
			j++;
		}
		while (src[i])
		{
			dest[i] = src[i - j];
			i++;
		}
	}
	return (dest);
}

char	*ft_replace_var(char *str, char **env)
{
	int		i;
	int		size;
	char	*buff;
	char	*dest;
	char	*var;

	i = 0;
	size = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			size = long_doll(&str[i + 1]);
			var = ft_substr(str, i + 1, size);
			buff = ft_resize(var, env);
			dest = ft_insert(str, buff, i + 1);
			str = ft_strdup(dest);
			i = 0;
			continue;
		}
		i++;
	}
	return (str);
}

char	**ft_parkour(char **cmd, char **env)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cmd[i])
	{
		i = 0;
		if (ft_strchr(cmd[i], '$') && cmd[i][0] != '\'')
			ft_replace_var(cmd[i], env);
		i++; 
	}
}