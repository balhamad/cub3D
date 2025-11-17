/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balhamad <balhamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 11:53:43 by rabusala          #+#    #+#             */
/*   Updated: 2025/11/02 18:16:55 by balhamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*ptr;
	int			j;
	int			n;

	if (!s1 || !set)
		return (NULL);
	j = 0;
	n = ft_strlen(s1) - 1;
	while (s1[j] && ft_strchr(set, s1[j]))
		j++;
	if (j > n)
	{
		ptr = (char *)malloc(1);
		if (ptr == NULL)
			return (NULL);
		ptr[0] = '\0';
		return (ptr);
	}
	while ((n > j) && ft_strchr(set, s1[n]))
		n--;
	ptr = (char *)malloc(n - j + 2);
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, &s1[j], (n - j + 2));
	return (ptr);
}
