/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabusala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:64:53 by rabusala          #+#    #+#             */
/*   Updated: 2024/09/01 14:45:56 by rabusala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)

{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
/*int main(int c, char **v)
{
	if (c ==2)
	{
		printf("%d",ft_isascii(v[1][0]));
		printf("%d",isascii(v[1][0]));
	}
	else
		printf("error");
}*/
