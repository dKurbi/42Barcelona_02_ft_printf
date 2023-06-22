/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:41:31 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/06/22 14:59:08 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	make_c(char *pc, char c)
{
	pc[0] = c;
	pc[1] = '1';
}

static char	*iss(char *print_str, va_list ap)
{
	print_str = va_arg(ap, char *);
	if (!print_str)
		print_str = ft_strdup ("(null)");
	else
		print_str = ft_strdup(print_str);
	return (print_str);
}

char	*make_str(const char **str, char *print_str, va_list ap, char *c)
{
	c[1] = '0';
	if (*str[0] != '%')
		make_c(c,*str[0]);
	else
	{
		(*str)++;
		if (*str[0] == 's')
			print_str = iss(print_str, ap);
		else if (*str[0] == '%')
			print_str = ft_strdup("%");
		else if (*str[0] == 'd' || *str[0] == 'i')
			print_str = ft_itoa(va_arg(ap, int));
		else if (*str[0] == 'u')
			print_str = ft_itoa_u(va_arg(ap, unsigned int));
		else if (*str[0] == 'x')
			print_str = ft_itoa_hex((unsigned long)va_arg(ap, int), 0);
		else if (*str[0] == 'X')
			print_str = ft_itoa_hex((unsigned long)va_arg(ap, int), 1);
		else if (*str[0] == 'p')
			print_str = ft_itoa_hex(va_arg(ap, unsigned long), 2);
		else if (*str[0] == 'c')
			make_c (c, (char) va_arg(ap, int));
	}
	return (print_str);
}

int	pr_print(char *print_str, char *c, va_list ap)
{
	int	i;

	if (c[1] != '0')
	{	
		i = ft_putchar(c[0]);
		if (i == -1)
		{
			va_end(ap);
			return (-1);
		}
	}
	else
	{
		i = ft_putstr(print_str);
		if (i == -1 || !print_str)
		{
			free(print_str);
			va_end(ap);
			return (-1);
		}
		free (print_str);
	}
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		rtn;
	char	*print_str;
	int		i;
	char	c[2];

	va_start(ap, str);
	rtn = 0;
	while (*str)
	{
		print_str = make_str(&str, print_str, ap, c);
		i = pr_print(print_str, c, ap);
		if (i == -1)
			return (-1);
		rtn += i;
		str++;
	}
	va_end(ap);
	return (rtn);
}
