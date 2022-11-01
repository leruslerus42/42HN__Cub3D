/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validCub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paroonag <paroonag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 10:45:29 by paroonag          #+#    #+#             */
/*   Updated: 2022/07/30 11:52:21 by paroonag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	valid_element_lines(char *word, int cnt_word)
{
	if (ft_strncmp(word, "NO\0", 3) == 0 && cnt_word != 2)
		ft_exit("error NO");
	else if (ft_strncmp(word, "SO\0", 3) == 0 && cnt_word != 2)
		ft_exit("error SO");
	else if (ft_strncmp(word, "WE\0", 3) == 0 && cnt_word != 2)
		ft_exit("error WE");
	else if (ft_strncmp(word, "EA\0", 3) == 0 && cnt_word != 2)
		ft_exit("error EA");
	else if (ft_strncmp(word, "F\0", 2) == 0 && cnt_word != 2)
		ft_exit("error F");
	else if (ft_strncmp(word, "C\0", 2) == 0 && cnt_word != 2)
		ft_exit("error C");
}

void	map_horizontal(t_info *cub)
{
	int	x;
	int	y;

	y = -1;
	while (++y < cub->map_height)
	{
		if (cub->map[y][0] != ' ' && cub->map[y][0] != WALL)
			ft_exit("map error west wall");
		if (cub->map[y][cub->map_width - 1] != ' ' &&
				cub->map[y][cub->map_width - 1] != WALL)
			ft_exit("map error east wall");
		x = 0;
		while (++x < cub->map_width)
		{
			if (cub->map[y][x] == ' ')
			{
				if (cub->map[y][x - 1] != ' ' && cub->map[y][x - 1] != WALL)
					ft_exit("map error east wall");
				else if (x + 1 < cub->map_width
					&& cub->map[y][x + 1] != ' ' && cub->map[y][x + 1] != WALL)
					ft_exit("map error west wall");
			}
		}
	}
}

void	map_vertical(t_info *cub)
{
	int	x;
	int	y;

	x = -1;
	while (++x < cub->map_width)
	{
		if (cub->map[0][x] != ' ' && cub->map[0][x] != WALL)
			ft_exit("map error south wall");
		if (cub->map[cub->map_height - 1][x] != ' ' &&
				cub->map[cub->map_height - 1][x] != WALL)
			ft_exit("map error north wall");
		y = 0;
		while (++y < cub->map_height)
		{
			if (cub->map[y][x] == ' ')
			{
				if (cub->map[y - 1][x] != ' ' && cub->map[y - 1][x] != WALL)
					ft_exit("map error north wall");
				else if (y + 1 < cub->map_height
					&& cub->map[y + 1][x] != ' ' && cub->map[y + 1][x] != WALL)
					ft_exit("map error south wall");
			}
		}
	}
}

void	valid_map(t_info *cub)
{
	if (!cub->ele.render_x || !cub->ele.render_y)
		ft_exit("empty rendering size");
	if (!cub->ele.xpm_path[NORTH] || !cub->ele.xpm_path[SOUTH]
		|| !cub->ele.xpm_path[WEST] || !cub->ele.xpm_path[EAST])
		ft_exit("empty texture path");
	if (cub->ele.floor == -1 || cub->ele.ceiling == -1)
		ft_exit("empty color");
	if (!cub->map_width || !cub->map_height)
		ft_exit("invalid map size");
	if (!cub->player.spawn_pos)
		ft_exit("empty player's orientation");
	map_horizontal(cub);
	map_vertical(cub);
}
