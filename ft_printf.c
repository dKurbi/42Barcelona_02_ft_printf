/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:41:31 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/06/15 17:09:16 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include <unistd.h>

int ft_abs(int i)
{
	if (i < 0)
		return (-i);
	else 
		return (i);
}

int ft_putchar(char c)
{
	write (1,&c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int rtn;

	if (ft_strlen(str) == 0)
	{
		write (1, "NULL", 4);
		return (4);
	} 
	else 
	{
		rtn = 0;
		while (str[rtn])
			write(1, &str[rtn++], 1);
	}
	return (rtn);
}


char	*exceptions(int n)
{
	char	*rtn;
	
	if (n == 0)
		rtn = ft_strdup("0");
	else
		rtn = ft_strdup("-80000000");
	return (rtn);
}

char	*mall_str(int n, int *num_d )
{
	int 	i;
	char	*rtn;

	 i = 0;
	 if (n < 0)
	 {
		 *num_d = 1;
		 n = -n;
	 }
	 while (n > 0)
	 {
		 n = n / 16;
		 (*num_d)++;
	 }
	 rtn = (char *) ft_calloc(*num_d + 1, sizeof(char));
	 return (rtn);
}

char	*detohex(char *rtn, int n, int num_d, int upper)
{
	char a;

	a = 'a';
	if (upper)
		a = 'A';
	num_d--;
	if (n < 0)
	{
		rtn[0] = '-';
		n = -n;
	}
	while(n > 0)
	{
		if ((n % 16) < 10) 
			rtn[num_d] = n % 16 + '0';
		else
			rtn[num_d] = n % 16 - 10 + a;
		n = n / 16;
		num_d--;
	}
	return (rtn);
}


char	*ft_itoa_hex(int num, int upper)
{
	char	*rtn;
	int		num_d;

	num_d = 0;
	if ((num == 0) || (num <=-2147483648))
		return (exceptions(num));
	rtn = mall_str(num, &num_d);
	if (rtn)
		rtn = detohex(rtn, num, num_d, upper);
	return (rtn);
}
	





int ft_printf(const char *str, ...)
{
	va_list ap;
	int rtn;

	va_start(ap, str);
	rtn = 0;
	while (*str)
	{
		if (str[0] != '%')
			rtn += ft_putchar(str[0]);
		else 
		{
			str++;
			if(str[0] == '%')
				rtn += ft_putchar('%');
			else if(str[0] == 'c')
				rtn += ft_putchar((char) va_arg(ap, char));
			else if(str[0] == 's')
				rtn += ft_putstr(va_arg(ap, char *));
			else if(str[0] == 'd' || str[0] == 'i')
				rtn += ft_putstr(ft_itoa(va_arg(ap, int)));
			else if(str[0] == 'u')
				rtn += ft_putstr(ft_itoa(ft_abs(va_arg(ap, int))));
			else if(str[0] == 'x')
				rtn += ft_putstr(ft_itoa_hex(va_arg(ap, int), 0));
			else if(str[0] == 'X')
				rtn += ft_putstr(ft_itoa_hex(va_arg(ap, int), 1));
		}
		str++;
	}
	va_end(ap);
	return (rtn);
}

int main(int args, char	**argv)
{
	char *str = "que tal";
	int rtn = 0;
	int rtn2 = 0;
	int i = 12131415;
	ft_printf("mi funcion\n");
	rtn = ft_printf("x= %x X = %X %% \n",i,i);
	printf("devuelve %d\n", rtn);
	printf("print f\n");
	rtn2 = printf("x= %x X = %X %% \n",i,i);
	printf("devuelve %d\n", rtn2);

}
	
	
