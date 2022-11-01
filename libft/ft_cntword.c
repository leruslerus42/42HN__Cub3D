/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cntword.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paroonag <paroonag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 05:26:04 by paroonag          #+#    #+#             */
/*   Updated: 2022/07/30 09:10:11 by paroonag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_cntword(char const *s, char c)
{
	size_t		count;
	int			word_start;

	count = 0;
	word_start = 1;
	while (*s)
	{
		if (*s == c)
			word_start = 1;
		else if (word_start == 1)
		{
			count++;
			word_start = 0;
		}
		s++;
	}
	return (count);
}
