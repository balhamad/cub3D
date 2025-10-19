/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabusala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 11:53:43 by rabusala          #+#    #+#             */
/*   Updated: 2024/09/08 12:29:03 by rabusala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void	fill(char *ptr, char const *str, size_t len, size_t start)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		ptr[i] = str[start + i];
		i++;
	}
	ptr[len] = '\0';
}*/
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
/*int main()
{
	char const  *str= "lorem \n ipsum \t dolor \n sit \t amet";
	char const *set = " ";
	printf("%s", ft_strtrim(str, set));
	return 0;
}*/
