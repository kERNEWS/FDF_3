/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrakyma <ktrakyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 21:21:49 by ktrakyma          #+#    #+#             */
/*   Updated: 2024/10/29 15:01:02 by ktrakyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
// #include <stdio.h>
#include "libft.h"

static size_t	count_substr(char const *s, char c)
{
	size_t	numb;
	size_t	i;

	numb = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != '\0')
		{
			numb++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (numb);
}

static int	free_ifmalloc_fails(char **array, size_t i)
{
	if (array[i] == NULL)
	{
		while (i-- > 0)
		{
			free (array[i]);
		}
		free (array);
		return (1);
	}
	return (0);
}

static const char	*skip_delimeters(const char *s, char c)
{
	while (*s == c && *s != '\0')
		s++;
	return (s);
}

static size_t	len_substr(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	return (len);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	num_of_substr;
	char	**array;
	size_t	len;

	i = 0;
	num_of_substr = count_substr(s, c);
	array = malloc((num_of_substr + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	while (*s && i < num_of_substr)
	{
		s = skip_delimeters(s, c);
		len = len_substr(s, c);
		array[i] = malloc((len + 1) * sizeof(char));
		if (free_ifmalloc_fails(array, i) == 1)
			return (NULL);
		ft_strlcpy(array[i], s, len + 1);
		i++;
		s += len;
	}
	array[i] = NULL;
	return (array);
}

// int main (void)
// {
// 	char * str = ", hello,, my name , is,,";
// 	char c = ',';
// 	int i = 0;
// 	char **result = ft_split(str, c);
// 	while(result[i] != NULL)
// 	{
// 		printf("%s\n", result[i]);
// 		free(result[i]);
// 		i++;
// 	}
// }