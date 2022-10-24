/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvaisman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:15:40 by dvaisman          #+#    #+#             */
/*   Updated: 2022/10/21 10:16:55 by dvaisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_putstr(char *str, t_printf_settings *settings, int len)
{
	int	i;

	i = 0;
	if (!str || len == 0)
		return ;
	if (len < 0)
		while (str[i])
			ft_printf_putchar(settings, str[i++]);
	else
	{
		while (i < len)
			ft_printf_putchar(settings, str[i++]);
	}
}
