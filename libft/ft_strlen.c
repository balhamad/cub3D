/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabusala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:24:45 by rabusala          #+#    #+#             */
/*   Updated: 2024/08/26 16:28:13 by rabusala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*int	main(int argc, char **argv)
{
	const char *str;
	str=argv[1];
	if (argc == 2)
	{
		printf("%ld\n", ft_strlen(str));
	}
	else
		printf("error");
}*/
