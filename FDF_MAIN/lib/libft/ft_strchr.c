/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrakyma <ktrakyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:40:23 by ktrakyma          #+#    #+#             */
/*   Updated: 2024/10/23 19:42:57 by ktrakyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	if ((char) c == '\0')
		return ((char *)s);
	else
		return (NULL);
}

// int	main(void)
// {
// 	char *string = "hello";
// 	char c = 'e';
// 	char *result = strchr(string, c);
// 	write(1, result, 1);
// }