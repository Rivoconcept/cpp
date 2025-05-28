
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int ft_printchar(char c)
{
    return (write(1, &c, 1));
}

int ft_printstr(char *str)
{
    int i = 0;
    int count = 0;
    if (!str)
        return (write(1, "(null)", 6));
    while(str[i] != '\0')
    {
        count += ft_printchar(str[i]);
        i++;
    }
    return (count);
}

int nbrlen(int nbr)
{
    int i = 0;
    if (nbr <= 0)
        i++;
    while(nbr)
    {
        i++;
        nbr /= 10;
    }
    return (i);
}

char *ft_itoa(int nbr)
{
    int i = 0;
    long n = nbr;
    char *str;
    int size = nbrlen(n);

    str = (char *)malloc(sizeof(char) * (size + 1));
    if (!str)
        return (NULL);
    str[size] = '\0';
    if (nbr < 0)
    {
        str[0] = '-';
        n *= -1;
        i++;
    }
    while( i < size)
    {
        str[--size] = (n % 10) + '0';
        n /= 10;
    }
    return (str);
}

int ft_printnbr(int nbr)
{
    int count = 0;
    char *str = ft_itoa(nbr);
    if (str)
    {
        count = ft_printstr(str);
        free(str);
    }
    return (count);
}

int ft_printhexa(unsigned int nbr)
{
    int i = 0;
    int count = 0;
    char temp[50];
    char *base = "0123456789abcdef";
    
    if (nbr == 0)
        return (write(1, "0", 1));
    while (nbr)
    {
        temp[i++] = base[nbr % 16];
        nbr /= 16;
    }
    while (i-- > 0)
    {
        count += ft_printchar(temp[i]);
    }
    return (count);
}

int find_format(char type, va_list args)
{
    int count = 0;
    if (type == 's')
        count += ft_printstr(va_arg(args, char *));
    else if (type == 'd')
        count += ft_printnbr(va_arg(args, int));
    else if (type == 'x')
        count += ft_printhexa(va_arg(args, unsigned int));
    return (count);
}

int ft_printf(const char *format, ... )
{
    int i = 0;
    int count = 0;
    va_list args;

    va_start(args, format);
    while(format[i] != '\0')
    {
        if (format[i] == '%')
        {
            i++;
            count += find_format(format[i], args);
        }
        else
            count += ft_printchar(format[i]);
        i++;
    }
    va_end(args);
    return (count);
}

/*int main(void)
{
    int nbr = 30;
	char *str = "comment";
    ft_printf("%x %s %d\n", nbr, str, nbr);

    ft_printf("%s\n", "toto");


    ft_printf("Magic %s is %d", "number", 42);


    ft_printf("Hexadecimal for %d is %x\n", 42, 42);

    return (0);
}*/
