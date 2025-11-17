/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balhamad <balhamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 17:53:00 by balhamad          #+#    #+#             */
/*   Updated: 2025/11/03 17:24:07 by balhamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	find_max_len(t_elements *el)
{
	int	i;
	int	len;
	int	max_len;

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

void	create_grid(t_elements *el, int *i, int *j, int max_len)
{
	int	row_len;

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

int	copy_the_map(t_elements *el)
{
	int	i;
	int	max_len;
	int	j;

	i = 0;
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
		create_grid(el, &i, &j, max_len);
	}
	el->copy_map[i] = NULL;
	return (1);
}
