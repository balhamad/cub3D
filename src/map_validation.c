/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balhamad <balhamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 13:16:10 by balhamad          #+#    #+#             */
/*   Updated: 2025/11/03 13:34:44 by balhamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	check(t_elements *el, char *line)
{
	long unsigned int	i;

	i = 0;
	(void)el;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'N'
			&& line[i] != 'S' && line[i] != 'E'
			&& line[i] != 'W' && line[i] != ' ')
			return (-1);
		if (line[i] == 'N' || line[i] == 'E'
			|| line[i] == 'S' || line[i] == 'W')
		{
			if (el->pl_flag == 0)
				el->pl_flag = 1;
			else
				return (-1);
		}
		i++;
	}
	return (0);
}

int	make_map(t_elements *el, char **map, int i)
{
	int	j;

	j = 0;
	free_2d_array(el->map);
	el->map = malloc(sizeof(char *) * (el->map_size + 2));
	if (!el->map)
		return (-1);
	while (j < i + 1)
	{
		el->map[j] = ft_strdup(map[j]);
		if (!el->map[j])
			return (-1);
		j++;
	}
	el->map[j] = NULL;
	el->map_size++;
	return (0);
}

int	save(t_elements *el, char *line)
{
	char	**map;
	int		i;

	i = 0;
	map = malloc(sizeof(char *) * (el->map_size + 2));
	if (!map)
		return (-1);
	while (i < el->map_size)
	{
		map[i] = ft_strdup(el->map[i]);
		if (!map[i])
			return (map_exit(&map, el));
		i++;
	}
	map[i] = ft_strdup(line);
	if (!map[i])
		return (map_exit(&map, el));
	map[i + 1] = NULL;
	if (make_map(el, map, i) == -1)
		return (map_exit(&map, el));
	free_2d_array(map);
	return (0);
}

int	skip_line(int fd, char **line)
{
	free(*line);
	*line = get_next_line(fd);
	while (*line != NULL)
	{
		remove_nl(*line);
		if (*line[0] != '\0')
		{
			free(*line);
			return (error_msg("Error in Map\n"));
		}
		free(*line);
		*line = get_next_line(fd);
	}
	return (0);
}

int	map_validation(t_elements *elements, int fd, int count, char *line)
{
	if (count != 6 || !line || line[0] == '\0')
	{
		if (line)
			free(line);
		return (error_msg("Error in file\n"));
	}
	while (line && line[0] == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	while (line != NULL)
	{
		if (line[0] == '\n')
			return (skip_line(fd, &line));
		remove_nl(line);
		if (check(elements, line) == -1 || save(elements, line) == -1)
		{
			free(line);
			return (error_msg("Error in map\n"));
		}
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}
