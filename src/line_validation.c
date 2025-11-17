/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balhamad <balhamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 16:37:23 by balhamad          #+#    #+#             */
/*   Updated: 2025/11/02 21:19:16 by balhamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	check_subline(char *sub, t_elements *el, char *line)
{
	int	i;

	i = 0;
	if (is_element(sub))
	{
		if ((is_element(sub) == 1))
			i = fill_element(el, sub, &(el->no), line);
		else if ((is_element(sub) == 2))
			i = fill_element(el, sub, &(el->so), line);
		else if ((is_element(sub) == 3))
			i = fill_element(el, sub, &(el->we), line);
		else if ((is_element(sub) == 4))
			i = fill_element(el, sub, &(el->ea), line);
		else if ((is_element(sub) == 5))
			i = fill_element(el, sub, &(el->f), line);
		else if ((is_element(sub) == 6))
			i = fill_element(el, sub, &(el->c), line);
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
	if (elements_loop(&line, elements, &count, fd) == -1
		|| map_validation(elements, fd, count, line) == -1)
	{
		gnl_cleanup();
		close(fd);
		return (-1);
	}
	if (solveable(elements) == -1)
	{
		gnl_cleanup();
		close(fd);
		return (error_msg("Error in FloodFill\n"));
	}
	close(fd);
	return (0);
}
