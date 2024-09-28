NAME = so_long
CC = cc
FLAGS = -Wall -Wextra -Werror -MMD -MP

L_LIBFT = -L./libft -lft
L_FT_PRINTF = -L./ft_printf -lftprintf
L_MLX = -L./minilibx-linux -lmlx -L/usr/lib/X11 -lXext -lX11
INCLUDES = -I./minilibx-linux

SRC_DIR = sources
SRCS =  $(SRC_DIR)/valid_map.c $(SRC_DIR)/put_img.c $(SRC_DIR)/so_long.c
OBJ_DIR = objets
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEP_DIR = dependances
DEPS = $(SRCS:$(SRC_DIR)/%.c=$(DEP_DIR)/%.d)
-include $(DEPS)

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
	@$(CC) $(OBJS) -I./includes $(L_LIBFT) $(L_FT_PRINTF) $(L_MLX) -o $(NAME) || (echo "\n$(RED) ============ $(ERROR) Linking failed ! ====================================== $(RESET)\n"; exit 1)
	@echo "$(GREEN) ============ $(SUCCESS) Executable created ! ================================ $(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR) $(DEP_DIR)
	@$(CC) $(FLAGS) $(INCLUDES) -I./includes -c $< -o $@ -MF $(DEP_DIR)/$*.d || (echo "\n$(RED) ============ $(ERROR) Compilation failed ! ================================== $(RESET)\n"; exit 1)
	@echo "$(GREEN) ============ $(SUCCESS) Successful compilation ! ============================ $(RESET)"

clean:
	@make clean -C libft --no-print-directory
	@make clean -C ft_printf --no-print-directory
	@make clean -C minilibx-linux --no-print-directory
	@rm -rf $(OBJ_DIR) $(DEP_DIR)
	@echo "$(YELLOW) ============ $(CLEAN) Successful binary & dependances cleaning ! ============ $(RESET)"

fclean: clean
	@make fclean -C libft --no-print-directory
	@make fclean -C ft_printf --no-print-directory
	@rm -rf $(NAME)
	@echo "$(BOLD)$(ORANGE) ============ $(REMOVE) Deleted executable ! ================================= $(RESET)"

re: fclean all
	@echo "$(PURPLE) ============ $(REDO) Redo completed ! ======================================= $(RESET)"

.PHONY: all clean fclean re