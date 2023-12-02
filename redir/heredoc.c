/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:37:12 by artmarti          #+#    #+#             */
/*   Updated: 2023/12/01 20:37:29 by artmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	heredoc(char *eof)
{
	int		pipefd[2];
	char	*input;

	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		input = readline("heredoc>");
		if (ft_strncmp(input, eof, ft_strlen(eof)) == 0
			&& ft_strlen(eof) == ft_strlen(input))
		{
			free(input);
			break ;
		}
		write(pipefd[1], input, strlen(input));
		write(pipefd[1], "\n", 1);
		free(input);
	}
	close(pipefd[1]);
	return (pipefd[0]);
}
