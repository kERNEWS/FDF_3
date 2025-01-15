/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrakyma <ktrakyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:48:39 by ktrakyma          #+#    #+#             */
/*   Updated: 2024/10/29 14:37:36 by ktrakyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <stdlib.h>
#include "libft.h"

// static char	func(unsigned int i, char c)
// {
// 	return (c + i);
// }

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*result;
	size_t	i;

	len = 0;
	i = 0;
	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	result = malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	while (i < len)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

// int main (void)
// {
// 	char * result = ft_strmapi("Hello, my name is hello", func);
// 	printf("%s", result);
// }
