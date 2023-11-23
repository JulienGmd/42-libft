# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgrimaud <jgrimaud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 20:12:27 by jgrimaud          #+#    #+#              #
#    Updated: 2023/11/23 17:09:01 by jgrimaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



# ----------------------------------- NOTES ------------------------------------

# *.c							== *.c
# $(wildcard *.c)				== a.c b.c
# $(filter-out a c, a b c d)	== b d
# SRC = a.c b.c
# $(SRC:%.c=obj/%.o)			== obj/a.o obj/b.o

# |  : order-only-prerequisites (https://stackoverflow.com/a/38525905).
# $@ : target
# $< : 1st dependance
# $^ : all dependance



# ----------------------------------- PARAMS -----------------------------------

NAME	=	libft.a

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -I.

SRC_DIR		=	./
SRC			=	$(SRC_DIR)ft_atoi.c			\
				$(SRC_DIR)ft_bzero.c		\
				$(SRC_DIR)ft_calloc.c		\
				$(SRC_DIR)ft_isalnum.c		\
				$(SRC_DIR)ft_isalpha.c		\
				$(SRC_DIR)ft_isascii.c		\
				$(SRC_DIR)ft_isdigit.c		\
				$(SRC_DIR)ft_isprint.c		\
				$(SRC_DIR)ft_itoa.c			\
				$(SRC_DIR)ft_memchr.c		\
				$(SRC_DIR)ft_memcmp.c		\
				$(SRC_DIR)ft_memcpy.c		\
				$(SRC_DIR)ft_memmove.c		\
				$(SRC_DIR)ft_memset.c		\
				$(SRC_DIR)ft_putchar_fd.c	\
				$(SRC_DIR)ft_putendl_fd.c	\
				$(SRC_DIR)ft_putnbr_fd.c	\
				$(SRC_DIR)ft_putstr_fd.c	\
				$(SRC_DIR)ft_split.c		\
				$(SRC_DIR)ft_strchr.c		\
				$(SRC_DIR)ft_strdup.c		\
				$(SRC_DIR)ft_striteri.c		\
				$(SRC_DIR)ft_strjoin.c		\
				$(SRC_DIR)ft_strlcat.c		\
				$(SRC_DIR)ft_strlcpy.c		\
				$(SRC_DIR)ft_strlen.c		\
				$(SRC_DIR)ft_strmapi.c		\
				$(SRC_DIR)ft_strncmp.c		\
				$(SRC_DIR)ft_strnstr.c		\
				$(SRC_DIR)ft_strrchr.c		\
				$(SRC_DIR)ft_strtrim.c		\
				$(SRC_DIR)ft_substr.c		\
				$(SRC_DIR)ft_tolower.c		\
				$(SRC_DIR)ft_toupper.c		\

BSRC		=	$(SRC_DIR)ft_lstaddback_bonus.c		\
				$(SRC_DIR)ft_lstaddfront_bonus.c	\
				$(SRC_DIR)ft_lstclear_bonus.c		\
				$(SRC_DIR)ft_lstdelone_bonus.c		\
				$(SRC_DIR)ft_lstiter_bonus.c		\
				$(SRC_DIR)ft_lstlast_bonus.c		\
				$(SRC_DIR)ft_lstmap_bonus.c			\
				$(SRC_DIR)ft_lstnew_bonus.c			\
				$(SRC_DIR)ft_lstsize_bonus.c		\

INC_DIR		=	./
INC			=	$(INC_DIR)libft.h	\

OBJ_DIR		=	./
OBJ			=	$(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
BOBJ		=  $(BSRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

ifeq ($(shell realpath $(OBJ_DIR)), $(realpath .))
OBJ_DIR_IS_DOT = 1
else
OBJ_DIR_IS_DOT = 0
endif



# ----------------------------- PARAMS VALIDATION ------------------------------

# Make sure OBJ_DIR is a subfolder
ifneq ($(findstring $(realpath .), $(shell realpath $(OBJ_DIR))), $(realpath .))
$(error OBJ_DIR must be a subfolder or '.')
endif



# ---------------------------------- TARGETS -----------------------------------

all: $(NAME)

$(NAME): $(OBJ)
	ar -rc $@ $^

# This rule only generates one file, which allows to not relink (meaning it will
# not recompile every sources when a source changes).
# Can be called with `make obj/ft_strlen.o`
$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

re: fclean all

clean:
	rm -f $(OBJ) $(BOBJ)
# @if [ $(OBJ_DIR_IS_DOT) ]; then\
# 	rm -f $(OBJ) $(BOBJ);\
# else\
# 	rm -rf $(OBJ_DIR);\
# fi

fclean: clean
	rm -f $(NAME)

bonus: $(BOBJ)
	@make SRC="$(BSRC)"

print:
	@echo "SRC\n$(SRC)\n"
	@echo "OBJ\n$(OBJ)\n"
	@echo "INC\n$(INC)\n"
	@echo "BSRC\n$(BSRC)\n"
	@echo "BOBJ\n$(BOBJ)\n"

debug: CFLAGS += -g
debug: re
	gdb ./a.out -tui

# For unit-test (https://github.com/alelievr/libft-unit-test)
so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC) $(BSRC)
	gcc -nostartfiles -shared -o libft.so $(OBJ) $(BOBJ)
