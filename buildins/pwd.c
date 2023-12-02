/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:14:34 by artmarti          #+#    #+#             */
/*   Updated: 2023/12/01 14:14:35 by artmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	m_pwd(void)
{
	char	*s;
	size_t	size;

	size = 2042;
	s = malloc((size + 1) * sizeof(char));
	if (s == NULL)
		exit(EXIT_FAILURE);
	getcwd(s, size);
	if (getcwd(s, size) == NULL)
		exit(EXIT_FAILURE);
	printf("%s\n", s);
	free(s);
	return (1);
}
