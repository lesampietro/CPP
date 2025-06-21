# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/31 17:07:39 by lsampiet          #+#    #+#              #
#    Updated: 2025/06/21 13:48:37 by lsampiet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN	:= \033[0;32m
MAG		:= \033[0;35m
CYAN	:= \033[0;36m
RST		:= \033[0m

NAME	:= hiBrain
CC		:= c++
CFLAGS	:= -Wall -Wextra -Werror -std=c++98
BIN_DIR	:= bin
SRC		:= main.cpp
OBJ		:= $(addprefix $(BIN_DIR)/, $(SRC:.cpp=.o))

all: $(BIN_DIR) $(NAME)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

$(NAME): $(OBJ)
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