/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balhamad <balhamad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:05:45 by rabusala          #+#    #+#             */
/*   Updated: 2025/10/06 14:04:23 by balhamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)

{
	size_t			i;
	size_t			alen;
	unsigned int	slen;
	char			*ptr;

	i = 0;
	slen = ft_strlen(s);
	if (len == 0 || start >= slen)
		return (ft_strdup(""));
	if ((slen - start) < len)
		alen = slen - start;
	else
		alen = len;
	ptr = (char *)malloc(alen + 1);
	if (ptr == NULL)
		return (NULL);
	while (i < alen)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
// int main(void)
// {
// 	const char str[]="hello world";
// 	// printf("%s\n", str);
// 	printf("%s", ft_substr(str,9,0));
// 	return 0;
// }
