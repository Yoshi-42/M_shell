#include "libft/libft.h"
#include <stdio.h>

// char	*ft_var_int(char *str, int err)
// {
// 	int	i;
// 	char *buff;
// 	char *dest;

// 	i = 0;
// 	buff = ft_itoa(err);
// 	while (str[i])
// 	{
// 		if (str[i] == '$' && str[i + 1] == '?')
// 		{
// 			dest = ft_substr(str, 0, i);
// 			dest = ft_strjoin(dest, buff);
// 			dest = ft_strjoin(dest, &str[i + 2]);
			
// 			//free(dest);
// 			//free(buff);
// 		}
// 		i++;
// 	}
// 	str = ft_strdup(dest);
// 	free(dest);
// 	free(buff);
// 	return (str);
// }
char	*ft_var_int(char *str, int err)
{
	int	i;
	char 	*dest;
	int 	size;
	char	*buff;
int			j;

j = 0;
	buff = ft_itoa(err);
	size = 0;
	//printf("Test 1\n");
	dest = malloc(sizeof(char) * (ft_strlen(buff) + ft_strlen(str) - 1));
	printf("err = %d\n", err);
	printf("buff = %s\n", buff);
	printf("str = %s\n", str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1] == '?')
		{
			printf("bleu %s\n", dest);
			while (buff[size] != '\0')
			{
				dest[i + size] = buff[size];
				printf("QUARTZ size=%i char=%c\n", size, dest[i+size]);
				size++;
			}
			printf("bleu 2 %s\n", dest);
			j++;
			j++;
		}
		dest[i + size] = str[i + j];
		printf("Tourmaline :: i=%i :: char=%c\n", i, str[i]);
		printf("GRENAT :: i=%i :: char=%c\n", i, dest[i]);
		i++;
	}
	dest[i + size] = '\0';
	printf("RUBIS : %s\n",dest);
	return (dest);
}
int main (int argc, char **argv)
{
	char *str = ft_var_int(argv[1], argc);
	printf("%s\n", str);
}