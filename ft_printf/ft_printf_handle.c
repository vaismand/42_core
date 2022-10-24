#include "ft_printf.h"

void
	ft_printf_handle(t_printf_settings *settings)
{
	size_t			index;
	unsigned char	current;

	settings->end = 0;
	index = 0;
	while ((current = settings->format[index]) && !settings->end)
	{
		index++;
		if (current != FT_PRINTF_CHAR_FORMAT)
			ft_printf_putchar(settings, (char)current);
		else
			ft_printf_format(settings, &index);
	}
}