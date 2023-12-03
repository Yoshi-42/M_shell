/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonon <bgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:56:11 by artmarti          #+#    #+#             */
/*   Updated: 2023/12/03 15:41:48 by bgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	verfi_word(const char *word, const char *verif)
{
	int	size;

	size = ft_strlen(verif);
	if (!ft_strncmp(word, verif, size) && ft_strlen(word) == size)
		return (1);
	return (0);
}

int	is_redir(char *word)
{
	if (verfi_word(word, "<") == 1)
		return (1);
	if (verfi_word(word, "<<") == 1)
		return (2);
	if (verfi_word(word, ">") == 1)
		return (3);
	if (verfi_word(word, ">>") == 1)
		return (4);
	return (0);
}

int	nb_word(char **tab)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (tab[i] != NULL)
	{
		if (!is_redir(tab[i]))
			count++;
		else
			i++;
		i++;
	}
	return (count);
}

t_command	*format_exe(t_command *cmd)
{
	int			i;
	int			j;
	t_command	*format;

	format = malloc(sizeof(t_command));
	format->cmd = (char **) ft_calloc(nb_word(cmd->cmd) + 1, sizeof(char *));
	i = 0;
	j = 0;
	while (cmd->cmd[i] != NULL)
	{
		if (!is_redir(cmd->cmd[i]))
		{
			format->cmd[j] = ft_strdup(cmd->cmd[i]);
			j++;
		}
		else
			i++;
		if (cmd->cmd[i] != NULL)
			i++;
	}
	format->cmd[j] = NULL;
	format->env.env_cpy = envp_cpy(cmd->env.env_cpy);
	return (format);
}
