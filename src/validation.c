/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balhamad <balhamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:16:16 by balhamad          #+#    #+#             */
/*   Updated: 2025/10/29 16:39:57 by balhamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	check_extention(char *file)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	while (file[j])
	{
		if (file[j] == '.')
		{
			i = j;
			break ;
		}
		j++;
	}
	if (file[i + 1] != 'c' || file[i + 2] != 'u'
		|| file[i + 3] != 'b' || file[i + 4] != '\0')
	{
		write(2, "Error: wrong extention\n", 23);
		return (1);
	}
	return (0);
}

int	skip_spaces(char *line, int *i)
{
	while (line[*i] && (line[*i] == ' ' || line[*i] == '\t'))
		(*i)++;
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

int	count_comas(char *el_str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while ((el_str)[i])
	{
		if ((el_str)[i] == ',')
			count++;
		i++;
	}
	return (count);
}

int	check_num(int num, char *arr)
{
	int	numlen;
	int	num1;

	num1 = num;
	numlen = 0;
	while (num > 0)
	{
		num /= 10;
		numlen++;
	}
	if (num1 == 0)
		numlen = 1;
	if (numlen != (int)ft_strlen(arr))
		return (-1);
	if (num1 < 0 || num1 > 255)
		return (-1);
	return (0);
}

int	update_check_arr(char **arr, int *num)
{
	char	*tmp;
	int		ret;
	int		i;

	ret = 1;
	tmp = ft_strdup(*arr);
	if (!tmp)
		return (-1);
	free(*arr);
	*arr = ft_strtrim(tmp, " \t");
	free(tmp);
	if (!(*arr) || (*arr)[0] == '\0')
		return (-1);
	i = 0;
	while ((*arr)[i])
	{
		if (!ft_isdigit((*arr)[i]))
			ret = -1;
		i++;
	}
	*num = ft_atoi(*arr);
	if (check_num(*num,*arr) == -1)
		ret = -1;
	return (ret);
}

void	fill_rgb_colors(t_elements *el, int num, int sub_n, int *ind)
{
	if (sub_n == 5 && *ind == 0)
		el->FR = num;
	if (sub_n == 5 && *ind == 1)
		el->FG = num;
	if (sub_n == 5 && *ind == 2)
		el->FB = num;
	if (sub_n == 6 && *ind == 0)
		el->CR = num;
	if (sub_n == 6 && *ind == 1)
		el->CG = num;
	if (sub_n == 6 && *ind == 2)
		el->CB = num;
	*ind += 1;
}

void	free_fixed_arr(char **arr)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (arr[i])
			free(arr[i]);
		i++;
	}
	free(arr);
}
int	check_colors(t_elements *el, int sub_n, char *el_str)
{
	char	**arr;
	int		i;
	int		num;

	i = 0;
	num = -1;
	if (count_comas(el_str) != 2)
		return (-1);
	arr = ft_split(el_str, ',');
	if(!arr)
		return (-1);
	while (i < 3)
	{
		if (!arr[i])
		{
			free_fixed_arr(arr);
			return (-1);
		}
		if (update_check_arr(&arr[i], &num) == -1)
		{
			free_fixed_arr(arr);
			return (error_msg("Invalid RGB value\n"));
		}
		fill_rgb_colors(el, num, sub_n, &i);
	}
	free_2d_array(arr);
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

int	check_subline(char *sub, t_elements *el, char *line)
{
	int	i;

	i = 0;
	if (is_element(sub))
	{
		if ((is_element(sub) == 1))
			i = fill_element(el, sub, &(el->NO), line);
		else if ((is_element(sub) == 2))
			i = fill_element(el, sub, &(el->SO), line);
		else if ((is_element(sub) == 3))
			i = fill_element(el, sub, &(el->WE), line);
		else if ((is_element(sub) == 4))
			i = fill_element(el, sub, &(el->EA), line);
		else if ((is_element(sub) == 5))
			i = fill_element(el, sub, &(el->F), line);
		else if ((is_element(sub) == 6))
			i = fill_element(el, sub, &(el->C), line);
		if (i == -1)
			return (-1);
	}
	else
		return (-1);
	return (1);
}

int	parse_line(char *line, t_elements *el, int *count)
{
	int		i;
	int		s;
	char	*sub_line;

	i = 0;
	s = 0;
	skip_spaces(line, &i);
	if (line[i] == '\n' && *count < 6)
		return (0);
	s = i;
	while (line[i] && line[i] != 9 && line[i] != 32 && line[i] != '\n')
		i++;
	sub_line = ft_substr(line, s, i - s);
	if (!sub_line)
		return (error_msg("Malloc failed\n"));
	if (check_subline(sub_line, el, line + i) == -1)
	{
		free(sub_line);
		return (error_msg("Error in Elements\n"));
	}
	(*count)++;
	free(sub_line);
	return (0);
}

int	all_digits(char *line)
{
	long unsigned int	i;

	i = 0;
	while (i < ft_strlen(line) - 1)
	{
		if ((line[i] == '0' || line[i] == '1') || line[i] == ' ')
			i++;
		else
			return (-1);
	}
	return (0);
}

int	elements_loop(char **line, t_elements *elements, int *count, int fd)
{
	while (*line && *count <= 6)
	{
		if ((*line)[0] == '\0')
			break ;
		if ((*line)[0] == '\n')
		{
			free(*line);
			*line = get_next_line(fd);
			continue ;
		}
		if (all_digits((*line)) == 0)
			break ;
		if (parse_line((*line), elements, count) == -1)
		{
			close(fd);
			free(*line);
			return (-1);
		}
		free((*line));
		*line = get_next_line(fd);
	}
	return (0);
}

int	check_lines(t_elements *elements, char *file)
{
	char	*line;
	int		count;
	int		fd;

	count = 0;
	line = NULL;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	if (elements_loop(&line, elements, &count, fd) == -1)
	{
		close(fd);
		return (-1);
	}
	if (map_validation(elements, fd, count, line) == -1)
	{
		close(fd);
		return (-1);
	}
	if (solveable(elements) == -1)
	{
		close(fd);
		return (error_msg("Error in FloodFill\n"));
	}
	close(fd);
	return (0);
}
