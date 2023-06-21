#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
int  ft_putchar(char cs)
{
    int c = 0;
    c += write(1, &cs, 1);
    return c;
}
int ft_putstr(char *s)
{
    if (!s)
    {
        ft_putstr("(null)");
        return 6;
    }
    int i = 0;
    while(s[i])
    {
        write(1, &s[i], 1);
        i++;
    }
    return i;
}
int ft_putnbr(long int n)
{
    int c = 0;
    char b[] = "0123456789";
    if (n < 0)
    {
        c+= ft_putchar('-');
        n = -n;
    }
    if (n >= 10)
        c+= ft_putnbr(n / 10);
   c+=  write(1, &b[n % 10], 1);
   return c;
}
int ft_puthexa(unsigned int n)
{
    int c = 0;
    char b[] = "0123456789abcdef";
  
    if (n >= 16)
        c+= ft_putnbr(n / 16);
   c+=  write(1, &b[n % 16], 1);
   return c;
}

int ft_printf(const char *str, ... )
{
    va_list ap;
    int i = 0;
    int c = 0;

    va_start(ap, str);
    while (str[i])
    {
        if (str[i] == '%')
        {   
            i++;
            if (str[i] == 'd')
                c += ft_putnbr(va_arg(ap, int));
            if (str[i] == 'x')
                c += ft_puthexa(va_arg(ap, unsigned int));
            if (str[i] == 's')
                c += ft_putstr(va_arg(ap, char *));
        }
        else
        c += ft_putchar(str[i]);
        i++;
    }
    va_end(ap);
    return c;
}