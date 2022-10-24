#include "ft_printf.h"

char	*g_formatter_key = FT_PRINTF_SUPPORTED_FORMATS;
char	*(*g_formatters[10])(t_printf_comb *) = {
	&ft_printf_format_char,
	&ft_printf_format_string,
	&ft_printf_format_pointer,
	&ft_printf_format_decimal,
	&ft_printf_format_decimal,
	&ft_printf_format_uint,
	&ft_printf_format_hex_int,
	&ft_printf_format_hex_int,
	&ft_printf_format_pourcent,
	&ft_printf_format_octal_int
};

void    *ft_printf_format_reg(char key)
{
	size_t			index;

	index = 0;
	while (g_formatter_key[index])
	{
		if (g_formatter_key[index] == key)
			return (g_formatters[index]);
		index++;
	}
	return (NULL);
}