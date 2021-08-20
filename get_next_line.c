#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h>

#define BUFFER_SIZE 32

int     is_in_line_feed(char *buff)
{
    int     i = 0;

    while (buff[i])
    {
        if (buff[i] == '\n')
            return (i);
        i++;
    }
    return (-1);
}

int ft_len(char *str)
{
    int i;
    
    i = 0;
    while (str[i])
        i++;
    return (i);
}

void testprint(char *str)
{
    int i;
    int len;

    i = 0;
    printf("len start\n");
    len = ft_len(str);
    printf("len finish\n");
    printf("len count: %d\n", len);
    for(i = 0 ; i < len ; i++)
        printf("%c",str[i]);
    printf("\n");

    return ;
}

char    *get_next_line(int fd)
{
    int     read_size;
    char    *ptr;
    char    buff[BUFFER_SIZE + 1];

    ptr = buff;
    if (fd < 3)
        return (NULL);
    printf("fd:%d\n", fd);
    while ((read_size = read(fd, buff, BUFFER_SIZE)) > 0)
    {
        printf("readsize:%d\n",read_size);
        buff[read_size] = '\0';
        testprint(buff);
        printf("real start\n");
        if (is_in_line_feed(buff) != -1)
        {
            return ptr;
        }
        printf("real end\n");
    }
}

int main()
{
    int fd;
    char *value;
    int re;

    fd = open("test.txt", O_RDONLY);
    printf("%d\n",BUFFER_SIZE);
    get_next_line(fd);
}