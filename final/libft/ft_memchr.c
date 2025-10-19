/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabusala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:08:39 by rabusala          #+#    #+#             */
/*   Updated: 2024/09/01 17:14:44 by rabusala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)

{
	size_t				i;
	const unsigned char	*str;

	i = 0;
	str = s;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *) & (str[i]));
		i++;
	}
	return (NULL);
}
/*int main(void)
{
	const char str[]="hello world";
	char *result = ft_memchr(str,'o',7);
	printf("%s",result);
	return 0;
}*/
