/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:19:23 by artmarti          #+#    #+#             */
/*   Updated: 2023/12/01 20:19:24 by artmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_tab(char **tableau)
{
	int	i;

	i = 0;
	while (tableau[i] != NULL)
	{
		printf("%s\n", tableau[i]);
		i++;
	}
}

void	ft_freetabs(char **tab)
{
	int	i;

	i = 0;
	if(tab != NULL)
	{
		while(tab[i])
		{
			free(tab[i]);
			tab[i] = NULL;
			i++;
		}
		free(tab);
		tab = NULL;
	}
}

void	ft_freetabs_plus(char **tab)
{
	int	i;

	i = 0;
	if(tab != NULL)
	{
		while(tab[i])
		{
			free(tab[i]);
			tab[i] = NULL;
			i++;
		}
	}
}

int ft_tab_len(char **array) 
{
    int i;
	
	i = 0;
    while (array[i] != NULL) 
       i++;
    return i;
}

void	ft_free_command(t_command **cmd)
{
	int i;

	i = 0;
	if ((*cmd)[0].cmd != NULL)
	{
		while ((*cmd)[i].cmd != NULL)
		{
			ft_freetabs_plus((*cmd)[i].cmd);
			ft_freetabs_plus((*cmd)[i].env.env_cpy);
			free((*cmd)[i].env.env_cpy);
			i++;
		}
		free((*cmd)[i].env.env_cpy);
		free(*cmd);
		(*cmd) = NULL;
	}
}