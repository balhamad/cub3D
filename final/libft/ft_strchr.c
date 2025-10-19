/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabusala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 14:08:49 by rabusala          #+#    #+#             */
/*   Updated: 2024/08/31 14:24:06 by rabusala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int s)
{
	char			c;
	unsigned int	i;

	i = 0;
	c = (char) s;
	while (str[i])
	{
		if (str[i] == c)
			return ((char *)&str[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&str[i]);
	return (NULL);
}
/*int main(void)
{
	const char str[]= "hi my name ";
	char ch='i';
	printf("%s\n", ft_strchr(str,ch));
	printf("%s", strchr(str,ch));
	return 0;
}*/
