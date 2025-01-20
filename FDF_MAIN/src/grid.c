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
			grid[i][k].height = ft_atoi(content[t++]);
			k++;
		}
		i++;
	}
}

t_map **load_map(char *file_name, int col, int row)
{
	char **content;
	char *s;
	char *str;
	t_map **grid;

	int fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (NULL);
	str = malloc((col * row) * sizeof(char *) + 1);
	if (str == NULL)
		return (NULL);
	while(1)
	{
		s = get_next_line(fd);
		printf("%s", s);
		if (s == NULL)
			break;
		str = strcat(str, s);
		free(s);
	}
	replace_nl(str);
	if ((content = ft_split(str, ' ')) == NULL)
		return(NULL);
	free(str);
	if ((grid = alloc_grid(row, col)) == NULL)
		return (NULL);
	for (int c = 0; c < row * col; c++)
	{
		printf("%s = %i ", content[c], c);
	}
	convert_and_store(grid, row, col, content);
	for (int c = 0; content[c]; c++) // Properly free the split content
        free(content[c]);
    free(content);

	return (grid);
}