/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrakyma <ktrakyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 22:35:35 by ktrakyma          #+#    #+#             */
/*   Updated: 2024/10/29 19:40:18 by ktrakyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
// #include <stdio.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;

	i = 0;
	little_len = ft_strlen(little);
	if (little_len == 0 && (big || little))
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		if (big[i] == little[0] && ft_strncmp(&big[i], little, little_len) == 0)
		{
			if (i + little_len <= len)
				return ((char *)(big + i));
		}
		i++;
	}
	return (NULL);
}

// int main (void)
// {
// 	const char *largestring = "MZIRIBMZIRIBMZE123";
//     const char *smallstring = "MZIRIBMZE";
//     char *ptr;

//     ptr = ft_strnstr(largestring, smallstring, 9);
// 	printf("%s", ptr);
// 	return 0;
// }