# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/21 12:18:41 by dkurcbar          #+#    #+#              #
#    Updated: 2023/06/26 15:26:35 by dkurcbar         ###   ########.fr        #
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
LIBFT_P	:= libft/
LIBFT_C := libft.a
INC_LBFT:= ${LIBFT_P}${LIBFT_C}

ifeq ($(MODE),  debug)
	CFLAGS	+= -g 
endif

all: 
	@make --no-print-directory -C ${LIBFT_P}
	@make --no-print-directory ${NAME}


${NAME}: ${OBJS} ${INC_LBFT}
	@cp libft/libft.a ${NAME}
	@${AR} ${NAME} $^ && echo "Library '${NAME}' created"

%.o: %.c ${INCLUDE}
	@${CC} -c ${CFLAGS} $< -o $@ && echo "Compiled: $< "
	
clean:
	@${RM} ${OBJS}
	@make --no-print-directory -C ${LIBFT_P} clean
	@$(foreach obj,${OBJS},echo "File deleted: ${obj}";)

fclean:	clean
	@${RM} ${NAME} 
	@make --no-print-directory -C ${LIBFT_P} fclean
	@$(foreach obj,${NAME},echo "File deleted: $(obj)";)

re:	fclean all

.PHONY: all clean fclean re
