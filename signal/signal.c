/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:58:11 by artmarti          #+#    #+#             */
/*   Updated: 2023/12/01 16:58:13 by artmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_ctrlc(int sign)
{
	if (!sign)
		printf("sign\n");
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	ft_ctrlslash(int sign)
{
	if (!sign)
		printf("sign\n");
	rl_on_new_line();
	rl_redisplay();
}
