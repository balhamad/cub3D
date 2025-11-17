/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balhamad <balhamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 13:09:56 by balhamad          #+#    #+#             */
/*   Updated: 2025/11/02 21:33:53 by balhamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	exit_all(void *param)
{
	t_elements	*elements;

	elements = (t_elements *)param;
	free_2d_array(elements->map);
	free_textures(elements);
	free(elements->textures);
	free_elements(elements);
	if (elements->mlx)
	{
		mlx_close_window(elements->mlx);
		mlx_terminate(elements->mlx);
	}
	gnl_cleanup();
	exit(0);
}

void	free_elements(t_elements *el)
{
	if (!el)
		return ;
	if (el->c)
		free(el->c);
	if (el->f)
		free(el->f);
	if (el->no)
		free(el->no);
	if (el->we)
		free(el->we);
	if (el->ea)
		free(el->ea);
	if (el->so)
		free(el->so);
}

void	free_2d_array(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	map_exit(char ***map, t_elements *el)
{
	(void)el;
	if (*map)
		free_2d_array(*map);
	return (-1);
}

void	free_textures(t_elements *el)
{
	if (!el || !el->textures)
		return ;
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
