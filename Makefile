NAME = so_long
CC = cc
FLAGS = -Wall -Wextra -Werror -g3

L_MLX = -L./minilibx-linux -lmlx -L/usr/lib/X11 -lXext -lX11
L_LIBFT = -L./libft -lft
L_FT_PRINTF = -L./ft_printf -lftprintf
INCLUDES = -I./includes -I./minilibx-linux

SRC_DIR = sources
SRCS =  $(SRC_DIR)/valid_map.c $(SRC_DIR)/so_long.c
OBJ_DIR = objets
OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

GREEN = \033[1;32m
RED = \033[1;31m
YELLOW = \033[1;33m
ORANGE = \033[38;5;214m
PURPLE = \033[1;35m
BOLD := \033[1m
RESET = \033[0m

SUCCESS = [ ✔ ]
ERROR = [ ✗ ]
CLEAN = [ ♻ ]
REMOVE = [ 🗑 ]
REDO = [ 🗘 ]

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft --no-print-directory
	@make -C ft_printf --no-print-directory
	@make -C minilibx-linux --no-print-directory
	@$(CC) $(OBJS) $(L_LIBFT) $(L_FT_PRINTF) $(L_MLX) -o $(NAME) || (echo "\n$(RED) ============ $(ERROR) Linking failed ! ===================== $(RESET)\n"; exit 1)
	@echo "$(GREEN) ============ $(SUCCESS) Binary created ! ====================== $(RESET)"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c includes/$(DEPS)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@ || (echo "\n$(RED) ============ $(ERROR) Compilation failed ! ==================== $(RESET)\n"; exit 1)
	@echo "$(GREEN) ============ $(SUCCESS) Successful compilation ! ================ $(RESET)"

clean:
	@make clean -C libft --no-print-directory
	@make clean -C ft_printf --no-print-directory
	@make clean -C minilibx-linux --no-print-directory
	@rm -rf $(OBJ_DIR)
	@echo "$(YELLOW) ============ $(CLEAN) Successful binary cleaning ! ============ $(RESET)"

fclean: clean
	@make fclean -C libft --no-print-directory
	@make fclean -C ft_printf --no-print-directory
	@rm -rf $(NAME)
	@echo "$(BOLD)$(ORANGE) ============ $(REMOVE) Deleted executable ! ==================== $(RESET)"

re: fclean all
	@echo "$(PURPLE) ============ $(REDO) Redo completed ! ======================== $(RESET)"

.PHONY: all clean fclean re