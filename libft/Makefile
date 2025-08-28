# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/12 17:51:57 by tching            #+#    #+#              #
#    Updated: 2025/08/19 20:01:08 by tiara            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
       	  ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
       	  ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
       	  ft_calloc.c ft_strdup.c ft_toupper.c ft_tolower.c \
       	  ft_strchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
       	  ft_strnstr.c ft_atoi.c ft_strrchr.c ft_substr.c \
       	  ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
       	  ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_isspace.c \
       	  ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strcmp.c

SRCB	= ft_lstnew.c	ft_lstadd_front.c	ft_lstsize.c \
		  ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
		  ft_lstiter.c ft_lstmap.c ft_lstlast.c

OBJS    = $(SRCS:.c=.o)

OBJB  	= $(SRCB:.c=.o)

NAME	= libft.a

LIBC	= ar rcs

CC		= cc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -I.

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJS)
	$(LIBC) $(NAME) $(OBJS)

bonus:  $(OBJS) $(OBJB)
	$(LIBC) $(NAME) $(OBJS) $(OBJB)

clean:
	$(RM) $(OBJS) $(OBJB)

fclean:	clean
	$(RM) $(NAME) 

re:		fclean all

.PHONY:	all clean fclean re bonus
