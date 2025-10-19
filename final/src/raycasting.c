/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bushra <bushra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 15:50:26 by balhamad          #+#    #+#             */
/*   Updated: 2025/10/16 13:25:50 by bushra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void ini_ray_var(t_elements *el, int x)
{
	el->camera_x = 2.0 * x / SCREEN_WIDTH * 1.0 - 1.0;
	el->raydir_x = el->dir_x + el->plane_x * el->camera_x;
	el->raydir_y = el->dir_y + el->plane_y * el->camera_x;
	el->map_x = (int)el->pos_x;
	el->map_y = (int)el->pos_y;
	el->delta_dist_x = fabs(1 / el->raydir_x);
	el->delta_dist_y = fabs(1 / el->raydir_y);
}
void find_side_dist(t_elements *el)
{
	if (el->raydir_x < 0)
	{
		el->step_x = -1;
		el->side_dist_x = (el->pos_x - el->map_x) * el->delta_dist_x;
	}
	else
	{
		el->step_x = 1;
		el->side_dist_x = (el->map_x + 1.0 - el->pos_x) * el->delta_dist_x;
	}
	if (el->raydir_y < 0)
	{
		el->step_y = -1;
		el->side_dist_y = (el->pos_y - el->map_y) * el->delta_dist_y;
	}
	else
	{
		el->step_y = 1;
		el->side_dist_y = (el->map_y + 1.0 - el->pos_y) * el->delta_dist_y;
	}
}
int start_dda(t_elements *el)
{
	int hit;
	int side;

	hit = 0;
	while (hit == 0)
	{
		if (el->side_dist_x < el->side_dist_y)
		{
			el->side_dist_x += el->delta_dist_x;
			el->map_x += el->step_x;
			side = 0;
		}
		else
		{
			el->side_dist_y += el->delta_dist_y;
			el->map_y += el->step_y;
			side = 1;
		}
		if (el->map[el->map_y][el->map_x] == '1')
			hit = 1;
	}
	return (side);
}
void prep_for_walls(t_elements *el)
{
	if (el->side == 0)
		el->truewalldist = (el->map_x - el->pos_x + (1 - el->step_x) / 2) / el->raydir_x;
	else
		el->truewalldist = (el->map_y - el->pos_y + (1 - el->step_y) / 2) / el->raydir_y;
	if(el->truewalldist == 0)
		el->truewalldist = 0.01;
	el->wall_hight = (int)(SCREEN_HEIGHT / el->truewalldist);
	el->wall_start = -el->wall_hight / 2 + SCREEN_HEIGHT / 2;
	el->wall_end = el->wall_hight / 2 + SCREEN_HEIGHT / 2;
	if (el->wall_start < 0)
		el->wall_start = 0;
	if (el->wall_end >= SCREEN_HEIGHT)
		el->wall_end = SCREEN_HEIGHT - 1;
}