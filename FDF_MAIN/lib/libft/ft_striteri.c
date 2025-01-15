/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrakyma <ktrakyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:08:23 by ktrakyma          #+#    #+#             */
/*   Updated: 2024/10/30 17:04:13 by ktrakyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"

// static void	func(unsigned int i, char *c)
// {
// 	if (i % 2 == 0 && *c >= 'a' && *c <= 'z')
// 		*c -= 32;
// }

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t			len;
	unsigned int	i;

	len = ft_strlen(s);
	i = 0;
	while (i < len)
	{
		f(i, &s[i]);
		i++;
	}
}
// int main (void)
// {
// 	char str[] = "Hello, my name is hello";
// 	ft_striteri(str, func);
// 	printf("%s", str);
// }