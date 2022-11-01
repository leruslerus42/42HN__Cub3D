/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paroonag <paroonag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 15:03:27 by paroonag          #+#    #+#             */
/*   Updated: 2021/06/22 16:32:40 by paroonag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	a;
	size_t	b;
	char	*h;
	char	*y;

	h = (char *)haystack;
	y = (char *)needle;
	if (y[0] == '\0')
		return (h);
	a = 0;
	while (haystack[a] && a < n)
	{
		b = 0;
		while (haystack[a + b] && needle[b]
			&& a + b < n && haystack[a + b] == needle[b])
			b++;
		if (!needle[b])
			return ((char *)(haystack + a));
		a++;
	}
	return (NULL);
}
