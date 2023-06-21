#include  <stdio.h>
#include <unistd.h>
#include <stdlib.h>
 #include <fcntl.h>
 #include <string.h>

#ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
#endif

int ft_strlen(char *s)
{
    int i = 0;
    while(s[i])
    {
        i++;
    }
    return i;
}
char  *ft_strjoin(char *s1, char *s2)
{
    if (!s1)
    {
        s1 = malloc(sizeof(char));
        s1[0] = '\0';
    }
    int len = ft_strlen(s1) + ft_strlen(s2);
    char *all = malloc(sizeof(char) * len + 1);
    if  (!all)
        return NULL;
    int i = 0;
    int j = 0;

    while(i < ft_strlen(s1))
    {
        all[i] = s1[i];
        i++;
    }
    while(j < ft_strlen(s2))
    {
        all[i + j] = s2[j];
        j++;
    }
    all[i + j] = '\0';
    free(s1);
    return all;
}
int check_str(char *buff)
{
    int i = 0;
    while(buff[i])
    {
        if (buff[i] == '\n')
            return 1;
        i++;
    }
    return 0;
}
char	*new_get_line(char *str, int fd)
{
    int r = 1;
    char *buff;

    buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    while(r > 0)
    {
        r = read(fd , buff , BUFFER_SIZE);
        if (r == -1)
            break;
        buff[r] = '\0';
        str = ft_strjoin(str, buff);
        // exit (1);
        if (check_str(str) == 1)
            break;
    }
    free(buff);
    return str;
}
static char *new_get_exact_line(char *line)
{
    char *exactline;
    int i;
    if (!line[0])
        return NULL;
    i = 0;
    while(line[i] != '\n' && line[i] != '\0')
        i++;
    exactline = malloc(i + 2);
    if (!exactline)
        return NULL;
    i = 0;
    while(line[i] != '\n' && line[i] != '\0')
    {
        exactline[i] = line[i];
        i++;
    }
    if (line[i] == '\n')
    {
        exactline[i] = '\n';
        i++;
    }
    exactline[i] = '\0';
    return exactline;
}

char *ft_strchr(char *s)
{
    int i = 0;
    int j = 0;
    char *save;

    while(s[i] != '\n' && s[i] != '\0')
        i++;
    if (!s[i])
    {
        free(s);
        return NULL;
    }
    save = malloc(sizeof(char) * ((ft_strlen(s) - i)));
    if (!save)
        return NULL;
    i++;
    while (i < ft_strlen(s))
    {
        save[j] = s[i];
        i++;
        j++;
    }
    save[j] ='\0';
    free(s);
    return save;
    
}
char *get_next_line(int fd)
{
    static char *save;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    save = new_get_line(save, fd);
    if (!save)
        return NULL;
    line = new_get_exact_line(save);
    save = ft_strchr(save);
    return line;
}

int main()
{
    int fd = open("file.txt", O_RDWR);
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
}