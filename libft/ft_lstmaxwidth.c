/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmaxwidth.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paroonag <paroonag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 04:58:46 by paroonag          #+#    #+#             */
/*   Updated: 2022/07/30 10:33:51 by paroonag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstmaxwidth(t_list *lst)
{
	size_t	max;
	size_t	len;

	max = 0;
	while (lst)
	{
		len = ft_strlen((const char *)lst->content);
		if (len > max)
			max = len;
		lst = lst->next;
	}
	return (max);
}
