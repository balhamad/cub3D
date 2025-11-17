/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balhamad <balhamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 19:38:09 by balhamad          #+#    #+#             */
/*   Updated: 2025/11/02 21:48:10 by balhamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*clean(char **array, char *ss)
{
	if (*array)
	{
		free(*array);
		*array = NULL;
	}
	if (ss)
		free(ss);
	return (NULL);
}

char	*read_line(int fd, char *array)
{
	char	*buf;
	char	*temp;
	int		bytes;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	if (!array)
		array = ft_strdup("");
	bytes = read(fd, buf, BUFFER_SIZE);
	while (bytes > 0)
	{
		buf[bytes] = '\0';
		temp = array;
		array = ft_strjoin(array, buf);
		free(temp);
		if (ft_strchr(array, '\n'))
			break ;
		bytes = read(fd, buf, BUFFER_SIZE);
	}
	if (bytes == -1)
		return (clean(&array, buf));
	free(buf);
	return (array);
}

char	**get_static_array(void)
{
	static char	*array = NULL;

	return (&array);
}

char	*slice_line(char **array)
{
	int		len;
	char	*line;
	char	*temp;

	if (!*array || !**array)
		return (NULL);
	len = 0;
	while ((*array)[len] && (*array)[len] != '\n')
		len++;
	line = ft_substr(*array, 0, len + ((*array)[len] == '\n'));
	if (!line)
		return (clean(array, NULL));
	if ((*array)[len] == '\0')
	{
		free(*array);
		*array = NULL;
	}
	else
	{
		temp = *array;
		*array = ft_substr(*array, len + 1, ft_strlen(*array) - len - 1);
		free(temp);
	}
	return (line);
}
