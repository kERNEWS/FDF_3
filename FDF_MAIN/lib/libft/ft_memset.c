/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrakyma <ktrakyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:30:54 by ktrakyma          #+#    #+#             */
/*   Updated: 2024/10/29 15:15:52 by ktrakyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
// void	*ft_memset(void *ptr, int val, size_t num);
// int main(void)
// {
// 	size_t c = 5;
// 	char buffer[20] = "hello";
// 	write(1, buffer, 19);
// 	void *result = ft_memset(buffer, 'B', c);
// 	write(1, "\n", 1);
// 	write(1, result, 19);
// }
void	*ft_memset(void *ptr, int val, size_t num)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)ptr;
	i = 0;
	while (i < num)
	{
		p[i] = (unsigned char)val;
		i++;
	}
	return (ptr);
}
