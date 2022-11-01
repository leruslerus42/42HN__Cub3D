/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paroonag <paroonag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 07:17:04 by paroonag          #+#    #+#             */
/*   Updated: 2022/07/30 11:52:16 by paroonag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	init_cub(t_info *cub, char *arg)
{
	ft_memset(cub, 0, sizeof(t_info));
	cub->ele.floor = -1;
	cub->ele.ceiling = -1;
	cub->ele.render_x = 1920;
	cub->ele.render_y = 1080;
	cub->width = cub->ele.render_x;
	cub->height = cub->ele.render_y;
	if (!ft_isformat(arg, ".cub"))
		ft_exit("invalid .cub");
	cub->fd = open(arg, O_RDONLY);
	if (cub->fd == -1)
		ft_exit("fail to open .cub");
}

int	main(int argc, char **argv)
{
	t_info	cub;

	if (argc != 2)
	{
		printf("use ./cub3D map.cub\n");
		return (0);
	}
	init_cub(&cub, argv[1]);
	read_elements(&cub);
	read_map(&cub);
	valid_map(&cub);
	set_cub(&cub);
	start_game(&cub);
	return (0);
}
