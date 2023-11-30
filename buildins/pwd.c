#include "../minishell.h"

void m_pwd(void)
{
	char *s;
	size_t size = 2042;

	s = malloc((size + 1) * sizeof(char));
	getcwd(s, size);
	printf("%s\n", s);
	free(s);
}

