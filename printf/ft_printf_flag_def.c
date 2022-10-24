/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag_def.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvaisman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 09:56:56 by dvaisman          #+#    #+#             */
/*   Updated: 2022/10/21 10:03:25 by dvaisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_flag_def(t_printf_flags *flags)
{
	flags->valid = 0;
	flags->side = 0;
	flags->minus_sign = 0;
	flags->width = 0;
	flags->width_neg = 0;
	flags->precision = 0;
	flags->precision_set = 0;
	flags->precision_neg = 0;
	flags->hashtag = 0;
	flags->type = 0;
	flags->hex_upper = 0;
	flags->letter = '\0';
	flags->padding_char = ' ';
}
