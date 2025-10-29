/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balhamad <balhamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:05:57 by balhamad          #+#    #+#             */
/*   Updated: 2025/10/29 15:32:40 by balhamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	init_elements(t_elements *el)
{
	(el)->map_size = 0;
	(el)->C = NULL;
	(el)->F = NULL;
	(el)->NO = NULL;
	(el)->WE = NULL;
	(el)->EA = NULL;
	(el)->SO = NULL;
	(el)->map = NULL;
	(el)->CB = 0;
	(el)->pl_flag = 0;
	(el)->copy_map = NULL;
	(el)->map_size = 0;
	el->textures = init_textures();
	if (!el->textures)
		return (-1);
	return (1);
}

t_textures	*init_textures(void)
{
	t_textures	*t;

	t = malloc(sizeof(t_textures));
	if (!t)
	{
		ft_printf("Error\nFailed to allocate memory for textures\n");
		return (NULL);
	}
	t->east = NULL;
	t->west = NULL;
	t->north = NULL;
	t->south = NULL;
	return (t);
}

int	init_window(t_elements *el)
{
	el->mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "HELL", false);
	if (!el->mlx)
	{
		ft_printf("Error\nFailed to initialize mlx\n");
		return (-1);
	}
	el->window = mlx_new_image(el->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!el->window)
	{
		ft_printf("Error\nFailed to create image\n");
		return (-1);
	}
	if (mlx_image_to_window(el->mlx, el->window, 0, 0) < 0)
	{
		ft_printf("Error\nFailed to put image to window\n");
		return (-1);
	}
	return (1);
}

int	main(int c, char **v)
{
	t_elements	elements;

	if (init_elements(&elements) == -1)
		return (1);
	if (c == 2)
	{
		if (check_extention(v[1]) == 1)
			return (1);
		if (check_lines(&elements, v[1]) == -1)
		{
			free_2d_array((&elements)->map);
			free_textures(&elements);
			free_elements(&elements);
			gnl_cleanup();
			return (1);
		}
		run(&elements);
		exit_all(&elements);
	}
	else
		write(2, "Error: wrong number of args\n", 28);
	gnl_cleanup();
	return (0);
}
