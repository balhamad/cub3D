/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balhamad <balhamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 12:55:03 by balhamad          #+#    #+#             */
/*   Updated: 2025/10/21 18:24:09 by balhamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int get_pos(t_elements *el)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (el->map[i])
	{
		j = 0;
		while (el->map[i][j])
		{
			if (el->map[i][j] == 'N' || el->map[i][j] == 'W' || el->map[i][j] == 'E' || el->map[i][j] == 'S')
			{
				el->map_x = j;
				el->map_y = i;
				el->pos_x = j + 0.5;
				el->pos_y = i + 0.5;
				decide_pos(el, el->map[i][j]);
				el->map[i][j] = '0';
				return (1);
			}
			j++;
		}
		i++;
	}
	return (-1);
}

int copy_the_map(t_elements *el)
{
	int i = 0;
	el->copy_map = malloc(sizeof(char *) * (el->map_size + 1));
	if(!el->copy_map)
	{
		free_2d_array(el->copy_map);
		return (-1);
	}
	while (i < el->map_size)
	{
		el->copy_map[i] = ft_strdup(el->map[i]);
		if (!el->copy_map[i])
		{
			free_2d_array(el->copy_map);
			return (-1);
		}
		i++;
	}
	el->copy_map[i] = NULL;
	return 1;
}

void flood_fill(t_elements *info, int x, int y)
{
	if (y >= info->map_size || y < 0)
	{
		info->exit_flag = 1;
		return;
	}
	if (!info->copy_map[y])
	{
		info->exit_flag = 1;
		return;
	}
	if (x < 0 || x >= (int)ft_strlen(info->copy_map[y]))
	{
		info->exit_flag = 1;
		return;
	}
	if ((info->copy_map[y][x] == '0' && (y + 1 >= info->map_size || !info->copy_map[y + 1][x] || y - 1 < 0 || x - 1 < 0 || !info->copy_map[y - 1][x] || x + 1 >= (int)ft_strlen(info->copy_map[y]))))
	{
		info->exit_flag = 1;
		return;
	}
	if (info->copy_map[y][x] == '1')
		return;
	if (info->copy_map[y][x] == ' ')
		info->exit_flag = 1;
	info->copy_map[y][x] = '1';
	flood_fill(info, x - 1, y);
	flood_fill(info, x + 1, y);
	flood_fill(info, x, y - 1);
	flood_fill(info, x, y + 1);
	flood_fill(info, x - 1, y + 1);
	flood_fill(info, x - 1, y - 1);
	flood_fill(info, x + 1, y - 1);
	flood_fill(info, x + 1, y + 1);
}

int solveable(t_elements *info)
{
	int pl_flag = 0;
	if (copy_the_map(info) == -1)
		return (-1);
	if(get_pos(info) == 1)
		pl_flag++;
	else
	{
		free_2d_array(info->copy_map);
		return (-1);
	}
	info->exit_flag = 0;
	flood_fill(info, info->map_x, info->map_y);
	if (info->exit_flag == 1)
	{
		free_2d_array(info->copy_map);
		return (-1);
	}
	free_2d_array(info->copy_map);
	return (0);
}
