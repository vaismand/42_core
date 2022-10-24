/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_flags.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvaisman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:18:12 by dvaisman          #+#    #+#             */
/*   Updated: 2022/10/21 11:24:39 by dvaisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_parse_precision(const char *format, t_printf_comb *bundle)
{
	int	i;

	i = 0;
	if (format[i] == '.')
	{
		i++;
		bundle->flags->precision = 0;
		if (format[i] == '*')
		{
			bundle->flags->precision = va_arg(bundle->settings->args, int);
			i++;
		}
		else
		{
			while (ft_isdigit(format[i]))
			{
				bundle->flags->precision = \
					bundle->flags->precision * 10 + (format[i] - '0');
				i++;
			}
		}
	}
	return (i);
}

int	ft_printf_parse_width(const char *format, t_printf_comb *bundle)
{
	int	i;

	i = 0;
	if (ft_isdigit(format[i]))
	{
		bundle->flags->width = 0;
		while (ft_isdigit(format[i]))
		{
			bundle->flags->width = \
				bundle->flags->width * 10 + (format[i] - '0');
			i++;
		}
	}
	else if (format[i] == '*')
	{
		bundle->flags->width = va_arg(bundle->settings->args, int);
		i++;
	}
	return (i);
}

int	ft_printf_parse_flags(const char *format, t_printf_comb *bundle)
{
	int	i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '-')
			bundle->flags->minus_sign = 1;
		else if (format[i] == '0')
			bundle->flags->minus_sign = 1;
		else if (format[i] == '.')
			i += ft_printf_parse_precision(format + i, bundle);
		else if (ft_isdigit(format[i]) || format[i] == '*')
			i += ft_printf_parse_width(format + i, bundle);
		else
			break ;
		i++;
	}
	return (i);
}
