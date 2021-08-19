#include <stdio.h>
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

char    *get_next_line(int fd)
{
    static char* save[100];
    char    buff[BUFFER_SIZE];
    
    while (read(fd, buff, BUFFER_SIZE))
    {
        buff[BUFFER_SIZE] = 0;
        if (is_in_line_feed(buff) == -1)
        {
            return buff;
        }
    }

}

int main()
{
    int fd;
    char *value;

    fd = open("test.txt", O_RDONLY);
    value = get_next_line(fd);
    printf("%s",value);
}