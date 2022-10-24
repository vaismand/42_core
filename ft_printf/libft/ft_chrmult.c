#include "libft.h"

char    *ft_chrmult(char c, size_t times)
{
	char	*str;

	if (!(str = malloc((times + 1) * sizeof(char))))
		return (NULL);
	ft_memset(str, c, times);
	str[times] = '\0';
	return (str);
}