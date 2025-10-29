/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabusala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:45:20 by rabusala          #+#    #+#             */
/*   Updated: 2024/08/26 15:46:46 by rabusala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*int	atoi(char c)
{
	return (c -= 48);
}*/

int	ft_isdigit(int c)

{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
/*int	main(int argc, char **argv)
{
	int	x;

	if (argc == 2)
	{
		x = atoi(argv[1][0]);
		printf("%d\n", ft_isdigit(x));
	}
	else
		printf("error");
}*/
