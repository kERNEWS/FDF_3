/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrakyma <ktrakyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:38:52 by ktrakyma          #+#    #+#             */
/*   Updated: 2024/10/30 17:04:55 by ktrakyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
// #include <stdio.h>
#include "libft.h"

static int	is_inset(char c, const char *set)
{
	while (*set != '\0')
	{
		if (c == *set)
		{
			return (1);
		}
		set++;
	}
	return (0);
}

static char	*ft_strcpy(char *p, char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		p[i] = src[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	char	*temp;
	size_t	len;

	p = (char *)s1;
	len = ft_strlen(s1);
	if (len == 0)
		return (ft_strdup(""));
	while (is_inset(*p, set) == 1)
	{
		p++;
		len--;
	}
	while (is_inset(p[len - 1], set) == 1 && len != 0)
		len --;
	temp = malloc(len + 1);
	if (temp == NULL)
		return (NULL);
	ft_strcpy(temp, p, len);
	return (temp);
}
// int main (void)
// {
// 	char *s1 = "";
// 	char *set = "";
// 	char *result = ft_strtrim(s1, set);
// 	printf("%s", result);
// }