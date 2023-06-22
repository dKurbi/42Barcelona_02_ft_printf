/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:06:49 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/06/21 16:44:18 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

int		ft_printf(const char *str, ...);
char	*ft_itoa_hex(unsigned long num, int t);
int		ft_putchar(char c);
int		ft_putstr(char *str);
char	*ft_itoa_u(unsigned int n);

#endif
