/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrakyma <ktrakyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:33:09 by ktrakyma          #+#    #+#             */
/*   Updated: 2024/10/29 19:13:54 by ktrakyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	size_t	len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	write (fd, s, len);
	write (fd, "\n", 1);
}

// int main (void)
// {
// 	char *s = "asa\n";
// 	ft_putendl_fd(s, 2);
// }
