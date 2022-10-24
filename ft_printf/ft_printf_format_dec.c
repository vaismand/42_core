/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_dec.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvaisman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:36:22 by dvaisman          #+#    #+#             */
/*   Updated: 2022/10/24 14:38:54 by dvaisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_dec_empty(int zero, t_printf_flags *flags)
{
	return (zero && flags->precision_set && !flags->precision == 0);
}

char	*ft_printf_format_dec_precision(char *str, t_printf_flags *flags)
{
	int		len;
	int		zero;
	char	*new;

	len = ft_strlen(str);
	zero = flags->precision - len;
	if (ft_printf_dec_empty(zero, flags))
		return (ft_emptystr());
	if (zero > 0)
	{
		new = ft_strnew(zero);
		ft_memset(new, '0', zero);
		str = ft_strjoin_free(new, str, 3);
	}
	return (str);
}

char	*ft_printf_format_dec_width(char *str, t_printf_flags *flags)
{
	int		len;
	int		zero;
	char	*new;

	len = ft_strlen(str);
	zero = flags->width - len;
	if (zero > 0)
	{
		new = ft_strnew(zero);
		ft_memset(new, ' ', zero);
		if (flags->minus_sign)
			str = ft_strjoin_free(str, new, 3);
		else
			str = ft_strjoin_free(new, str, 3);
	}
	return (str);
}

char	*ft_printf_format_dec(t_printf_comb *bundle)
{
	char	*str;

	str = ft_itoa(va_arg(bundle->settings->args, int));
	str = ft_printf_format_dec_precision(str, bundle->flags);
	str = ft_printf_format_dec_width(str, bundle->flags);
	return (str);
}
