
NAME = push_swap

OBJ=$(SRC:.c=.o)

CC = cc
MAKE = make
CFLAG=-Wall -Wextra -Werror -g3

SRCS_DIR = ./src/
OBJ_DIR = ./objects/
INC_DIR = ./includes/
PARSE_DIR = $(SRCS_DIR)parsing/
OPE_DIR = $(SRCS_DIR)operations/
LIBFT_DIR = ./libft/

SRCS=push_swap.c check_error.c ft_push.c ft_reverse_rotate.c ft_rotate.c ft_swap.c initialization.c ft_tri.c ft_tri2.c

OBJ = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o)) 

INC_H = -I $(INC_DIR) -I $(LIBFT_DIR)/includes/

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(INC_H) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INC_H) -c -o $@ $<

$(OBJ_DIR)%.o: $(PARSE_DIR)%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INC_H) -c -o $@ $<

$(OBJ_DIR)%.o: $(OPE_DIR)%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INC_H) -c -o $@ $<

clean:
	rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all



.PHONY: all clean fclean re
