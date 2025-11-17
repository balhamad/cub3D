/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color_elements.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balhamad <balhamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 16:45:26 by balhamad          #+#    #+#             */
/*   Updated: 2025/11/03 17:22:10 by balhamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
		el->fr = num;
	if (sub_n == 5 && *ind == 1)
		el->fg = num;
	if (sub_n == 5 && *ind == 2)
		el->fb = num;
	if (sub_n == 6 && *ind == 0)
		el->cr = num;
	if (sub_n == 6 && *ind == 1)
		el->cg = num;
	if (sub_n == 6 && *ind == 2)
		el->cb = num;
	*ind += 1;
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
	if (!arr)
		return (-1);
	while (i < 3)
	{
		if (!arr[i] || update_check_arr(&arr[i], &num) == -1)
		{
			free_fixed_arr(arr);
			return (error_msg("Invalid RGB value\n"));
		}
		fill_rgb_colors(el, num, sub_n, &i);
	}
	free_2d_array(arr);
	return (0);
}
