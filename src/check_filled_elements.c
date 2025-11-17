/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_filled_elements.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balhamad <balhamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 16:40:27 by balhamad          #+#    #+#             */
/*   Updated: 2025/11/03 13:36:53 by balhamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	skip_spaces(char *line, int *i)
{
	while (line[*i] && (line[*i] == ' ' || line[*i] == '\t'))
		(*i)++;
	return (0);
}

int	check_texture(t_elements *el, int sub_n, char *el_str)
{
	mlx_texture_t	*tex;

	tex = mlx_load_png(el_str);
	if (!tex)
	{
		free_textures(el);
		return (-1);
	}
	if (sub_n == 1)
		el->textures->north = tex;
	else if (sub_n == 2)
		el->textures->south = tex;
	else if (sub_n == 3)
		el->textures->west = tex;
	else if (sub_n == 4)
		el->textures->east = tex;
	return (0);
}

int	is_element(char *sub)
{
	if (ft_strcmp(sub, "NO") == 0)
		return (1);
	else if (ft_strcmp(sub, "SO") == 0)
		return (2);
	else if (ft_strcmp(sub, "WE") == 0)
		return (3);
	else if (ft_strcmp(sub, "EA") == 0)
		return (4);
	else if (ft_strcmp(sub, "F") == 0)
		return (5);
	else if (ft_strcmp(sub, "C") == 0)
		return (6);
	else
		return (0);
}

int	check_filled_element(t_elements *el, char *sub, char **el_str)
{
	int		sub_n;
	char	*str;

	str = ft_strtrim(*el_str, " \t");
	if (!str)
		return (-1);
	sub_n = is_element(sub);
	if (sub_n == 1 || sub_n == 2 || sub_n == 3 || sub_n == 4)
	{
		if (check_texture(el, sub_n, str) == -1)
		{
			free(str);
			return (-1);
		}
	}
	if (sub_n == 5 || sub_n == 6)
	{
		if (check_colors(el, sub_n, str) == -1)
		{
			free(str);
			return (-1);
		}
	}
	free(str);
	return (0);
}

int	fill_element(t_elements *el, char *sub, char **el_str, char *line)
{
	int	i;
	int	s;

	i = 0;
	s = 0;
	if (*el_str != NULL)
		return (-1);
	skip_spaces(line, &i);
	s = i;
	while (line[i] && line[i] != '\n')
		i++;
	*el_str = ft_substr(line, s, i - s);
	if (*el_str == NULL || **el_str == '\0')
		return (-1);
	if (check_filled_element(el, sub, el_str) == -1)
		return (-1);
	return (1);
}
