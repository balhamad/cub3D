/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabusala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 14:36:21 by rabusala          #+#    #+#             */
/*   Updated: 2024/08/31 14:42:51 by rabusala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int s)

{
	int	i;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == (unsigned char)s)
			return ((char *) &(str[i]));
		i--;
	}
	return (NULL);
}
/*int main(void)
{
	char str[]= "hi my name is fraqish ";
	char ch='a';
	printf("%s\n", ft_strrchr(str,ch));
	printf("%s\n", strrchr(str,ch));
	return 0;
}*/
