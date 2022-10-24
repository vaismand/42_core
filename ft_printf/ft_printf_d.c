#include "ft_printf.h"

int ft_printf_d(int fd, const char *format, ...)
{
	t_printf_settings settings;

	settings.format = format;
	settings.written = 0;
	settings.fd = fd;
	va_start(settings.args, format);
	ft_printf_handle(&settings);
	va_end(settings.args);
	return (settings.written);
}