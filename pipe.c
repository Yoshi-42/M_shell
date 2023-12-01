#include "minishell.h"


void print_tab(char **tableau);
//void init_tab(char ***tableau, int nombreDeChaines, char *chaines[]);
int	redirect(t_command cmd, int p_i, int p_o);

void	m_pipe(t_command *cmd)
{
	//int		*pipefd;

	//pipefd = malloc(sizeof(int) * 2);
	//pipe(pipefd);
	//dup2(pipefd[0], STDIN_FILENO);//on defini l'entree du pipe
	redirect(*cmd, -1, -1);
	//close(pipefd[0]);
	//dup2(pipefd[1], STDOUT_FILENO);	
}

int	fake_tree(t_list *l_cmd)
{
	t_list	*index;
	int		fd_in;
	int		fd_out;
	int		*fd_pipe;
	
	index = l_cmd;
	fd_pipe = malloc(sizeof(int) * 2);
	fd_in = -1;
	fd_out = -1;
	while (index->next != NULL)//tant que l_cmd->next != NULL 
	{
		//print_tab(index->cmd->cmd);
		pipe(fd_pipe);
		fd_out = fd_pipe[0];
		printf("pipe sorti : %i\n", fd_out);
		//m_pipe(index->cmd);
		redirect(*index->cmd, fd_in, fd_out);
		fd_in = fd_pipe[1];
		index = index->next;
		close(fd_out);
	}
	redirect(*index->cmd, fd_in, -1);
	//m_pipe(index->cmd);

	//print_tab(index->cmd->cmd);


	
	//			on creer un pipe
	//			on definie entrer et sorti
	//			on fait entrer notre commande dans la boucle des redirection
	//				a l'interieur on lexecute autant de fois qu'il y a des sorti et des entree
	//			puis on l'execute dans le pipe


	// arriver la on execute la derniere command (ou la premiere si il n'y en a qu'une)
	// dans la boucle des redirection
	return (0);
}
/*
int main ()
{
    t_list *pipe;
    pipe = malloc(sizeof(t_list));
    pipe->cmd = malloc(sizeof(t_command));  // Allouer de la mémoire pour la structure t_command
    char *debug[] = {"ls", "-la" , "<" , "RUBIS", ">>", "SAPHIR", ">>", "diadem"};
    init_tab(&pipe->cmd->cmd, 8, debug);
    pipe->next = malloc(sizeof(t_list));
    pipe->next->cmd = malloc(sizeof(t_command));  // Allouer de la mémoire pour la structure t_command
    char *debug2[] = {"grep", "fromage","<", "gingembre", "<", "bleu"};
    init_tab(&pipe->next->cmd->cmd, 6, debug2);
    pipe->next->next = NULL;
    fake_tree(pipe);
    return 0;
}
*/
void init_tab(char ***tab, int size, char *args[]) {
    *tab = malloc((size + 1) * sizeof(char *));
    for (int i = 0; i < size; i++) {
        (*tab)[i] = args[i];
    }
    (*tab)[size] = NULL;  // Marquer la fin du tableau avec NULL
}

int main() {
    t_list *pipe;
    pipe = malloc(sizeof(t_list));

    // Première commande
    pipe->cmd = malloc(sizeof(t_command));
    char *debug1[] = {"ls", "-la", ">", "output.txt"};
    init_tab(&pipe->cmd->cmd, 4, debug1);
    pipe->next = NULL;

    // Deuxième commande
    t_list *second_command = malloc(sizeof(t_list));
    pipe->next = second_command;
    second_command->cmd = malloc(sizeof(t_command));
    char *debug2[] = {"grep", "r", ">>", "hello.txt"};
    init_tab(&second_command->cmd->cmd, 4, debug2);
    second_command->next = NULL;

    // Troisième commande
    t_list *third_command = malloc(sizeof(t_list));
    second_command->next = third_command;
    third_command->cmd = malloc(sizeof(t_command));
    char *debug3[] = {"cat"};
    init_tab(&third_command->cmd->cmd, 1, debug3);
    third_command->next = NULL;

    // Appel de la fonction qui manipule la liste chaînée
    fake_tree(pipe);

    // Libération de la mémoire à la fin du programme (à adapter selon votre structure)
    free(pipe->cmd->cmd);
    free(pipe->cmd);
    free(pipe);

    free(second_command->cmd->cmd);
    free(second_command->cmd);
    free(second_command);

    free(third_command->cmd->cmd);
    free(third_command->cmd);
    free(third_command);

    return 0;
}
