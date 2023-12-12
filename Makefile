# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgrimaud <jgrimaud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 20:12:27 by jgrimaud          #+#    #+#              #
#    Updated: 2023/12/12 20:46:16 by jgrimaud         ###   ########.fr        #
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
CFLAGS	=	-Wall -Wextra -Werror

SRC		=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
BSRC	=	ft_lstaddback_bonus.c ft_lstaddfront_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c

INC		=	libft.h

OBJ_DIR	=	obj/
OBJ		=	$(SRC:%.c=$(OBJ_DIR)%.o)
BOBJ	=  $(BSRC:%.c=$(OBJ_DIR)%.o)



# ---------------------------------- TARGETS -----------------------------------

all: $(NAME)

$(NAME): $(OBJ)
	ar -rc $@ $^

# This rule only generates one file, which allows to not relink (meaning it will
# not recompile every sources when a source changes).
# Can be called with `make obj/ft_strlen.o`
$(OBJ_DIR)%.o: %.c $(INC) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

re: fclean all

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

bonus: $(BOBJ)
	@make SRC="$(BSRC)"

print:
	@echo "\nSRC\n$(SRC)"
	@echo "\nOBJ\n$(OBJ)"
	@echo "\nINC\n$(INC)"
	@echo "\nBSRC\n$(BSRC)"
	@echo "\nBOBJ\n$(BOBJ)"

gdb:
	@make -s CFLAGS+="-g" fclean all bonus
	@gdb ./a.out -tui

vg:


# For unit-test (https://github.com/alelievr/libft-unit-test)
so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC) $(BSRC)
	gcc -nostartfiles -shared -o libft.so $(OBJ) $(BOBJ)
