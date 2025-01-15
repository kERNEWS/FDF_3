/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrakyma <ktrakyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:45:47 by ktrakyma          #+#    #+#             */
/*   Updated: 2024/10/29 14:32:38 by ktrakyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
// #include <stdio.h>
#include "libft.h"

static char	*alloc(size_t str_len, size_t len, unsigned int start, char *p)
{
	if (str_len - start > len)
	{
		p = malloc(len + 1);
	}
	else
	{
		p = malloc((str_len - start) + 1);
	}
	return (p);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			str_len;
	unsigned int	i;
	char			*p;

	i = 0;
	p = NULL;
	str_len = ft_strlen(s);
	if (start >= str_len)
		return (ft_strdup(""));
	p = alloc(str_len, len, start, p);
	if (p == NULL)
		return (NULL);
	while (i < len && s[start] != '\0')
	{
		p[i] = s[start];
		i++;
		start++;
	}
	p[i] = '\0';
	return (p);
}

// int main (void)
// {
// 	char *s = "Hello";
// 	unsigned int start = 1;
// 	size_t len = 5;
// 	char *result = ft_substr(s, start, len);
// 	printf("%s", result);
// }