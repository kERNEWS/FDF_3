/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrakyma <ktrakyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:53:38 by ktrakyma          #+#    #+#             */
/*   Updated: 2024/10/16 20:05:49 by ktrakyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (c - 'A' + 'a');
	}
	else
	{
		return (c);
	}
}
// int main(void)
// {
//     char ch = '1';
//     printf("%c\n", ft_tolower(ch));

// }