/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrmult.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvaisman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:10:31 by dvaisman          #+#    #+#             */
/*   Updated: 2022/10/24 13:14:56 by dvaisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_chrmult(char c, size_t times)
{
	char	*str;

	str = (malloc(times + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_memset(str, c, times);
	str[times] = '\0';
	return (str);
}
