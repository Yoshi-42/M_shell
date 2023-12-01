#include "minishell.h"
#include <string.h>


void print_tab(char **tableau) 
{
	int	i;
	
	i = 0;
	while (tableau[i] != NULL) {
		printf("%s\n", tableau[i]);  // Afficher chaque mot
		i++;
	}
}
/*
void init_tab(char ***tableau, int nombreDeChaines, char *chaines[]) 
{
    *tableau = (char **)malloc(nombreDeChaines * sizeof(char *));

    if (*tableau == NULL) {
        fprintf(stderr, "Erreur d'allocation de mémoire\n");
        exit(EXIT_FAILURE);
    }
	
    for (int i = 0; i < nombreDeChaines; ++i) {
        (*tableau)[i] = strdup(chaines[i]);
        
        if ((*tableau)[i] == NULL) {
            fprintf(stderr, "Erreur d'allocation de mémoire pour la chaîne %d\n", i);
            exit(EXIT_FAILURE);
        }
    }
}
*/