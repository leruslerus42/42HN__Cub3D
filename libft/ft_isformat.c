/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isformat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paroonag <paroonag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 04:54:28 by paroonag          #+#    #+#             */
/*   Updated: 2022/07/30 10:34:24 by paroonag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isformat(char *str, char *fmt)
{
	int		len_str;
	int		len_fmt;
	char	*start_fmt;

	len_str = ft_strlen(str);
	len_fmt = ft_strlen(fmt);
	if (len_str <= len_fmt)
		return (0);
	start_fmt = str + len_str - len_fmt;
	if (ft_strncmp(start_fmt, fmt, len_fmt) == 0)
		return (1);
	return (0);
}
