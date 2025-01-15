/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrakyma <ktrakyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:30:28 by ktrakyma          #+#    #+#             */
/*   Updated: 2024/10/29 15:01:12 by ktrakyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
// #include <stdio.h>
#include "libft.h"

static char	*strcpy(char *p, const char *src)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(src);
	i = 0;
	while (i < len)
	{
		p[i] = src[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

static char	*strcat(char *p, const char *src)
{
	size_t	len_p;
	size_t	len_src;
	size_t	i;

	len_p = ft_strlen(p);
	len_src = ft_strlen(src);
	i = 0;
	while (i < len_src)
	{
		p[len_p] = src[i];
		i++;
		len_p++;
	}
	p[len_p] = '\0';
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	len;

	len = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	p = malloc(len + 1);
	if (p == NULL)
	{
		return (NULL);
	}
	p = strcpy(p, s1);
	p = strcat(p, s2);
	return (p);
}

// int main (void)
// {
//     char *s = "hello";
// 	char *c = ", hello again";
// 	char * result = ft_strjoin(s, c);
//     printf("%s", result);
// }