/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabusala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:48:48 by rabusala          #+#    #+#             */
/*   Updated: 2024/09/10 15:55:22 by rabusala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))

{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*void f(unsigned int n, char *str)
{
	*str = *str + n;
}
int main()
{
	char str[]="hello";
	printf("%s\n",str);
	ft_striteri(str,f);
	printf("%s",str);
	return 0;
}*/
