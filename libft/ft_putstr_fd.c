/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabusala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:23:58 by rabusala          #+#    #+#             */
/*   Updated: 2024/09/04 17:30:53 by rabusala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *s)

{
	int	i;

	i = 0;
	if (!s)
		i += ft_putstr("(null)");
	else
	{
		while (s[i])
		{
			write (1, &s[i], 1);
			i++;
		}
	}
	return (i);
}
/*int main()
{
	ft_putstr_fd("hello",1);
	return 0;
}*/
