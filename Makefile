# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/30 11:53:25 by pjimenez          #+#    #+#              #
#    Updated: 2023/12/04 18:27:07 by pjimenez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIB = push_swap.a
CC = gcc
CFLAGS	= -Wall -Werror -Wextra
RM	=	rm -f
AR	=	ar rcs

FILES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isdigit.c ft_split.c \
ft_strlen.c ft_substr.c main.c stack_fts.c utils.c swap_fts.c rotate_fts.c \
push_fts.c reverse_rotate_fts.c find_limits.c push_swap_fts.c ft_lstsize.c \
set_nodes.c sorts_fts.c moves_fts.c main.c

OBJ = $(FILES:.c=.o)

all:	$(NAME)

$(NAME):$(OBJ)
	@ar rcs $(LIB) $(OBJ) 
	@$(CC) $(CFLAGS) -o $(NAME) $(LIB)


clean:
	@$(RM) -rf $(OBJ)

fclean:		clean
			@$(RM) -f $(NAME) $(OBJ) $(LIB)

re:			fclean all
.PHONY:	all clean fclean re