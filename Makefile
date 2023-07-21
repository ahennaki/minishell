# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/10 23:10:40 by aennaki           #+#    #+#              #
#    Updated: 2023/07/20 07:33:37 by aennaki          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = minishell
CFLAGS = -Wall -Werror -Wextra
SRC = libft/ft_atoi.c libft/ft_calloc.c libft/ft_itoa.c libft/ft_lstadd_back.c \
	libft/ft_lstadd_front.c libft/ft_lstnew.c libft/ft_lstsize.c libft/ft_memcmp.c \
	libft/ft_quotes.c libft/ft_split.c libft/ft_strchr.c libft/ft_strdup.c libft/ft_strjoin.c \
	libft/ft_strlen.c libft/ft_strtrim.c libft/ft_strrchr.c libft/ft_substr.c \
	main.c init_env.c parsing.c tokenize.c
		
OBJ = $(SRC:.c=.o)

RM = rm -rf

all : $(NAME)

%.o : %.c headers/minishell.h headers/libft.h
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $^ -o $(NAME) -lreadline

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re