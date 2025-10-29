/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabusala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:24:42 by rabusala          #+#    #+#             */
/*   Updated: 2024/09/11 12:21:13 by rabusala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	colen(char *s, char c)
{
	size_t	end;

	end = 0;
	while (s[end] && s[end] != c)
		end++;
	return (end);
}

static size_t	count(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{	
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

char	*mallocfill(char const *s, char c)

{
	char	*ptr;
	size_t	plen;

	plen = colen((char *)s, c);
	ptr = (char *)malloc (plen + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s, (plen + 1));
	ptr[plen] = '\0';
	return (ptr);
}

void	freearr(char **arr)
{
	char	**temp;

	temp = arr;
	while (*temp)
	{
		free (*temp);
		temp++;
	}
	free (arr);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	plen;
	size_t	len;
	char	**arr;

	i = 0;
	len = count(s, c);
	arr = (char **)malloc((len + 1) * sizeof(char *));
	if (!arr || !s)
		return (NULL);
	while (i < len)
	{
		while (*s == c)
			s++;
		plen = colen((char *)s, c);
		arr[i] = mallocfill(s, c);
		if (!arr[i++])
		{
			freearr(arr);
			return (NULL);
		}
		s += plen;
	}
	arr[i] = NULL;
	return (arr);
}	
