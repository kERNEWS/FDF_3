/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrakyma <ktrakyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:06:13 by ktrakyma          #+#    #+#             */
/*   Updated: 2024/12/15 16:46:54 by ktrakyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_buffer
{
	int		last;
	int		size;
	char	buffer[BUFFER_SIZE];
}	t_buffer;

typedef struct s_result
{
	char	*content;
	int		size;
	int		capacity;
}	t_result;

char	*get_next_line(int fd);

#endif