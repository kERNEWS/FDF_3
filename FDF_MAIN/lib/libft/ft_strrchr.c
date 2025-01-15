/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrakyma <ktrakyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 20:45:44 by ktrakyma          #+#    #+#             */
/*   Updated: 2024/10/29 18:22:23 by ktrakyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strrchr(const char *s, int c)
{
	const char	*result;

	result = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			result = s;
		}
		s++;
	}
	if ((char) c == '\0')
	{
		return ((char *)s);
	}
	else
	{
		return ((char *)result);
	}
}

// int	main(void)
// {
// 	char *string = "hellol";
// 	char c = ' ';
// 	char *result = strrchr(string, c);
// 	write(1, result, 1);
// }