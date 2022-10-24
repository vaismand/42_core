#include "libft.h"

int ft_itoa_base_nsize(int value, int base)
{
    int		size;

    size = 0;
    if (value == 0)
        return (1);
    if (value < 0)
    {
        size++;
        value *= -1;
    }
    while (value > 0)
    {
        value /= base;
        size++;
    }
    return (size);
}