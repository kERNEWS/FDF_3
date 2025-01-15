/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrakyma <ktrakyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 22:30:19 by ktrakyma          #+#    #+#             */
/*   Updated: 2024/10/29 19:09:52 by ktrakyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <unistd.h>
#include <stdlib.h>
// #include <stdio.h>

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

char	*ft_itoa(int n)
{
	int		num_dig;
	char	*result;

	num_dig = count_dig(n);
	result = malloc((num_dig + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
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

// int main (void)
// {
// 	char *res = ft_itoa(-2147483647 -1);
// 	printf("%s", res);
// }