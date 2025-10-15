/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabusala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 17:49:00 by rabusala          #+#    #+#             */
/*   Updated: 2024/09/15 17:54:28 by rabusala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*sor;
	char	*dst;
	size_t	i;

	i = n;
	sor = (char *)src;
	dst = (char *)dest;
	if (src == NULL && dest == NULL)
		return (NULL);
	if (dst < sor || dst >= (sor + n))
		ft_memcpy(dst, sor, n);
	else
	{
		while (i > 0)
		{
			dst[i - 1] = sor[i - 1];
			i--;
		}
	}
	return (dest);
}
