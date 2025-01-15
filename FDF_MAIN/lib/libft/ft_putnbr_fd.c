/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrakyma <ktrakyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:45:28 by ktrakyma          #+#    #+#             */
/*   Updated: 2024/10/30 16:38:26 by ktrakyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static int	count_dig(int n)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		return (1);
	}
	if (n < 0)
	{
		i++;
		while (n < 0)
		{
			n /= 10;
			i++;
		}
		return (i);
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	convert_to_str(int num, char *res, int n)
{
	int		i;
	char	c;

	while (num >= 0 && n != 0)
	{
		i = n % 10;
		if (i < 0)
			i *= -1;
		n /= 10;
		c = i + '0';
		res[num] = c;
		num--;
	}
}

static char	*ft_itoa_no_malloc(int n, char *result)
{
	int		num_dig;

	num_dig = count_dig(n);
	if (n < 0)
	{
		result[0] = '-';
		n *= -1;
	}
	else if (n == 0)
	{
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}
	result[num_dig] = '\0';
	num_dig--;
	convert_to_str(num_dig, result, n);
	return (result);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		len;
	char	result[15];

	ft_itoa_no_malloc(n, result);
	len = ft_strlen(result);
	write (fd, result, len);
}
// int main (void)
// {
// 	int n = -2549;
// 	ft_putnbr_fd(n, 1);
// }