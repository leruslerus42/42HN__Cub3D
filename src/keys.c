/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paroonag <paroonag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 07:17:58 by paroonag          #+#    #+#             */
/*   Updated: 2022/07/30 11:52:15 by paroonag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	exit_game(void)
{
	ft_exit("close button is pressed");
	return (0);
}

int	handle(int key, t_info *cub)
{
	if (key == KEY_W)
		move_forward_backward(cub, &cub->player, cub->player.move_speed);
	if (key == KEY_S)
		move_forward_backward(cub, &cub->player, -cub->player.move_speed);
	if (key == KEY_A)
		move_left_right(cub, &cub->player, cub->player.move_speed);
	if (key == KEY_D)
		move_left_right(cub, &cub->player, -cub->player.move_speed);
	if (key == KEY_LEFT)
		rotate(&cub->player, -cub->player.rot_speed);
	if (key == KEY_RIGHT)
		rotate(&cub->player, cub->player.rot_speed);
	if (key == KEY_ESC)
		ft_exit("exit key is pressed");
	return (0);
}

void	start_game(t_info *cub)
{
	cub->img.ptr = mlx_new_image(cub->mlx, cub->width, cub->height);
	cub->img.data = (int *)mlx_get_data_addr(cub->img.ptr,
			&cub->img.bpp, &cub->img.size_line, &cub->img.endian);
	cub->win = mlx_new_window(cub->mlx, cub->width, cub->height, "cub3D");
	mlx_hook(cub->win, X_EVENT_KEY_PRESS, 0, &handle, cub);
	mlx_hook(cub->win, X_EVENT_KEY_EXIT, 0, &exit_game, cub);
	mlx_loop_hook(cub->mlx, &raycast, cub);
	mlx_loop(cub->mlx);
}
