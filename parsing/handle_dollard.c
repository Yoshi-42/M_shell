/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dollard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:30:15 by artmarti          #+#    #+#             */
/*   Updated: 2023/11/30 09:30:16 by artmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// Cette fonction va venir verifier si la chaine de caractere en parametre
// est une variable d'environment existante.
// Si oui elle renvoie la position de la variable d'environnemt
// Sinon elle renvoie -1
int	check_is_var_env(char *cmd)
{
	cmd = cmd;
	return (-1);
}

// Remplacer strlen par ft_strlen
char	*destroy_dollard(char *cmd, char *del)
{
	char	*str;
	int		a;
	int		i;
	int		b;

	a = 0;
	i = 0;
	b = 0;
	str = malloc(sizeof(char) * (strlen(cmd) - strlen(del) + 1));
	while (cmd[i] != '\0')
	{
		if (cmd[i] == '$' && b == 0)
		{
			i++;
			b = 1;
			while (cmd[i] != '\0' && cmd[i] != '$' && cmd[i] != ' ')
				i++;
		}
		str[a] = cmd[i];
		i++;
		a++;
	}
	str[a] = '\0';
	return (str);
}

// Cette fonction remplace le mot $ par la variable existante
// char	*replace_dollard(char *cmd, int i)
// {

// }

char	*check_dollard(char *cmd, int i)
{
	char	*str;
	int		j;
	int		a;
	int		check_var;

	a = 0;
	j = i;
	while (cmd[j] != '\0' && cmd[j] != '$' && cmd[j] != ' ')
		j++;
	str = malloc(sizeof(char) * j - i + 1);
	while (i < j)
	{
		str[a] = cmd[i];
		a++;
		i++;
	}
	str[a] = '\0';
	check_var = check_is_var_env(str);
	if (check_var == -1)
		cmd = destroy_dollard(cmd, str);
	else
		cmd = NULL;//replace_dollard(cmd, str, check_var);
	return (cmd);
}

char	**handle_dollard(char **cmds)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (cmds[i] != NULL)
	{
		while (cmds[i][j] != '\0')
		{
			if (cmds[i][j] == '$')
			{
				cmds[i] = check_dollard(cmds[i], j);
				j = 0;
			}
			else
				j++;
		}
		j = 0;
		printf("%s\n", cmds[i]);
		i++;
	}
	return (cmds);
}
