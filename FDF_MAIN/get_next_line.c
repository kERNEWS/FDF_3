/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktrakyma <ktrakyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:05:56 by ktrakyma          #+#    #+#             */
/*   Updated: 2024/12/15 16:45:07 by ktrakyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef MAX_FD
# define MAX_FD 100000
#endif

static char	*re_allocate(t_result *line, int capacity_needed)
{
	int		i;
	char	*fresh_line;

	i = 0;
	if (line->capacity == 0)
		line->capacity = 128;
	while (line->capacity <= capacity_needed)
		line->capacity *= 2;
	fresh_line = malloc (line->capacity * sizeof(char));
	if (!fresh_line)
	{
		free (line->content);
		line->content = NULL;
		return (NULL);
	}
	while (line->size != 0 && i <= line->size)
	{
		fresh_line[i] = line->content[i];
		i++;
	}
	free (line->content);
	line->content = fresh_line;
	return (line->content);
}

static t_result	append_to_line(t_buffer *buf, t_result
*line, int start, int end)
{
	if (line->capacity < (end - start + 1) + line->size)
		if (!(re_allocate(line, (end - start + 1) + line->size)))
			return (*line);
	while (start < end)
	{
		line->content[line->size] = buf->buffer[start];
		line->size++;
		start++;
	}
	line->content[line->size] = '\0';
	return (*line);
}

static char	*return_content(t_result line)
{
	char	*return_;
	int		i;

	i = 0;
	if (line.size == 0)
	{
		free (line.content);
		return (NULL);
	}
	return_ = malloc ((line.size + 1) * sizeof(char));
	if (!return_)
	{
		free (line.content);
		return (NULL);
	}
	while (i <= line.size)
	{
		return_[i] = line.content[i];
		i++;
	}
	free (line.content);
	return (return_);
}

static char	*main_(t_buffer *buf, int fd, t_result *line)
{
	int	start;
	int	end;

	start = buf->last;
	if (start == 0)
		buf->size = read (fd, buf->buffer, BUFFER_SIZE);
	if (buf->size <= 0)
	{
		if (buf->size == 0)
			return (return_content(*line));
		free (line->content);
		return (NULL);
	}
	end = start;
	while (end < buf->size && buf->buffer[end] != '\n')
		end++;
	if (end < buf->size)
	{
		buf->last = (end + 1) % buf->size;
		return (return_content(append_to_line(buf, line, start, end + 1)));
	}
	buf->last = 0;
	if (!(append_to_line(buf, line, start, buf->size).content))
		return (NULL);
	return (main_(buf, fd, line));
}

char	*get_next_line(int fd)
{
	static t_buffer	buf = {0, 0, ""};
	t_result		line;
	char			*result;

	if (fd < 0 || fd >= MAX_FD)
		return (NULL);
	line.capacity = 0;
	line.size = 0;
	line.content = NULL;
	result = main_(&buf, fd, &line);
	return (result);
}

// int main()
// {
// 	int fd = open("giant_line.txt", O_RDONLY);
// 	char *return_ = NULL;
// 	while ((return_ = get_next_line(fd)))
// 	{
// 		printf("%s", return_);
// 		free(return_);
// 	}
// }
// // 	return_ = get_next_line(fd);
// // 	printf("%s", return_);
// // 	free(return_);
// // 	return_ = get_next_line(fd);
// // 	printf("%s", return_);
// // 	free(return_);
// // 	return_ = get_next_line(fd);
// // 	printf("%s", return_);
// // 	free(return_);
// // 	return_ = get_next_line(fd);
// // 	printf("%s", return_);
// // 	free(return_);
// // 	return_ = get_next_line(fd);
// // 	printf("%s", return_);
// // 	free(return_);
// // 	return_ = get_next_line(fd);
// // 	printf("%s", return_);
// // 	free(return_);
// // }
