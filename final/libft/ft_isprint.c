/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabusala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:22:21 by rabusala          #+#    #+#             */
/*   Updated: 2024/09/01 14:25:51 by rabusala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (16384);
	else
		return (0);
}
/*int main(int c, char **v)
{
	if (c==2)
	{
		printf("%d\n",ft_isprint(v[1][0]));
		printf("%d",isprint(v[1][0]));
	}
	else
		printf("error");
}*/
