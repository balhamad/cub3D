/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lowhexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabusala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:16:01 by rabusala          #+#    #+#             */
/*   Updated: 2024/09/19 17:41:41 by rabusala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lowhexa(unsigned int nb)
{
	char			*base;
	unsigned int	len;

	len = 0;
	base = "0123456789abcdef";
	if (nb >= 16)
	{
		len += ft_lowhexa(nb / 16);
		len += ft_putchar(base[nb % 16]);
	}
	else
		len += ft_putchar(base[nb % 16]);
	return (len);
}
