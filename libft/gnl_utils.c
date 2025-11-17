/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balhamad <balhamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 19:38:09 by balhamad          #+#    #+#             */
/*   Updated: 2025/11/02 21:47:57 by balhamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	char	**array_ptr;
	char	*array;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	array_ptr = get_static_array();
	array = read_line(fd, *array_ptr);
	*array_ptr = array;
	if (!array || !array[0])
		return (clean(array_ptr, NULL));
	return (slice_line(array_ptr));
}

void	gnl_cleanup(void)
{
	char	**array;

	array = get_static_array();
	if (*array)
	{
		free(*array);
		*array = NULL;
	}
}
