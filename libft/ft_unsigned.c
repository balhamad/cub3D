/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabusala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:21:21 by rabusala          #+#    #+#             */
/*   Updated: 2024/09/19 13:21:43 by rabusala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_unsigned(unsigned int c)
{
	int	count;

	count = 0;
	if (c >= 10)
		count += ft_unsigned((c / 10));
	count += ft_putchar((c % 10) + '0');
	return (count);
}
