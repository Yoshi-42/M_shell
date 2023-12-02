/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:52:18 by artmarti          #+#    #+#             */
/*   Updated: 2023/12/01 20:52:19 by artmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	fake_tree(t_command *l_cmd)
{
	int	i;
	int	fd_in;
	int	fd_out;
	int	*fd_pipe;

	fd_pipe = malloc(sizeof(int) * 2);
	fd_in = -1;
	fd_out = -1;
	i = 0;
	while (l_cmd[i + 1].cmd != NULL)
	{
		pipe(fd_pipe);
		fd_out = fd_pipe[1];
		redirect(l_cmd[i], fd_in, fd_out);
		if (fd_in != -1)
			close (fd_in);
		fd_in = fd_pipe[0];
		i++;
		close(fd_out);
	}
	redirect(l_cmd[i], fd_in, -1);
	return (0);
}
