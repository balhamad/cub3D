/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balhamad <balhamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 13:16:10 by balhamad          #+#    #+#             */
/*   Updated: 2025/10/21 18:29:22 by balhamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int check_mapline(t_elements *el,char *line)
{
	long unsigned int i;
	(void)el;
	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'N' && line[i] != 'S' && line[i] != 'E' && line[i] != 'W' && line[i] != ' ')
			return (-1);
		if (line[i] == 'N' || line[i] == 'E' || line[i] == 'S' || line[i] == 'W')
		{
			if(el->pl_flag == 0)
				el->pl_flag = 1;
			else
				return -1;
		}
		i++;
	}
	return (0);
}
void remove_nl(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	if (i > 0 && str[i - 1] == '\n')
		str[i - 1] = '\0';
}
int save_mapline(t_elements *el, char *line)
{
	char **map;
	int i;
	int j;

	i = 0;
	j = 0;
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
	free_2d_array(el->map);
	el->map = malloc(sizeof(char *) * (el->map_size + 2));
	if (!el->map)
		return (map_exit(&map, el));
	while (j < i + 1)
	{
		el->map[j] = ft_strdup(map[j]);
		if (!el->map[j])
			return (map_exit(&map, el));
		j++;
	}
	el->map[j] = NULL;
	el->map_size++;
	free_2d_array(map);
	return (0);
}

int skip_line(int fd, char **line)
{
	free(*line);
	while ((*line = get_next_line(fd)) != NULL)
	{
		remove_nl(*line);
		if (*line[0] != '\0')
		{
			free(*line);
			return (-1);
		}
		free(*line);
	}
	return (0);
}
int map_validation(t_elements *elements, int fd, int count, char *line)
{
	if (count != 6 || !line || line[0] == '\0')
	{
		if (line)
			free(line);
		return (-1);
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
		if (check_mapline(elements, line) == -1 || save_mapline(elements, line) == -1)
		{
			free(line);
			return (-1);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}
