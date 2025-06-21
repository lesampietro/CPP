# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/31 17:07:39 by lsampiet          #+#    #+#              #
#    Updated: 2025/06/21 15:21:02 by lsampiet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN	:= \033[0;32m
MAG		:= \033[0;35m
CYAN	:= \033[0;36m
RST		:= \033[0m

NAME	:= harlFilter
CC		:= c++
CFLAGS	:= -Wall -Wextra -Werror -std=c++98
SRC_DIR	:= src
INC_DIR	:= includes
BIN_DIR	:= bin
SRCS	:= main.cpp \
			$(SRC_DIR)/harlFilter.cpp

OBJS	:= $(patsubst $(SRC_DIR)/%.cpp,$(BIN_DIR)/%.o,$(SRCS))

all: $(BIN_DIR) $(NAME)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

$(NAME): $(OBJS)
	@echo "Linking $(NAME)..."
	@$(CC) $(CFLAGS) -o $@ $^
	@echo "\n$(CYAN)----- $(MAG)❤ $(GREEN)$(NAME) compiled! $(MAG)❤ $(CYAN)-----$(RST)\n"

$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BIN_DIR)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	@echo "Cleaning objects..."
	@rm -rf $(BIN_DIR)

fclean: clean
	@echo "Cleaning executable..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re