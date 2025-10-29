/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabusala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:02:23 by rabusala          #+#    #+#             */
/*   Updated: 2024/09/19 12:17:08 by rabusala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_form(va_list args, char s)
{
	int	c;

	c = 0;
	if (s == 'c')
		c += ft_putchar(va_arg(args, int));
	else if (s == 's')
		c += ft_putstr(va_arg(args, char *));
	else if (s == 'd' || s == 'i')
		c += ft_putnbr(va_arg(args, int));
	else if (s == 'u')
		c += ft_unsigned(va_arg(args, unsigned int));
	else if (s == 'x')
		c += ft_lowhexa(va_arg(args, unsigned int));
	else if (s == 'X')
		c += ft_uphexa(va_arg(args, unsigned int));
	else if (s == 'p')
		c += ft_p(va_arg(args, unsigned long));
	else if (s == '%')
		c += ft_putchar('%');
	return (c);
}

int	ft_printf(const char *form, ...)
{
	int		count;
	int		i;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, form);
	while (form[i])
	{
		if (form[i] == '%')
		{
			count += ft_form(args, form[++i]);
			i++;
		}
		else
		{
			write(1, &form[i++], 1);
			count++;
		}
	}
	return (count);
}
/*int main ()
{
	int c =5;
	int x = ft_printf("%d\n",c);
	printf("%d\n",x);
	return 0;
}*/
