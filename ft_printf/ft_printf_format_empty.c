/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_empty.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvaisman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:35:06 by dvaisman          #+#    #+#             */
/*   Updated: 2022/10/24 14:39:49 by dvaisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_format_empty(t_printf_comb *bundle)
{
	if (bundle->flags->precision_set)
		bundle->flags->precision_set = 0;
	if (bundle->flags->letter == '\0')
		return (ft_emptystr());
	bundle->len = 1;
	return (ft_chartostr(bundle->flags->letter));
}
