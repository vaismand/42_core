/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvaisman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 09:59:12 by dvaisman          #+#    #+#             */
/*   Updated: 2022/10/24 12:47:45 by dvaisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_printf_settings	settings;

	settings.format = format;
	settings.written = 0;
	settings.fd = FT_PRINTF_FD;
	va_start(settings.args, format);
	ft_printf_handle(&settings);
	va_end(settings.args);
	return (settings.written);
}
