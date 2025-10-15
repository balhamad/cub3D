/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabusala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:09:04 by rabusala          #+#    #+#             */
/*   Updated: 2024/09/03 13:34:39 by rabusala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)

{
	size_t	dlen;
	size_t	space;
	size_t	i;
	size_t	len;

	dlen = ft_strlen(dest);
	i = 0;
	if (size > dlen)
		space = size - dlen - 1;
	else
		space = 0;
	if (ft_strlen(src) >= space)
		len = space;
	else
		len = ft_strlen(src);
	if (size <= dlen)
		return (ft_strlen(src) + size);
	while (src[i] && i < len)
	{
		dest[dlen + i] = src[i];
		i++;
	}
	dest[dlen + i] = '\0';
	return (ft_strlen(src) + dlen);
}
/*int main(void)
{
char dest[]="a";
char src[]="lorem ipsum dolor sit amet";
printf("%ld\n",ft_strlcat(dest,src,0));
printf("%s",dest);
return (0);
}*/
