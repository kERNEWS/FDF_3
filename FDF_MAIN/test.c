#include "inlcude/fdf.h"

#include "lib/libft/libft.h"

static int	is_space(char c)
{
	if (c == ' ' || (c >= '\t' && c <= '\r'))
	{
		return (1);
	}
	return (0);
}

static int	check_sign(char c)
{
	if (c == '-')
	{
		return (-1);
	}
	return (1);
}

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		res;
	int		sign;

	i = 0;
	res = 0;
	if (nptr == NULL)
		return (0);
	while (is_space(nptr[i]))
	{
		i++;
	}
	sign = check_sign(nptr[i]);
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	res *= sign;
	return (res);
}
int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (*str++)
	{
		i++;
	}
	return (i);
}
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(src);
	i = 0;
	if (size == 0)
	{
		return (len);
	}
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
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

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = 0;
	if (size <= len_dst)
		return (size + len_src);
	else
	{
		while (src[i] && (len_dst + i) < (size - 1))
		{
			dst[len_dst + i] = src[i];
			i++;
		}
		dst[len_dst + i] = '\0';
		return (len_dst + len_src);
	}
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


void replace_nl(char *str)
{
	int i;

	i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			str[i] = ' ';
		i++;
	}
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
			grid[i][k].height = ft_atoi(content[t]);
			printf("%x\n", grid[i][k].color);
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
    size_t capacity = 1028;

    int fd = open(file_name, O_RDONLY);
    if (fd < 0 || !(str = malloc(capacity)) || !(s = malloc(1)))
        return (NULL);
    str[0] = '\0'; // Initialize as an empty string
    s[0] = '\0';

    while (1)
    {
        s = get_next_line(fd);
        if (s == NULL) // Handle EOF or error
            break;

        if (need_more_space(str, &capacity, s))
        {
            char *temp = allocate_space(str, &capacity);
            if (!temp)
            {
                free(s);
                free(str);
                close(fd);
                return (NULL);
            }
            str = temp;
        }

        ft_strlcat(str, s, capacity); // Append line to str
        free(s); // Free the line returned by get_next_line
    }

    replace_nl(str); // Replace newlines in the combined string

    content = ft_split(str, ' '); // Split into tokens
    free(str); // Free combined string after splitting

    if (!content || !(grid = alloc_grid(row, col)))
    {
        if (content)
        {
            for (int c = 0; content[c]; c++)
                free(content[c]);
            free(content);
        }
        close(fd);
        return (NULL);
    }

    convert_and_store(grid, row, col, content);

	for (int c = 0; c < row * col; c++)
	{
		printf("%s = %i ", content[c], c);
	}
    for (int c = 0; content[c]; c++) // Free split content
        free(content[c]);
    free(content);
    close(fd);
    return (grid);
}
int main (int argc, char *argv[])
{
    char* file_name = "test_maps/julia.fdf";
    int k = count_rows(file_name); // Number of rows
    int i = count_col(file_name);  // Number of columns
    printf("%i\n", k);
    printf("%i\n", i);

    // Load the map into grid
    t_map **grid = load_map(file_name, i, k);

    // Free the grid rows
    for (int row = 0; row < k; row++) 
    {
        free(grid[row]); // Free each row
    }

    // Free the grid itself
    free(grid);

    return 0; // Successful exit
}

	
	// for (int c = 0; c < k; c++)
	// {
	// 	for (int x = 0; x < i; x++)
	// 	{
	// 		printf("%i ", grid[c][x].height);
	// 	}
	// 	printf("\n");
	// }
