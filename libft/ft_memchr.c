/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paroonag <paroonag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 12:34:27 by paroonag          #+#    #+#             */
/*   Updated: 2021/06/21 11:40:14 by paroonag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	const char		*st;
	size_t			i;

	st = (const char *)str;
	i = 0;
	while (i < n)
	{
		if (st[i] == c)
		{
			return ((void *)(str + i));
		}
		i++;
	}
	return (0);
}
