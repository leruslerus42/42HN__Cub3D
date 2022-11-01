/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paroonag <paroonag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 04:25:50 by paroonag          #+#    #+#             */
/*   Updated: 2022/07/30 11:52:13 by paroonag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	set_background(t_info *cub)
{
	int	x;
	int	y;

	y = -1;
	while (++y < cub->height)
	{
		x = -1;
		while (++x < cub->width)
		{
			if (y > cub->height / 2)
				cub->buf[y][x] = cub->ele.floor;
			else
				cub->buf[y][x] = cub->ele.ceiling;
		}
	}
}

void	wall_raycast(t_info *cub)
{
	int	x;

	x = -1;
	while (++x < cub->width)
	{
		init_ray(cub, &cub->player, &cub->ray, x);
		calc_sidedist_step(&cub->player, &cub->ray);
		apply_dda(cub, &cub->ray);
		distance_wall(&cub->player, &cub->ray);
		height_wall(cub, &cub->ray);
		te_x_wall(&cub->player, &cub->ray);
		te_y_wall(cub, &cub->ray, x);
		cub->z_buf[x] = cub->ray.perp_wall_dist;
	}
}

void	display(t_info *cub)
{
	int	x;
	int	y;

	y = -1;
	while (++y < cub->height)
	{
		x = -1;
		while (++x < cub->width)
			cub->img.data[cub->width * y + x] = cub->buf[y][x];
	}
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img.ptr, 0, 0);
}

int	raycast(t_info *cub)
{
	set_background(cub);
	wall_raycast(cub);
	display(cub);
	return (0);
}
