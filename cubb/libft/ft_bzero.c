/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabusala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:58:57 by rabusala          #+#    #+#             */
/*   Updated: 2024/09/05 15:49:31 by rabusala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)

{
	unsigned char	*str;

	str = s;
	while (n--)
		*str++ = '\0';
}
/*int main(void)
 {
	char str[]="hello world";
	ft_bzero(str,3);
	printf("%s",str);
	return 0;
}*/
