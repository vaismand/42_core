/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_octal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvaisman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:49:56 by dvaisman          #+#    #+#             */
/*   Updated: 2022/10/24 14:52:52 by dvaisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_format_octal(t_printf_comb *bundle)
{
	unsigned int	num;
	char			*str;

	num = va_arg(bundle->settings->args, unsigned int);
	str = ft_itoa_base(num, 8);
	if (bundle->flags->precision_set && \
		bundle->flags->precision == 0 && num == 0)
		str = ft_emptystr();
	if (bundle->flags->precision_set && bundle->flags->precision > 0)
		str = ft_printf_precision(bundle, str);
	if (bundle->flags->width_set && bundle->flags->width > 0)
		str = ft_printf_width(bundle, str);
	bundle->len = ft_strlen(str);
	return (str);
}
