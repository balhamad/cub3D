/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raneem <raneem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 13:09:56 by balhamad          #+#    #+#             */
/*   Updated: 2025/10/13 18:11:31 by raneem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void exit_all(t_elements *elements)
{
	free_2d_array(elements->map);
	free_textures(elements);
	free(elements->textures);
	free_elements(elements);
	mlx_close_window(elements->mlx);
	mlx_terminate(elements->mlx);
	gnl_cleanup();
	exit(0);
}
void free_elements(t_elements *el)
{
	if (!el)
		return;
	if (el->C)
		free(el->C);
	if (el->F)
		free(el->F);
	if (el->NO)
		free(el->NO);
	if (el->WE)
		free(el->WE);
	if (el->EA)
		free(el->EA);
	if (el->SO)
		free(el->SO);
	// free(el);
}

void free_2d_array(char **arr)
{
	if(!arr)
		return;
	int i;

	if (!arr)
		return;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int map_exit(char ***map,t_elements *el)
{
	(void)el;
	if (*map)
		free_2d_array(*map);
	// if(el->map)
	// 	free_2d_array(el->map);
	return (-1);
}

void free_textures(t_elements *el)
{
	if (el->textures->north)
		mlx_delete_texture(el->textures->north);
	if (el->textures->south)
		mlx_delete_texture(el->textures->south);
	if (el->textures->west)
		mlx_delete_texture(el->textures->west);
	if (el->textures->east)
		mlx_delete_texture(el->textures->east);
	free(el->textures);
	el->textures = NULL;
}