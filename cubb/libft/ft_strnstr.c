/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabusala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:10:09 by rabusala          #+#    #+#             */
/*   Updated: 2024/09/02 11:24:35 by rabusala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)

{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little [i] == '\0')
		return ((char *) & (big[i]));
	while ((i < len) && big[i])
	{
		while ((big[i + j] == little[j]) && little[j] && ((i + j) < len))
			j++;
		if (little[j] == '\0')
			return ((char *) & (big [i]));
		i++;
		j = 0;
	}
	return (0);
}
/*int main(void)
{
	const char	str[]= "hello world";
	const char	to_find[] = "";

	printf("%s\n \n", ft_strnstr(str, to_find,3));
	//printf("%d\n", strnstr(str, to_find,4));
	to_find = "";
	printf("%s\n", ft_strnstr(str, to_find));
	printf("%s\n", strnstr(str, to_find));
	to_find = "onj";
	printf("%s\n", ft_strnstr(str, to_find));
	printf("%s\n", strnstr(str, to_find));
	str = "hi my name is raneem";
	to_find = " ";
	printf("%s\n", ft_strnstr(str, to_find));
	printf("%s\n", strnstr(str, to_find));
}*/
