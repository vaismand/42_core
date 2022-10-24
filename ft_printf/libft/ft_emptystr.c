#include "libft.h"

char	*ft_emptystr(void)
{
    char	*str;

    str = (char *)malloc(sizeof(char));
    if (str == NULL)
        return (NULL);
    str[0] = '\0';
    return (str);
}