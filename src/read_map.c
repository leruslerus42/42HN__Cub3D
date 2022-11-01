/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paroonag <paroonag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 07:18:51 by paroonag          #+#    #+#             */
/*   Updated: 2022/07/30 11:52:11 by paroonag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	init_map(t_info *cub, t_list *map_lines)
{
	int	i;

	cub->map_width = ft_lstmaxwidth(map_lines);
	cub->map_height = ft_lstsize(map_lines);
	cub->map = malloc(sizeof(char *) * (cub->map_height + 1));
	if (!(cub->map))
		ft_exit("fail to malloc map(height)");
	cub->map[cub->map_height] = NULL;
	i = 0;
	while (map_lines)
	{
		cub->map[i] = malloc(sizeof(char) * (cub->map_width + 1));
		if (!(cub->map[i]))
			ft_exit("fail to malloc map(width)");
		ft_memset(cub->map[i], ' ', cub->map_width);
		cub->map[i][cub->map_width] = '\0';
		i++;
		map_lines = (map_lines)->next;
	}
}

void	init_player(t_info *cub, int i, int j)
{
	int	degree;

	degree = 0;
	if (cub->player.spawn_pos)
		ft_exit("invalid map content(multiple player)");
	cub->player.spawn_pos = cub->map[i][j];
	cub->player.pos_x = 0.5f + j;
	cub->player.pos_y = 0.5f + i;
	cub->player.dir_x = -1.0;
	cub->player.dir_y = 0.0;
	cub->player.plane_x = 0.0;
	cub->player.plane_y = 0.66;
	cub->player.move_speed = 0.20;
	cub->player.rot_speed = 0.13;
	if (cub->player.spawn_pos == 'N')
		degree = 90;
	else if (cub->player.spawn_pos == 'S')
		degree = 270;
	else if (cub->player.spawn_pos == 'E')
		degree = 180;
	else if (cub->player.spawn_pos == 'W')
		degree = 0;
	rotate(&(cub->player), degree * (M_PI / 180));
}

void	store_map(t_info *cub, t_list *map_lines)
{
	int		i;
	int		j;
	char	*content;
	int		len_content;

	i = -1;
	while (++i < cub->map_height)
	{
		content = (char *)((map_lines)->content);
		len_content = (int)ft_strlen(content);
		j = -1;
		while (++j < len_content)
		{
			if (!ft_strchr("01NSEW \n", content[j]))
				ft_exit("invalid map");
			cub->map[i][j] = content[j];
			if (ft_strchr("NSEW", content[j]))
				init_player(cub, i, j);
		}
		map_lines = (map_lines)->next;
	}
}

void	read_map(t_info *cub)
{
	char	*line;

	while (get_next_line(cub->fd, &line) > 0)
	{
		if (line[0] == '\0')
			break ;
		ft_lstadd_back(&cub->map_lines, ft_lstnew(ft_strdup(line)));
		free(line);
	}
	free(line);
	init_map(cub, cub->map_lines);
	store_map(cub, cub->map_lines);
	ft_lstclear(&cub->map_lines, free);
}
