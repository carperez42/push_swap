# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: carperez <carperez@student.45madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/20 12:47:21 by carperez          #+#    #+#              #
#    Updated: 2024/05/13 17:17:36 by carperez         ###   ########.fr        #
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
BONUS = checker
NAME = push_swap.a
LIBFT = libft.a
GNL = get_next_line.a

#variable definition: paths
DIR_HEADER = header/
DIR_OBJ = obj/
DIR_BIN = bin/
DIR_SRC = src/
DIR_LIBFT_h = libft/$(DIR_HEADER)
DIR_LIBFT_s = libft/$(DIR_SRC)
DIR_LIBFT_a = libft/$(DIR_BIN)
DIR_GNL_h = get_next_line/$(DIR_HEADER)
DIR_GNL_s = get_next_line/$(DIR_SRC)
DIR_GNL_a = get_next_line/$(DIR_BIN)

#C files
FILES_SRC = 000-main.c 001-stack_initialitation.c 002-input_verification.c\
			003-sorting_verification.c 004-stack_update.c 005-stacks_management.c\
			006-push_operations.c 007-rotative_operations.c 008-swap_operations.c\
			009-checker.c

#O files
OBJECTS = $(addprefix $(DIR_OBJ),$(FILES_SRC:.c=.o))

#commands 
COM_COMPILER = gcc
COM_HEADERS = -I $(DIR_HEADER) -I $(DIR_LIBFT_h) -I $(DIR_GNL_h)
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
					@make -C $(DIR_GNL_s) --no-print-directory
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
$(PROGRAM): $(filter-out $(DIR_OBJ)009-checker.o,$(OBJECTS)) $(DIR_BIN)$(NAME) $(DIR_LIBFT_a)$(LIBFT)
					@$(COM_COMPILER) $(COM_FLAGS) $^ -o $@
					@echo "${GREEN}info [SUCCESS] $(PROGRAM) created.${NC}"

#BONUS tag
bonus:	 $(filter-out $(DIR_OBJ)000-main.o,$(OBJECTS)) $(DIR_LIBFT_a)$(LIBFT) $(DIR_GNL_a)$(GNL)
					@$(COM_COMPILER) $(COM_FLAGS) $^ -o $(BONUS) -g
					@echo "${GREEN}info [SUCCESS] $(BONUS) created.${NC}"

#REMOVE temp files
clean:
					@$(COM_REMOVE) -rf $(DIR_OBJ)
					@$(COM_REMOVE) -f $(COa_tempS)
					@make clean -C $(DIR_LIBFT_s) --no-print-directory
					@make clean -C $(DIR_GNL_s) --no-print-directory
					@echo "${BLUE}info [INFO] temp folders removed.${NC}"

#REMOVE compilation
fclean:				clean
					@make fclean -C $(DIR_LIBFT_s) --no-print-directory
					@make fclean -C $(DIR_GNL_s) --no-print-directory
					@$(COM_REMOVE) -rf $(DIR_BIN)
					@$(COM_REMOVE) -f ./$(PROGRAM)
					@$(COM_REMOVE) -f ./$(BONUS)
					@echo "${BLUE}info [INFO] static library $(NAME) removed.${NC}"
					@echo "${BLUE}info [INFO] $(PROGRAM) removed.${NC}"
					@echo "${BLUE}info [INFO] $(BONUS) removed.${NC}"

#RECREATE static library and process	
re:				fclean all bonus