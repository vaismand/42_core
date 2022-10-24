/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_pointer.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvaisman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:11:49 by dvaisman          #+#    #+#             */
/*   Updated: 2022/10/24 14:15:25 by dvaisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_printf_format_pointer_2(char *str, unsigned long ptr, \
		t_printf_comb *bundle)
{
	if (ptr == 0 && bundle->flags->precision == 0 && \
			bundle->flags->precision_set)
	{
		free(str);
		return (ft_emptystr());
	}
	return (str);
}

char	*ft_printf_format_pointer(t_printf_comb *bundle)
{
	char			*str;
	unsigned long	ptr;

	ptr = va_arg(bundle->settings->args, unsigned long);
	str = ft_itoa_base(ptr, 16);
	str = ft_printf_format_pointer_2(str, ptr, bundle);
	str = ft_strjoin_free("0x", str, 2);
	return (str);
}
