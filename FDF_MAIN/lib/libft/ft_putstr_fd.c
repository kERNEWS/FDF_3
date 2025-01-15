/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrakyma <ktrakyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:03:19 by ktrakyma          #+#    #+#             */
/*   Updated: 2024/10/24 20:05:30 by ktrakyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	write (fd, s, i);
}
// int main (void)
// {
// 	ft_putstr_fd("Hello", 1);
// }