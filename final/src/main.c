/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balhamad <balhamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:05:57 by balhamad          #+#    #+#             */
/*   Updated: 2025/10/21 21:22:18 by balhamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void print(char **m)
{
	int i = 0;
	while (m && m[i])
	{
		printf("%s\n", m[i]);
		i++;
	}
}

int main(int c, char **v)
{
	t_elements elements;

	if (init_elements(&elements) == -1)
		return (1);

	if (c == 2)
	{
		if (check_extention(v[1]) == 1)
			return (1);
		if (check_lines(&elements, v[1]) == -1)
		{
			write(2, "ERROR\n", 6);
			free_2d_array((&elements)->map);
			free_textures(&elements);
			free_elements(&elements);
			gnl_cleanup();
			return (1);
		}
		run(&elements);
		free_2d_array(elements.map);
		free_textures(&elements);
		free(elements.textures);
		free_elements(&elements);
	}
	else
		write(2, "Error: wrong number of args\n", 28);
	gnl_cleanup();
	return (0);
}
