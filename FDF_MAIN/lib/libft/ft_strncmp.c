/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrakyma <ktrakyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 21:20:02 by ktrakyma          #+#    #+#             */
/*   Updated: 2024/10/30 17:04:45 by ktrakyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
// #include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && i < n && s1[i] != '\0')
	{
		i++;
	}
	if (i == n)
	{
		return (0);
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
// int main(void)
// {
//     char s1 [] = "Hello";
//     char s2 [] = "Hell";

//     int result = ft_strncmp(s1, s2, 4);
//     printf("%i", result);
// }