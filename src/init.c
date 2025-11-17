/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balhamad <balhamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:31:31 by balhamad          #+#    #+#             */
/*   Updated: 2025/11/02 17:51:14 by balhamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	is_wall(t_elements *el, double x, double y)
{
	int		map_x;
	int		map_y;
	double	margin;

	margin = 0.1;
	if (x < 0 || y < 0 || y >= SCREEN_HEIGHT || x >= SCREEN_WIDTH)
		return (1);
	map_x = (int)(x - margin);
	map_y = (int)(y - margin);
	if (el->map[map_y][map_x] == '1')
		return (1);
	map_x = (int)(x + margin);
	map_y = (int)(y - margin);
	if (el->map[map_y][map_x] == '1')
		return (1);
	map_x = (int)(x - margin);
	map_y = (int)(y + margin);
	if (el->map[map_y][map_x] == '1')
		return (1);
	map_x = (int)(x + margin);
	map_y = (int)(y + margin);
	if (el->map[map_y][map_x] == '1')
		return (1);
	return (0);
}
