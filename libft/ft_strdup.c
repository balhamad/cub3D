/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balhamad <balhamad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:33:06 by rabusala          #+#    #+#             */
/*   Updated: 2025/10/08 19:01:37 by balhamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)

{
	int		i;
	int		j;
	char	*ptr;

	i = ft_strlen(s);
	j = 0;
	if(!s)
		return (NULL);
	ptr = (char *)malloc(i + 1);
	if (ptr == NULL)
		return (NULL);
	while (s[j])
	{
		ptr[j] = s[j];
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}
