/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_hex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvaisman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:59:36 by dvaisman          #+#    #+#             */
/*   Updated: 2022/10/24 14:16:28 by dvaisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_format_hex(t_printf_comb *bundle)
{
	unsigned int	num;
	char			*str;

	num = va_arg(bundle->settings->args, unsigned int);
	str = ft_itoa_base(num, 16);
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