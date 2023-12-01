#include "../minishell.h"

int heredoc(char *EOF)
{
	int		pipefd[2];
	char	*input;

	if (pipe(pipefd) == -1) {
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	while (1) 
	{
		input = readline("heredoc>");
		if (ft_strcmp(input, EOF, ft_strlen(EOF)) == 0 && ft_strlen(EOF) == ft_strlen(input)) 
		{
			free(input);
			break;
		}
		write(pipefd[1], input, strlen(input));
		write(pipefd[1], "\n", 1);
		free(input);
	}
	close(pipefd[1]);
	return (pipefd[0]);
}