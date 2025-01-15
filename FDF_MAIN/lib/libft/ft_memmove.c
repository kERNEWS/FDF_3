/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrakyma <ktrakyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 20:10:53 by ktrakyma          #+#    #+#             */
/*   Updated: 2024/10/29 17:52:19 by ktrakyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *) dest;
	s = (unsigned char *) src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	if (d > s && d < s + n)
	{
		i = n;
		while (i > 0)
		{
			i--;
			d[i] = s [i];
		}
		return (dest);
	}
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
// int main(void)
// {
//     char buffer[20] = "1234567890";
//     ft_memmove(buffer + 4, buffer, 6);
//     printf("%s\n", buffer);
//     return 0;
// }