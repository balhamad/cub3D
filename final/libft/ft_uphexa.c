/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uphexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabusala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:50:12 by rabusala          #+#    #+#             */
/*   Updated: 2024/09/21 11:50:42 by rabusala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_uphexa(unsigned int nb)
{
	char			*base;
	unsigned int	len;

	len = 0;
	base = "0123456789ABCDEF";
	if (nb >= 16)
	{
		len += ft_uphexa(nb / 16);
		len += ft_putchar(base[nb % 16]);
	}
	else
		len += ft_putchar(base[nb % 16]);
	return (len);
}
