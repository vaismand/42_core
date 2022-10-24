/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_char.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvaisman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:25:50 by dvaisman          #+#    #+#             */
/*   Updated: 2022/10/21 10:46:29 by dvaisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_format_char(t_printf_comb *comb)
{
	char	c;

	c = (char)va_arg(comb->settings->args, int);
	comb->len = 1;
	return (ft_chartostr(c));
}
