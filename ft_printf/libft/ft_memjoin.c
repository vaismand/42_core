#include "libft.h"

char    *ft_memjoin(void *s1, size_t l1, void *s2, size_t l2)
{
	char	*str;

	if (!s1 || !s2 || !(str = malloc(l1 + l2)))
		return (NULL);
	ft_memcpy(str, s1, l1);
	ft_memcpy(str + l1, s2, l2);
	return (str);
}