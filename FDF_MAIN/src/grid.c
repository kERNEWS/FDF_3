#include "../inlcude/fdf.h"

int count_rows(char *file_name)
{
	char *line;
	int fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return -1;
	int row;
	row = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		free(line);
		row++;
	}
	close(fd);
	return (row);
}
int count_col(char *file_name)
{
	int fd = open(file_name, O_RDONLY);
    if (fd < 0)
	{
		return (-1);
	}
	char *line;
	char **content;
	int i;
    i = 0;
	line = get_next_line(fd);
	replace_nl(line);
	content = ft_split(line, ' ');
	while (content[i] != NULL)
		{
			free(content[i]);
			i++;
		}
		free(content);
		free(line);
	while((line = get_next_line(fd)) != NULL)
		free(line);
	close(fd);
	return (i);
}


t_map **alloc_grid(int row, int col)
{
	t_map **grid;
	int i;

	i = 0;
	if ((grid = malloc(row * sizeof(t_map *))) == NULL)
		return (NULL);
	while (i < row)
	{
		if ((grid [i] = malloc(col * sizeof(t_map))) == NULL)
		{
			while (--i >= 0)
				free(grid[i]);
			free(grid);
			return(NULL);
		}
		i++;
	}
	return (grid);
}
void set_color(char **content, t_map **grid, int t, int i, int k)
{
    char *temp;
    unsigned int color = 0xFFFFFF;

    temp = ft_strchr(content[t], ',');
    if (temp)
    {
        
        color = ft_atoi_base(temp + 1, 16);
    }

    grid[i][k].color = color;
}


void convert_and_store(t_map **grid, int row, int col, char **content)
{
	int i;
	int k;
	int t;

	i = 0;
	t = 0;
	while (i < row)
	{
		k = 0;
		while(k < col)
		{
			if (!content[t]) // Ensure content[t] is not NULL
            {
                fprintf(stderr, "Error: NULL value in content at index %d\n", t);
                return;
            }
			if (t >= row * col)
				return;
			grid[i][k].height = ft_atoi(content[t]);
			set_color(content, grid, t, i, k);
			// printf("%x\n", grid[i][k].color);
			k++;
			t++;
		}
		i++;
	}
}


static char	*allocate_space(char *line, size_t *capacity)
{
	size_t		i;
	char	*fresh_line;
	size_t line_len;

	i = 0;
	*capacity = *capacity * 2;
	fresh_line = malloc (*capacity * (sizeof(char)));
	if (!fresh_line)
		return (NULL);
	line_len = ft_strlen(line);
	while (line_len != 0 && i <= line_len)
	{
		fresh_line[i] = line[i];
		i++;
	}
	free (line);
	line = fresh_line;
	return (line);
}

int need_more_space(char *str, size_t *capacity, char *s)
{
	if (((size_t)ft_strlen(str) + (size_t)ft_strlen(s) + 1) < *capacity)
		return (0);
	return(1);
}

t_map **load_map(char *file_name, int col, int row)
{
	char **content;
	char *s;
	char *str;
	t_map **grid;
	size_t capacity;

	capacity = 1028;

	int fd = open(file_name, O_RDONLY);
	if (!(str = malloc(1)) && (s = malloc(1)))
		return(NULL);
	str[0] = '\0';
	if (fd < 0)
		return (NULL);
	while(1)
	{
		if (need_more_space(str, &capacity, s))
		{
			if (!(str = (allocate_space(str, &capacity))))
			{
				free(str);
				return(NULL);
			}
		}
		s = get_next_line(fd);
		// printf("%s", s);
		if (s == NULL)
			break;
		ft_strlcat(str, s, capacity);
		free(s);
	}
	replace_nl(str);
	if ((content = ft_split(str, ' ')) == NULL)
		return(NULL);
	free(str);
	if ((grid = alloc_grid(row, col)) == NULL)
		return (NULL);
	// for (int c = 0; c < row * col; c++)
	// {
	// 	printf("%s = %i ", content[c], c);
	// }
	convert_and_store(grid, row, col, content);
	for (int c = 0; content[c]; c++) // Properly free the split content
        free(content[c]);
    free(content);
	close(fd);
	return (grid);
}