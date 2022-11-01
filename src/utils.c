/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paroonag <paroonag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 04:27:44 by paroonag          #+#    #+#             */
/*   Updated: 2022/07/30 11:52:22 by paroonag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	set_color_utils(t_info *cub, int type, int hex)
{
	if (type == FLOOR && cub->ele.floor == -1)
		cub->ele.floor = hex;
	else if (type == CEILING && cub->ele.ceiling == -1)
		cub->ele.ceiling = hex;
	else
		ft_exit("multiple floor/ceiling colors");
}

int	valid_and_set_element_lines(t_info *cub, char **word, int cnt_word)
{
	int	type;

	valid_element_lines(word[0], cnt_word);
	type = set_elements(cub, word);
	return (type);
}

void	ft_exit(const char *str)
{
	ft_putstr(str);
	ft_putstr("\n");
	exit(0);
}
