/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balhamad <balhamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 12:55:03 by balhamad          #+#    #+#             */
/*   Updated: 2025/10/29 15:32:23 by balhamad         ###   ########.fr       */
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
int find_max_len(t_elements *el)
{
	int i;
	int len;
	int max_len;
	i = 0;
	max_len = 0;
	while (i < el->map_size)
	{
		len = (int)ft_strlen(el->map[i]);
		if (len > max_len)
			max_len = len;
		i++;
	}
	return (max_len);
}
void create_grid(t_elements *el,int *i,int *j,int max_len)
{
	int row_len;
	
	(*j) = 0;
	row_len = ft_strlen(el->map[*i]);
	while (*j < max_len)
	{
		if (*j < row_len)
		{
			el->copy_map[*i][*j] = el->map[*i][*j];
		}
		else
			el->copy_map[*i][*j] = 'X';
		(*j)++;
	}
	el->copy_map[*i][max_len] = '\0';
	(*i)++;
}
int copy_the_map(t_elements *el)
{
    int	i;
    int	max_len;
	int	len;
	int	j;

	i = 0;
	len = 0;
	max_len = find_max_len(el);
    el->copy_map = malloc(sizeof(char *) * (el->map_size + 1));
    if (!el->copy_map)
        return (-1);
    while (i < el->map_size)
    {
        el->copy_map[i] = malloc(max_len + 1);
        if (!el->copy_map[i])
        {
            free_2d_array(el->copy_map);
            return (-1);
        }
		create_grid(el,&i,&j,max_len);
    }
    el->copy_map[i] = NULL;
    return (1);
}
void flood_fill(t_elements *info, int x, int y)
{
	if ( y >= info->map_size || y < 0 || !info->copy_map[y])
	{
		info->exit_flag = 1;
		return;
	}
	if ( x < 0 || x >= (int)ft_strlen(info->copy_map[y]) || info->copy_map[y][x] == 'X')
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
