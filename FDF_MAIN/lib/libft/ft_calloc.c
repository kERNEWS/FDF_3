/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrakyma <ktrakyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:33:35 by ktrakyma          #+#    #+#             */
/*   Updated: 2024/10/30 16:48:14 by ktrakyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
// #include <stdio.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	alloc_num;
	void	*p;

	alloc_num = 0;
	if (nmemb == 0 || size == 0)
	{
		p = malloc(1);
		if (!p)
			return (NULL);
		return (p);
	}
	if (nmemb > __SIZE_MAX__ / size)
	{
		return (NULL);
	}
	alloc_num = nmemb * size;
	p = malloc(alloc_num);
	if (p == NULL)
		return (NULL);
	ft_memset(p, 0, alloc_num);
	return (p);
}

// int main (void)
// {
// 	int nub = 3;
// 	char *s = ft_calloc(0 , 0);
// 	for (int i = 0; i < nub; i++)
// 	{
// 		if (s[i] != 0)
// 		{
// 			printf("calloc not working properly");
// 			return -1;
// 		}
// 	}
// 	printf("calloc is working");
// 	return (0);
// }