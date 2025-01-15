/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrakyma <ktrakyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 21:47:45 by ktrakyma          #+#    #+#             */
/*   Updated: 2024/10/29 18:29:43 by ktrakyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
// #include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;
	size_t				i;

	i = 0;
	p1 = (const unsigned char *) s1;
	p2 = (const unsigned char *) s2;
	if (n == 0)
	{
		return (0);
	}
	while (i < n && p1[i] == p2[i])
	{
		i++;
	}
	if (i == n)
		return (0);
	return ((int)(p1[i] - p2[i]));
}
// int main (void)
// {
// 	char str1[] = "abcdefghij";
//     char str2[] = "abcdefgxyz";
//     int result = ft_memcmp(str1, str2, 7);
// 	printf("%i", result);
// }