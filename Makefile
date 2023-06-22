# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/21 12:18:41 by dkurcbar          #+#    #+#              #
#    Updated: 2023/06/21 16:37:18 by dkurcbar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= 	libftprintf.a
HEADER	:= 	ft_printf.h 
SRCS	:= 	ft_printf.c ft_itoa_hex.c ft_putchar.c ft_putstr.c ft_itoa_u.c
		
OBJS	:= ${SRCS:.c=.o}
CC		:= gcc
CFLAGS	:=	-Wall -Werror -Wextra
AR		:= ar rcs
INCLUDE	:= ft_printf.h Makefile
RM		:= rm -f 
MODE	:= normal
LIBFT	:= libft/

ifeq ($(MODE),  debug)
	CFLAGS	+= -g 
endif

all: 
	@make --no-print-directory -C ${LIBFT}
	@make --no-print-directory ${NAME}


${NAME}: ${OBJS}
	@cp libft/libft.a ${NAME}
	@${AR} ${NAME} $^ && echo "Library '${NAME}' created"

%.o: %.c ${INCLUDE}
	@${CC} -c ${CFLAGS} $< -o $@ && echo "Compiled: $< "
	
clean:
	@${RM} ${OBJS}
	@$(foreach obj,${OBJS},echo "File deleted: ${obj}";)

fclean:	clean
	@${RM} ${NAME} 
	@$(foreach obj,${NAME},echo "File deleted: $(obj)";)

re:	fclean all

.PHONY: all clean fclean re