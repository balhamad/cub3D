// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   get_next_line.c                                    :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: balhamad <balhamad@student.42amman.com>    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/11/04 17:22:22 by rabusala          #+#    #+#             */
// /*   Updated: 2025/01/29 15:37:22 by balhamad         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "libft.h"

size_t line_length(char *str)
{
	size_t i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

char *clean(char **array, char *ss)
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

char *read_1ine(int fd, char *array)
{
	char *buf;
	char *temp;
	int bytes_read;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	if (!array)
		array = ft_strdup("");
	bytes_read = read(fd, buf, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buf[bytes_read] = '\0';
		temp = array;
		array = ft_strjoin(array, buf);
		free(temp);
		if (ft_strchr(array, '\n'))
			break;
		bytes_read = read(fd, buf, BUFFER_SIZE);
	}
	if (bytes_read == -1)
		return (clean(&array, buf));
	free(buf);
	return (array);
}

char **get_static_array(void)
{
	static char *array = NULL;
	return (&array);
}

char *slice_line(char **array)
{
	int len;
	char *line;
	char *temp;

	len = line_length(*array);
	if ((*array)[len] == '\n')
		line = ft_substr(*array, 0, len + 1);
	else
		line = ft_substr(*array, 0, len);
	if (line_length(*array) != ft_strlen(*array))
	{
		temp = *array;
		*array = ft_substr(*array, len + 1, ft_strlen(*array) - len);
		free(temp);
	}
	else
		clean(array, NULL);
	return (line);
}

char *get_next_line(int fd)
{
	char **array_ptr;
	char *array;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	array_ptr = get_static_array();
	array = read_1ine(fd, *array_ptr);
	*array_ptr = array;
	if (!array || array[0] == '\0')
		return (clean(array_ptr, NULL));
	return (slice_line(array_ptr));
}

void gnl_cleanup(void)
{
	char **array = get_static_array();
	if (*array)
	{
		free(*array);
		*array = NULL;
	}
}
// int main()
// {
// 	int fd = open("text.txt", O_RDONLY);
// 	char *line = "p";
// 	// line = get_next_line(fd);
// 	while (line)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		free(line);
// 	}
// 	return 1;
// }