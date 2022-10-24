/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_reg.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvaisman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:55:54 by dvaisman          #+#    #+#             */
/*   Updated: 2022/10/24 13:49:16 by dvaisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_printf_format_reg(char key)
{
	size_t	index;

	index = 0;
	while (g_formatter_key[index])
	{
		if (g_formatter_key[index] == key)
			return (g_formatters[index]);
		index++;
	}
	return (NULL);
}
