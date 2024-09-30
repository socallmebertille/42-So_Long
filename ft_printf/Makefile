#Variables

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

#Sources et Objects

SRC_DIR = sources
SRCS =  $(wildcard $(SRC_DIR)/*.c)
OBJ_DIR = objets
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
HEADER = includes/ft_printf.h

#Rules

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(C_FLAGS) $(INCLUDES) -I./includes -c $< -o $@

clean: 
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean bonus re
