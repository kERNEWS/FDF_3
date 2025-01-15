/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrakyma <ktrakyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 22:24:30 by ktrakyma          #+#    #+#             */
/*   Updated: 2024/10/29 14:43:38 by ktrakyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(src);
	i = 0;
	if (size == 0)
	{
		return (len);
	}
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
// int	main (void)
// {
// 	int size = 0;
// 	char dst [size];
// 	char src [] = "my name is hello";
// 	int result = ft_strlcpy(dst, src, size);
// 	printf("%s\n", dst);
// 	printf("%i", result);
// } 