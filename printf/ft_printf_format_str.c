/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvaisman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:56:33 by dvaisman          #+#    #+#             */
/*   Updated: 2022/10/21 10:57:22 by dvaisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_format_str(t_printf_comb *comb)
{
	char	*str;
	int		len;

	str = va_arg(comb->settings->args, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (comb->flags->precision >= 0 && comb->flags->precision < len)
		len = comb->flags->precision;
	comb->len = len;
	return (ft_strndup(str, len));
}
