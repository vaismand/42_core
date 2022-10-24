/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvaisman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:00:06 by dvaisman          #+#    #+#             */
/*   Updated: 2022/10/24 13:20:43 by dvaisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_d(int fd, const char *format, ...)
{
	t_printf_settings	settings;

	settings.format = format;
	settings.written = 0;
	settings.fd = fd;
	va_start(settings.args, format);
	ft_printf_handle(&settings);
	va_end(settings.args);
	return (settings.written);
}
