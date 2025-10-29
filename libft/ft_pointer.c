/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabusala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:44:23 by rabusala          #+#    #+#             */
/*   Updated: 2024/09/21 16:51:18 by rabusala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pointer(unsigned long nb)
{
	char	*base;
	int		len;

	base = "0123456789abcdef";
	len = 0;
	if (nb >= 16)
	{
		len += ft_pointer(nb / 16);
		len += ft_pointer(nb % 16);
	}
	else
		len += ft_putchar(base[nb % 16]);
	return (len);
}

int	ft_p(unsigned long nb)
{
	if (nb == 0)
		return (write(1, "(nil)", 5));
	else
		return (ft_putstr("0x") + ft_pointer(nb));
}
