#include "inlcude/fdf.h"


int main()
{
    char *str;
    int fd = open("test_maps/julia.fdf", O_RDONLY);
    while((str = get_next_line(fd)) != NULL)
    {
        printf("%s", str);
    }
}