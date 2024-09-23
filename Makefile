NAME = so_long
CC = cc
FLAGS = -Wall -Wextra -Werror -g3
INCLUDES = -Iincludes
SRCS = 
OBJS = ${SRCS:.c=.o}
# BONUS_SRCS = bonus/   _bonus.c
# BONUS_OBJS = ${BONUS_SRCS:.c=.o}

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

all: ${NAME}

${NAME}: ${OBJS}
	@${CC} ${OBJS} -o ${NAME} || {echo "\n${RED} ============ ${ERROR} Linking failed ! ===================== ${NC}\n"; exit 1}
	@echo "${GREEN} ============ ${SUCCESS} Binary created ! ====================== ${RESET}"

# bonus: ${OBJS} ${BONUS_OBJS}
# 	@${CC} ${BONUS_OBJS} -o ${NAME} || (echo "\n${RED} ============ ${ERROR} Bonus linking failed ! ===================== ${NC}\n"; exit 1)
# 	@echo "${GREEN} ============ ${SUCCESS} Bonus compiled successfully! ================ ${RESET}"

.c.o:
	@${CC} ${FLAGS} ${INCLUDES} -c $< -o $@ || {echo "\n${RED} ============ ${ERROR} Compilation failed ! ==================== ${NC}\n"; exit 1}
	@echo "${GREEN} ============ ${SUCCESS} Successful compilation ! ================ ${RESET}"

clean:
	@rm -rf ${OBJS} ${BONUS_OBJS}
	@echo "${YELLOW} ============ ${CLEAN} Successful binary cleaning ! ============ ${RESET}"

fclean: clean
	@rm -rf ${NAME}
	@echo "${BOLD}${ORANGE} ============ ${REMOVE} Deleted executable ! ==================== ${RESET}"

re: fclean all
	@echo "${PURPLE} ============ ${REDO} Redo completed ! ======================== ${RESET}"

.PHONY: all clean fclean re