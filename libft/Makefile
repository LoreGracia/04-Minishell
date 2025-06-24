# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/17 18:19:07 by lgracia-          #+#    #+#              #
#    Updated: 2025/06/12 13:12:39 by lgracia-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = libft.a

HEADER = ../inc/libft.h

FILES = ft_isprint.c ft_strjoin.c ft_strtrim.c ft_atoi.c ft_itoa.c ft_putendl_fd.c ft_strlcat.c ft_substr.c ft_bzero.c ft_memchr.c ft_putnbr_fd.c ft_strlcpy.c ft_tolower.c ft_calloc.c ft_memcmp.c ft_putstr_fd.c ft_strlen.c ft_toupper.c ft_isalnum.c ft_memcpy.c ft_split.c ft_strmapi.c ft_isalpha.c  ft_memmove.c ft_strchr.c ft_strncmp.c ft_isascii.c  ft_memset.c ft_strdup.c ft_strndup.c ft_strnstr.c ft_isdigit.c ft_putchar_fd.c ft_striteri.c ft_strrchr.c ft_strcmp.c ft_strchrpos.c #$(shell ls *.c)

OBJ = $(FILES:.c=.o)

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJBONUS = $(BONUS:.c=.o)

DEPS = $(FILES:.c=.d)

DEPSB = $(BONUS:.c=.d)


all: $(NAME)

-include $(DEPS)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

%.o:%.c Makefile
	$(CC) $(FLAGS) -MMD -c $< -o $@

clean:
	rm -fr $(OBJ)
	rm -fr $(DEPS)
	rm -fr $(DEPSB)
	rm -fr $(OBJBONUS)

fclean: clean
	rm -fr $(NAME)

re: fclean all

bonus: $(HEADER) $(OBJ) $(OBJBONUS)
	ar -rcs $(NAME) $(OBJ) $(OBJBONUS) 

-include $(DEPSB)

.PHONY: clean re fclean all
