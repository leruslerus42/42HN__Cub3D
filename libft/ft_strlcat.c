/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paroonag <paroonag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 13:13:43 by paroonag          #+#    #+#             */
/*   Updated: 2021/06/18 13:39:11 by paroonag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	t;
	size_t	o;

	o = n;
	t = ft_strlen(dest) + ft_strlen(src);
	while (*dest != 0 && n > 0)
	{
		dest++;
		n--;
	}
	if (n == 0)
		return (ft_strlen(src) + o);
	while (*src != 0 && n > 1)
	{
		*dest++ = *src++;
		n--;
	}
	*dest = 0;
	return (t);
	return (0);
}
