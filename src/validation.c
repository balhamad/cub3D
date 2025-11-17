/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balhamad <balhamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:16:16 by balhamad          #+#    #+#             */
/*   Updated: 2025/11/02 17:51:56 by balhamad         ###   ########.fr       */
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

void	free_fixed_arr(char **arr)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (arr[i])
			free(arr[i]);
		i++;
	}
	free(arr);
}

void	remove_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i > 0 && str[i - 1] == '\n')
		str[i - 1] = '\0';
}
