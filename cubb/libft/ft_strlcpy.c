/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabusala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 13:20:51 by rabusala          #+#    #+#             */
/*   Updated: 2024/08/31 14:08:33 by rabusala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = ft_strlen(src);
	j = 0;
	if (size == 0)
		return (i);
	len = size - 1;
	while (src[j] && (j < (len)))
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (i);
}
/*int main(void)
{
int x=1;
char dest[x];
char src[]="Hello";
printf("%ld\n",ft_strlcpy(dest,src,x));
printf("%s",dest);
return (0);
}*/
