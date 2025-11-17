/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balhamad <balhamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 17:41:16 by balhamad          #+#    #+#             */
/*   Updated: 2025/11/02 17:51:40 by balhamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	move_forword(t_elements *el)
{
	double	new_x;
	double	new_y;

	new_x = el->pos_x;
	new_y = el->pos_y;
	new_x += el->dir_x * MOVE_SPEED;
	new_y += el->dir_y * MOVE_SPEED;
	if (!is_wall(el, el->pos_x, new_y))
		el->pos_y = new_y;
	if (!is_wall(el, new_x, el->pos_y))
		el->pos_x = new_x;
}

void	move_back(t_elements *el)
{
	double	new_x;
	double	new_y;

	new_x = el->pos_x;
	new_y = el->pos_y;
	new_x -= el->dir_x * MOVE_SPEED;
	new_y -= el->dir_y * MOVE_SPEED;
	if (!is_wall(el, el->pos_x, new_y))
		el->pos_y = new_y;
	if (!is_wall(el, new_x, el->pos_y))
		el->pos_x = new_x;
}

void	move_right(t_elements *el)
{
	double	new_x;
	double	new_y;

	new_x = el->pos_x;
	new_y = el->pos_y;
	new_x += el->plane_x * MOVE_SPEED;
	new_y += el->plane_y * MOVE_SPEED;
	if (!is_wall(el, el->pos_x, new_y))
		el->pos_y = new_y;
	if (!is_wall(el, new_x, el->pos_y))
		el->pos_x = new_x;
}

void	move_left(t_elements *el)
{
	double	new_x;
	double	new_y;

	new_x = el->pos_x;
	new_y = el->pos_y;
	new_x -= el->plane_x * MOVE_SPEED;
	new_y -= el->plane_y * MOVE_SPEED;
	if (!is_wall(el, el->pos_x, new_y))
		el->pos_y = new_y;
	if (!is_wall(el, new_x, el->pos_y))
		el->pos_x = new_x;
}

void	rotate(t_elements *el)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rot;

	old_dir_x = el->dir_x;
	old_plane_x = el->plane_x;
	rot = 0.0;
	if (mlx_is_key_down(el->mlx, MLX_KEY_LEFT))
		rot -= ROT_SPEED;
	if (mlx_is_key_down(el->mlx, MLX_KEY_RIGHT))
		rot += ROT_SPEED;
	if (rot != 0.0)
	{
		el->dir_x = el->dir_x * cos(rot) - el->dir_y * sin(rot);
		el->dir_y = old_dir_x * sin(rot) + el->dir_y * cos(rot);
		el->plane_x = el->plane_x * cos(rot) - el->plane_y * sin(rot);
		el->plane_y = old_plane_x * sin(rot) + el->plane_y * cos(rot);
	}
}
