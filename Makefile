# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: carperez <carperez@student.45madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/20 12:47:21 by carperez          #+#    #+#              #
#    Updated: 2024/05/09 16:26:28 by carperez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#colors
GREEN=\033[1;5;32m
YELLOW=\033[0;33m
BLUE=\033[1;34m
MAGENTA=\033[0;35m
CYAN=\033[0;36m
NC=\033[0m

#variable definition:
PROGRAM = push_swap
NAME = push_swap.a
LIBFT = libft.a

#variable definition: paths
DIR_HEADER = header/
DIR_OBJ = obj/
DIR_BIN = bin/
DIR_SRC = src/
DIR_LIBFT_h = libft/$(DIR_HEADER)
DIR_LIBFT_s = libft/$(DIR_SRC)
DIR_LIBFT_a = libft/$(DIR_BIN)

#C files
FILES_SRC = 000-main.c 001-input_verification.c 002-sorting_verification.c\
			003-stack_update.c 004-stacks_management.c 005-push_operations.c\
			006-rotative_operations.c 007-swap_operations.c

#O files 
OBJECTS = $(addprefix $(DIR_OBJ),$(FILES_SRC:.c=.o))

#commands 
COM_COMPILER = gcc
COM_HEADERS = -I $(DIR_HEADER) -I $(DIR_LIBFT_h)
COM_FLAGS= -Wall -Werror -Wextra -fsanitize=address -MD $(COM_HEADERS)
COM_STATICLIB = ar rcs
COa_tempS = .cache_exists
COM_FOLDERS = mkdir -p
COM_REMOVE = rm -f

#DECLARATED tags
.PHONY: 		all bonus clean fclean re

#CREATION temp subfolders
$(COa_tempS):
					@$(COM_FOLDERS) $(DIR_OBJ)
					@echo "${YELLOW}info [SUCCESS] temp folder for $(NAME) created.${NC}"

#UPDATE static lib
all:			$(NAME) $(PROGRAM)
$(NAME):		$(OBJECTS)
					@$(COM_FOLDERS) $(DIR_BIN)
					@make -C $(DIR_LIBFT_s) --no-print-directory
					@cp $(DIR_LIBFT_a)$(LIBFT) $(DIR_BIN)
					@mv $(DIR_BIN)$(LIBFT) $(DIR_BIN)$@
					@$(COM_STATICLIB) $(DIR_BIN)$@ $<
					@echo "${YELLOW}info [SUCCESS] static library $@ created.${NC}"

#COMPILATION
$(DIR_OBJ)%.o:	$(DIR_SRC)%.c | $(COa_tempS)
					@$(COM_COMPILER) $(COM_FLAGS) -c $< -o $@
-include $(DIR_OBJ)%.d

#PROGRAM compilation
$(PROGRAM): $(OBJECTS) $(DIR_BIN)$(NAME) $(DIR_LIBFT_a)$(LIBFT)
					@$(COM_COMPILER) $(COM_FLAGS) $^ -o $@
					@echo "${GREEN}info [SUCCESS] $(PROGRAM) created.${NC}"

#REMOVE temp files
clean:
					@$(COM_REMOVE) -rf $(DIR_OBJ)
					@$(COM_REMOVE) -f $(COa_tempS)
					@make clean -C $(DIR_LIBFT_s) --no-print-directory
					@echo "${BLUE}info [INFO] temp folders removed.${NC}"

#REMOVE compilation
fclean:				clean
					@make fclean -C $(DIR_LIBFT_s) --no-print-directory
					@$(COM_REMOVE) -rf $(DIR_BIN)
					@$(COM_REMOVE) -f ./$(PROGRAM)
					@echo "${BLUE}info [INFO] static library $(NAME) removed.${NC}"
					@echo "${BLUE}info [INFO] $(PROGRAM) removed.${NC}"

#RECREATE static library and process	
re:				fclean all