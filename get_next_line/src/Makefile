# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: carperez <carperez@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/17 18:42:11 by carperez          #+#    #+#              #
#    Updated: 2023/06/17 18:42:11 by carperez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#colors
GREEN=\033[1;5;32m
YELLOW=\033[0;33m
BLUE=\033[1;34m
MAGENTA=\033[0;35m
CYAN=\033[0;36m
NC=\033[0m

#variable definition
NAME = get_next_line.a

#variable definition: paths
DIR_HEADER = ../header/
DIR_OBJ = ../obj/
DIR_BIN = ../bin/

#C files
FILES_MANDATORY = get_next_line.c get_next_line_utils.c
FILES_BONUS = get_next_line_bonus.c get_next_line_utils_bonus.c

#O files 
OBJECTS_MANDATORY = $(addprefix $(DIR_OBJ),$(FILES_MANDATORY:.c=.o))
OBJECTS_BONUS = $(addprefix $(DIR_OBJ),$(FILES_BONUS:.c=.o))

#commands 
COM_COMPILER = gcc
COM_FLAGS=  -Wall -Werror -Wextra -MD -I$(DIR_HEADER) 
COM_STATICLIB = ar rcs
COM_TEMPS = .cache_exists
COM_FOLDERS = mkdir -p
COM_REMOVE = rm -f

#DECLARATED tags
.PHONY:			all bonus clean fclean re

#CREATION temp folders
$(COM_TEMPS):
					@$(COM_FOLDERS) $(DIR_OBJ)
					@echo "${YELLOW}info [SUCCESS] temp folder for $(NAME) created.${NC}"

#CREATE static library
all:			$(NAME)
$(NAME):		$(OBJECTS_MANDATORY)
					@$(COM_FOLDERS) $(DIR_BIN)
					@$(COM_STATICLIB) $(DIR_BIN)$@ $^
					@echo "${YELLOW}info [SUCCESS] static library $@ created.${NC}"
bonus:			$(OBJECTS_MANDATORY) $(OBJECTS_BONUS)
					@$(COM_STATICLIB) $(DIR_BIN)$(NAME) $^
					@echo "${YELLOW}info [SUCCESS] static library $@ updated.${NC}"
#COMPILATION
$(DIR_OBJ)%.o:	%.c | $(COM_TEMPS)
					@$(COM_COMPILER) $(COM_FLAGS) -c $< -o $@
-include $(DIR_OBJ)%.d			

#REMOVE temp files
clean:
					@$(COM_REMOVE) -rf $(DIR_OBJ)
					@$(COM_REMOVE) -f $(COM_TEMPS)
					@echo "${BLUE}info [INFO] temp folders removed.${NC}"

#REMOVE static library
fclean: 		clean
					@$(COM_REMOVE) -rf $(DIR_BIN)
					@echo "${BLUE}info [INFO] static library $(NAME) removed.${NC}"

#CLEAN environmnet					
re: 			fclean all