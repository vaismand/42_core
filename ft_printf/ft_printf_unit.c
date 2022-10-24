/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvaisman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:58:22 by dvaisman          #+#    #+#             */
/*   Updated: 2022/10/24 13:19:14 by dvaisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_unit(t_printf_flags *flags, int offset)
{
	char	*str;
	int		len;

	str = ft_strnew(1);
	str[0] = flags->type;
	len = ft_strlen(str);
	if (flags->width > len)
	{
		if (flags->minus_sign)
			str = ft_strjoin_free(str, ft_strnew(flags->width - len), 3);
		else
			str = ft_strjoin_free(ft_strnew(flags->width - len), str, 3);
	}
	ft_putstr_fd(str + offset, 1);
	free(str);
	return (ft_strlen(str + offset));
}
