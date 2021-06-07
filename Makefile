SRCS =	./srcs/liste_funzioni2_a.c \
		./srcs/liste_funzioni_a.c \
		./srcs/comandi.c \
		./srcs/lista_funzioni_b.c \
		./srcs/lista_funzioni2_b.c \
		./srcs/main.c \
		./srcs/comandi2.c \
		./srcs/comandi3.c \
		./srcs/atoi_mod.c \
		./srcs/index.c \
		./srcs/parsing.c \
		./srcs/split_list_b.c \
		./srcs/clean_index.c \
		./srcs/check_position.c \
		./srcs/check_position_b.c \
		./srcs/make_mosse.c \
		./srcs/correct_insert.c \
		./srcs/ordine_decrescente.c \
		./srcs/3_number.c \
		./srcs/5_number.c \
		./srcs/4_number.c
DIR = ./srcs/

NAME = pushswap

CC = gcc

FLAG = -Wall -Werror -Wextra

RM = rm -rf

OBJECT = ${SRCS:.c=.o}

all	:	$(NAME)

$(NAME)	:	$(OBJECT)
	$(CC) $(FLAG) $(OBJECT) -o $(NAME)

%.o	: %.c
	$(CC) $(FLAG) -c $< -o $@

clean: 
	$(RM) $(OBJECT)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

norminette:
	norminette $(SRCS)


#leaks --atExit -- ./a.out 