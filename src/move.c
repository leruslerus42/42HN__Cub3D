/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paroonag <paroonag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 07:16:11 by paroonag          #+#    #+#             */
/*   Updated: 2022/07/30 11:52:14 by paroonag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	move_forward_backward(t_info *cub, t_player *player, double move_speed)
{
	char	x;
	char	y;

	x = cub->map[(int)player->pos_y]
	[(int)(player->pos_x + player->dir_x * move_speed)];
	y = cub->map[(int)(player->pos_y + player->dir_y * move_speed)]
	[(int)player->pos_x];
	if (x != WALL)
		player->pos_x += player->dir_x * move_speed;
	if (y != WALL)
		player->pos_y += player->dir_y * move_speed;
}

void	move_left_right(t_info *cub, t_player *player, double move_speed)
{
	char	x;
	char	y;

	x = cub->map[(int)player->pos_y]
	[(int)(player->pos_x + player->dir_y * move_speed)];
	y = cub->map[(int)(player->pos_y + -player->dir_x * move_speed)]
	[(int)player->pos_x];
	if (x != WALL)
		player->pos_x += player->dir_y * move_speed;
	if (y != WALL)
		player->pos_y += -player->dir_x * move_speed;
}

void	rotate(t_player *player, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(rot_speed)
		- player->dir_y * sin(rot_speed);
	player->dir_y = old_dir_x * sin(rot_speed)
		+ player->dir_y * cos(rot_speed);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(rot_speed)
		- player->plane_y * sin(rot_speed);
	player->plane_y = old_plane_x * sin(rot_speed)
		+ player->plane_y * cos(rot_speed);
}
