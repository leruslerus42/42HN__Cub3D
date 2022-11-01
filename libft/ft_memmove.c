/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paroonag <paroonag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 12:27:01 by paroonag          #+#    #+#             */
/*   Updated: 2021/06/22 21:09:54 by paroonag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*a;
	char	*b;

	a = (char *)dst;
	b = (char *)src;
	if (dst == src)
		return (dst);
	if (b < a)
	{
		while (n--)
		{
			*(a + n) = *(b + n);
		}
		return (dst);
	}
	while (n--)
	{
		*a++ = *b++;
	}
	return (dst);
}
