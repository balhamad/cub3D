/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabusala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:46:58 by rabusala          #+#    #+#             */
/*   Updated: 2024/08/29 17:04:09 by rabusala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)
		|| (c >= 48 && c <= 57))
		return (8);
	else
		return (0);
}
/*int main(int argc, char **argv)
{
	int i=0;
	if (argc ==2)
	{
		while(argv[1][i])
		{
			printf ("%d\n", ft_isalnum(argv[1][i]));
			printf ("%d", isalnum(argv[1][i]));
			if (i>0)
			{
				printf("error");
				break;
			}
			i++;
		}
	}
	else
		printf ("error");
}*/
