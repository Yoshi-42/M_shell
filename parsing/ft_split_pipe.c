char **ft_split_pipe(char **cmd)
{
	int	start;
	int	end;
	int	size;
	char **dest;

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
		dest = malloc(sizeof(char *) * end);
		while (start < end)
		{
			dest[start] = ft_strdup(cmd[start]);
			start++;
		}
		dest[start] = NULL;
	}
	return (dest);
}

int	ft_count_pipe(char **cmd)
{
	int	i;
	int	count;

	i = 0;
	while (cmd[i])
	{
		if (ft_strcmp(cdm[i], "|") == 0)
			count++;
		i++;
	}
	return (count + 1);
}

t_node	*ft_create_nodes(char **cmd)
{
	int	n;
	t_node	*node;
	int i;
	int	j;

	i = 0;
	j = 1
	n = ft_count_pipe(cmd);
	node = malloc(sizeof(t_node *) * n);
	node[0]->cmd->cmd = ft_split_pipe(cmd);
	while (cmd[i])
	{
		if (ft_strcmp(cmd[i], "|") == 0 && j < n)
		{
			node[j].cmd->cmd = ft_split_pipe(&cmd[i + 1]);
			j++;
		}
		i++;
	}
	return (node);
}