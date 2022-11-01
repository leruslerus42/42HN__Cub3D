/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paroonag <paroonag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 16:52:48 by paroonag          #+#    #+#             */
/*   Updated: 2021/06/22 20:22:41 by paroonag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = (char *)malloc(nitems * size);
	if (ptr == 0)
		return (0);
	while (i < nitems * size)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}
