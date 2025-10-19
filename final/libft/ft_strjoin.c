/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabusala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:52:59 by rabusala          #+#    #+#             */
/*   Updated: 2024/09/05 11:02:41 by rabusala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)

{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (ptr == NULL)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		ptr[i] = *s2++;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/*int main(void)
{
	const char str[]="hello ";
	const char str2[]="world";
	printf("%s\n", str);
	printf("%s\n", str2);
	printf("%s", ft_strjoin(str,str2));
	return 0;
}
*/
