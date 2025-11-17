/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balhamad <balhamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 17:39:24 by balhamad          #+#    #+#             */
/*   Updated: 2025/11/02 17:52:23 by balhamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	cursor_hook(double xpos, double ypos, void *param)
{
	t_elements		*el;
	static double	last_x = -1;
	double			old_dir_x;
	double			old_plane_x;
	double			dx;

	(void)ypos;
	el = (t_elements *)param;
	old_dir_x = el->dir_x;
	old_plane_x = el->plane_x;
	if (last_x < 0)
		last_x = xpos;
	dx = xpos - last_x;
	el->angle = dx * MOUSE_SENSITIVITY;
	el->cos_a = cos(el->angle);
	el->sin_a = sin(el->angle);
	el->dir_x = el->dir_x * el->cos_a - el->dir_y * el->sin_a;
	el->dir_y = old_dir_x * el->sin_a + el->dir_y * el->cos_a;
	el->plane_x = el->plane_x * el->cos_a - el->plane_y * el->sin_a;
	el->plane_y = old_plane_x * el->sin_a + el->plane_y * el->cos_a;
	last_x = xpos;
}

void	keyhook(void *param)
{
	t_elements	*el;

	el = (t_elements *)param;
	if (mlx_is_key_down(el->mlx, MLX_KEY_ESCAPE))
		exit_all(el);
	if (mlx_is_key_down(el->mlx, MLX_KEY_W))
		move_forword(el);
	if (mlx_is_key_down(el->mlx, MLX_KEY_S))
		move_back(el);
	if (mlx_is_key_down(el->mlx, MLX_KEY_D))
		move_right(el);
	if (mlx_is_key_down(el->mlx, MLX_KEY_A))
		move_left(el);
	rotate(el);
}

void	render(void *param)
{
	t_elements	*el;
	int			x;

	x = 0;
	el = (t_elements *)param;
	while (x < SCREEN_WIDTH)
	{
		ini_ray_var(el, x);
		find_side_dist(el);
		el->side = start_dda(el);
		prep_for_walls(el);
		ceiling_floor(el, x);
		draw_textured_wall(el, x);
		x++;
	}
}

void	run(t_elements *el)
{
	int32_t	mouse_x;
	int32_t	mouse_y;

	init_window(el);
	mlx_get_mouse_pos(el->mlx, &mouse_x, &mouse_y);
	mlx_close_hook(el->mlx, exit_all, el);
	mlx_cursor_hook(el->mlx, cursor_hook, el);
	mlx_loop_hook(el->mlx, keyhook, el);
	mlx_loop_hook(el->mlx, render, el);
	mlx_loop(el->mlx);
	mlx_terminate(el->mlx);
}

void	move_pos(mlx_key_data_t keydata, t_elements *el)
{
	if (keydata.key == MLX_KEY_W)
		move_forword(el);
	else if (keydata.key == MLX_KEY_S)
		move_back(el);
	else if (keydata.key == MLX_KEY_D)
		move_right(el);
	else if (keydata.key == MLX_KEY_A)
		move_left(el);
}
