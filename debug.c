#include "minishell.h"

void print_tab(char **tableau) 
{
	int	i;
	
	i = 0;
	while (tableau[i] != NULL) {
		printf("%s\n", tableau[i]);  // Afficher chaque mot
		i++;
	}
}
