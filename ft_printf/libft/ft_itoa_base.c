/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvaisman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:11:22 by dvaisman          #+#    #+#             */
/*   Updated: 2022/10/24 13:12:41 by dvaisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_itoa_base_len(unsigned long long num, unsigned int base)
{
	size_t	len;

	len = 0;
	while (num)
	{
		num /= base;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(unsigned long long num, unsigned int base)
{
	char	*str;
	size_t	len;

	len = ft_itoa_base_len(num, base);
	if (num == 0)
		len = 1;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = (num % base) + (num % base > 9 ? 'a' - 10 : '0');
		num /= base;
	}
	return (str);
}
