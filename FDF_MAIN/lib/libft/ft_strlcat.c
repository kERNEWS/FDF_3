/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrakyma <ktrakyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 20:30:15 by ktrakyma          #+#    #+#             */
/*   Updated: 2024/10/30 17:04:25 by ktrakyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
// #include <stdio.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = 0;
	if (size <= len_dst)
		return (size + len_src);
	else
	{
		while (src[i] && (len_dst + i) < (size - 1))
		{
			dst[len_dst + i] = src[i];
			i++;
		}
		dst[len_dst + i] = '\0';
		return (len_dst + len_src);
	}
}
// int	main (void)
// {
// 	int size = 50;
// 	char dest[10] = "a";
// 	char src [] = "lorem ipsum dolor sit amet";
// 	int result = ft_strlcat(dest, src, 0);
// 	printf("%s\n", dest);
// 	printf("%i", result);
// } 