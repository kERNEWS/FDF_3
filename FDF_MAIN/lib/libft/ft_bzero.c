/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrakyma <ktrakyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:28:10 by ktrakyma          #+#    #+#             */
/*   Updated: 2024/10/29 15:11:30 by ktrakyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_bzero(void *ptr, size_t num)
{
	unsigned char	*p;
	size_t			i;

	i = 0;
	p = (unsigned char *)ptr;
	while (i < num)
	{
		p[i] = 0;
		i++;
	}
}

// int main(void)
// {
//     char buffer[20] = "hello";
//     write(1, buffer, 19);
//     ft_bzero(buffer, 3);
//     write(1, "\n", 1);
//     write(1, buffer, 5);
// }
