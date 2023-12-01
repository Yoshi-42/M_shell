
#include "../minishell.h"

char **ft_split_pipe(char **cmd)
{
	int	start;
	int	end;
	int	size;
	char **dest;

	size = 0;
	while (cmd[size])
		size++;
	start = 0;
	end = 0;
	while (cmd[end] && ft_strcmp(cmd[end], "|") != 0)
		end++;
	if (end == size)
		return (cmd);
	else
	{
		dest = malloc(sizeof(char *) * (end + 1));
		while (start < end)
		{
			dest[start] = ft_strdup(cmd[start]);
			start++;
		}
		dest[start] = NULL;
	}
	return (dest);
}

char **tabtab_strdup(char **tab)
{
	int	i;
	char **dest;

	i = 0;
	while (tab[i])
		i++;
	dest = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (tab[i])
	{
		dest[i] = ft_strdup(tab[i]);
		i++;
	}
	dest[i] = NULL;
	return (dest);
}


int	ft_count_pipe(char **cmd)
{
	int	i;
	int	count;

	i = 0;
	while (cmd[i])
	{
		if (ft_strcmp(cmd[i], "|") == 0)
			count++;
		i++;
	}
	return (count + 1);
}

t_command	*ft_create_nodes(char **cmd, char **env)
{
	int	n;
	t_command	*node;
	int i;
	int	j;

	i = 0;
	j = 1;
	n = ft_count_pipe(cmd);
	node = malloc(sizeof(t_command *) * n + 1);
	node[0].cmd = ft_split_pipe(cmd);
	while (cmd[i])
	{
		if (ft_strcmp(cmd[i], "|") == 0 && j < n)
		{
			node[j].cmd = ft_split_pipe(&cmd[i + 1]);
			node[j].env.env_cpy = tabtab_strdup(env);
			j++;
		}
		i++;
	}
	node[j].cmd = NULL;
	return (node);
}