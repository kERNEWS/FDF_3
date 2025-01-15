/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrakyma <ktrakyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:36:31 by ktrakyma          #+#    #+#             */
/*   Updated: 2024/10/29 14:53:35 by ktrakyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
// #include <stdio.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*p;
	size_t	i;
	size_t	str_len;

	i = 0;
	str_len = ft_strlen((char *)s);
	p = malloc(str_len + 1);
	if (p == NULL)
		return (NULL);
	while (i < str_len)
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
// int main (void)
// {
// 	char *str = "";
// 	char *result = strdup(str);
// 	printf("%s", result);
// }