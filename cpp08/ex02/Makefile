
GREEN	:= \033[0;32m
MAG		:= \033[0;35m
CYAN	:= \033[0;36m
RST		:= \033[0m

NAME	:= mutantStack
CC		:= c++
CFLAGS	:= -Wall -Wextra -Werror -std=c++98
BIN_DIR	:= bin
SRCS	:= main.cpp \
# 		   MutantStack.cpp

OBJS	:= $(patsubst %.cpp,$(BIN_DIR)/%.o,$(SRCS))

all: $(BIN_DIR) $(NAME)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

$(NAME): $(OBJS)
	@echo "Linking $(NAME)..."
	@$(CC) $(CFLAGS) -o $@ $^
	@echo "\n$(CYAN)----- $(MAG)❤ $(GREEN)$(NAME) compiled! $(MAG)❤ $(CYAN)-----$(RST)\n"

$(BIN_DIR)/%.o: %.cpp | $(BIN_DIR)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning objects..."
	@rm -rf $(BIN_DIR)

fclean: clean
	@echo "Cleaning executable..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re