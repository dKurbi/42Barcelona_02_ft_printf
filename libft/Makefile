# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkurcbar <dkurcbar@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 16:34:27 by dkurcbar          #+#    #+#              #
#    Updated: 2023/06/06 14:59:07 by dkurcbar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	:=	libft.a
HEADER	:=	libft.h
SRCS	:=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
			ft_strlcat.c ft_strlcpy.c ft_toupper.c ft_tolower.c ft_atoi.c \
			ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
			ft_strnstr.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
			ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
			
SRCS_B	:=	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
			ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c	

OBJS	:=	${SRCS:.c=.o}
OBJS_B	:=  ${SRCS_B:.c=.o}
CC		:=	gcc
CFLAGS	:=	-Wall -Werror -Wextra 
AR		:=	ar rcs
INCLUDE	:=	libft.h Makefile
RM		:=	rm -f
MODE	:=	normal

ifeq ($(MODE),debug)
	CFLAGS	+=	-g
endif

all: ${NAME}

${NAME}: ${OBJS}
	@${AR} ${NAME} $^ && echo "Library '${NAME}' created"

%.o: %.c ${INCLUDE}
	@${CC} -c ${CFLAGS} $< -o $@ && echo "Compiled: $< -> $@"

bonus :	.bonus
   
.bonus:	${OBJS} ${OBJS_B}
	@${AR} ${NAME} $^ && echo "Library '${NAME}' created with bonus"
	@touch $@ 

clean:	
	@${RM} ${SRCS:.c=.o} ${SRCS_B:.c=.o}
	@$(foreach obj,${OBJS},echo "File deleted: ${obj}";)
	@$(foreach obj,${OBJS_B},echo "File deleted: ${obj}";)

fclean:	clean
	@${RM} ${NAME} .bonus
	@$(foreach obj,${NAME},echo "File deleted: $(obj)";)

re:	fclean all

.PHONY: all clean fclean re
