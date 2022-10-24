/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvaisman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:47:52 by dvaisman          #+#    #+#             */
/*   Updated: 2022/10/24 12:53:14 by dvaisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_handle(t_printf_settings *settings)
{
	size_t			index;
	unsigned char	current;

	settings->end = 0;
	index = 0;
	current = settings->format[index];
	while (current && !settings->end)
	{
		index++;
		if (current != FT_PRINTF_CHAR_FORMAT)
			ft_printf_putchar(settings, (char)current);
		else
			ft_printf_format(settings, &index);
	}
}
