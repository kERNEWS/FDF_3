/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrakyma <ktrakyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 21:13:04 by ktrakyma          #+#    #+#             */
/*   Updated: 2024/10/29 15:05:03 by ktrakyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
// #include <stdio.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		b;
	const unsigned char	*p;
	size_t				i;

	i = 0;
	b = (unsigned char) c;
	p = (const unsigned char *) s;
	while (i < n)
	{
		if (p[i] == b)
		{
			return ((void *)(p + i));
		}
		i++;
	}
	return (NULL);
}

// int main (void)
// {
// 	char *str = "Hello, World!";
//     char target = 'W';
//     char *result = ft_memchr(str, target, 2);

//     printf("%s", result);
// }