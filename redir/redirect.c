#include "../minishell.h"

int	m_exe(t_command cmd) //(char **cmd, char **envp)
{
	pid_t child_pid;
	int status;
	char *file;

	 child_pid = fork();
	if (child_pid == -1)
	{
		perror("Erreur de processus");
		return (-1);
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		file = ft_strjoin("/bin/", cmd.cmd[0]);
		//execve(cmd.cmd[0], cmd.cmd, cmd.env.env_cpy);
		execve(file, cmd.cmd, cmd.env.env_cpy);
		perror("Erreur d'exécution");
		exit(EXIT_FAILURE);
		return (-1);
	}
	else
	{
		waitpid(child_pid, &status, 0);
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		{
			printf("La commande FAILED end %d\n", WEXITSTATUS(status));
		}
	}
	return (0);
}

int	verfi_word(const char *word, const char *verif)
{
	size_t	size;

	size  = strlen(verif); /////Error
	if(!strncmp(word, verif, size) && strlen(word) == size) ///ERROR
		return (1);
	return (0);
}

int	is_redir(char *word)
{
	if( verfi_word(word, "<") == 1 )
		return (1);
	if ( verfi_word(word, "<<") == 1)
		return (2);
	if( verfi_word(word, ">") == 1)
		return (3);
	if (verfi_word(word, ">>") == 1)
		return (4);
	return (0);
}

int	nb_word(char **tab)
{
	int	i;
	int count;

	i = 0;
	count = 0;
	while (tab[i] != NULL)
	{
		if (!is_redir(tab[i]))
			count++ ;
		else
			i++;
		i++;
	}
	return (count);
}

t_command	*format_exe(t_command cmd)
{
	int			i;
	int			j;
	t_command	*format;

	format = malloc(sizeof(t_command));
	format->cmd = malloc(sizeof(char *) * (nb_word(cmd.cmd) + 1));
	i = 0;
	j = 0;
	while(cmd.cmd[i] != NULL)
	{
		
		if(!is_redir(cmd.cmd[i]))
		{
			format->cmd[j]  = strdup(cmd.cmd[i]);
			j++;
		}
		else
			i++;
		if(cmd.cmd[i] != NULL)
			i++;
	}
	format->cmd[j] = NULL;
	return (format);
}

void	exe_node(t_command cmd, int in, int out)
{
	int origin_fd = dup(STDOUT_FILENO);
	int ori_fd_in = dup(STDIN_FILENO);
	if (in > 0)
		dup2(in, 0);
	if (out > 0)
		dup2(out, 1);
	m_exe(cmd);
	dup2(origin_fd, 1);
	dup2(ori_fd_in, 0);
}

int	all_nodes_no_enter(t_command cmd,t_command cmd_exe, int p_i , int p_o)
{
	int i;
	int	fd_out;
	int	flag;

	i = 0;
	flag = 0;
	if (p_o != -1)
	{
		exe_node(cmd_exe, p_i, p_o);
		flag++;
	}
	while (cmd.cmd[i] != NULL)
	{
		if (verfi_word(cmd.cmd[i], ">") || verfi_word(cmd.cmd[i], ">>"))
		{
			if (cmd.cmd[i + 1] == NULL)
				return (-1);
			if (verfi_word(cmd.cmd[i], ">"))
				fd_out = open(cmd.cmd[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
			else
				fd_out = open(cmd.cmd[i + 1], O_WRONLY | O_CREAT | O_APPEND, 0666);	
			if (fd_out ==  -1)
				perror("ERREUR DE FICHIER");
			exe_node(cmd_exe, p_i, fd_out);
			flag++;
			close (fd_out);
		}
		i++;
	}
	if (flag == 0)
			exe_node(cmd_exe, p_i, 1);
	

	return (0);
}

int	all_nodes(t_command cmd,t_command cmd_exe, int p_i, int p_o)
{
	int	i;
	int fd_in;
	int	flag;
	
	i = 0;
	flag = 0;
	if (p_i != -1)
	{
		all_nodes_no_enter(cmd, cmd_exe, p_i, p_o);
		flag++;
	}
	while (cmd.cmd[i] != NULL)
	{
		if (verfi_word(cmd.cmd[i], "<") || verfi_word(cmd.cmd[i], "<<"))
		{
			if (cmd.cmd[i + 1] == NULL)
					return (-1);
			if (verfi_word(cmd.cmd[i], "<"))
				fd_in = open(cmd.cmd[i + 1], O_RDONLY | O_CREAT , 0666);
			else
				fd_in = heredoc(cmd.cmd[i + 1]);
			if (fd_in ==  -1)
				perror("ERREUR DE FICHIER");
			all_nodes_no_enter(cmd, cmd_exe, fd_in, p_o);
			flag++;
		}
		i++;
	}
	if(flag == 0)
		all_nodes_no_enter(cmd, cmd_exe, -1, p_o);		
	return (0);
}

int	redirect(t_command cmd, int p_i, int p_o)
{
	t_command	*cmd_exe;

	cmd_exe = format_exe(cmd);
	return (all_nodes(cmd, *cmd_exe, p_i, p_o));
}