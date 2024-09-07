# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/29 23:25:19 by marvin            #+#    #+#              #
#    Updated: 2024/09/04 01:50:41 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
_BLUE=\033[0;34m
_ROSE=\x1b[38;5;213m
_NEW_BLUE=\x1b[38;5;80m
_NEW_YELLOW=\x1b[38;5;228m
_GREEN_BOLD=\033[1;32m
_LIGHT_GREY=\x1b[38;5;242m
_PURPLE_UNDER=\033[0;4m\x1b[38;5;093m

# Reset colors
_END=\033[0;0m


MAKEFLAGS += --no-print-directory
OPTIONS_PRINTED = /tmp/options_printed_${USER}

# MANDATORY FILES

SRC_DIR = src
PARS_DIR = $(SRC_DIR)/parsing

SRC_MAIN = \
	$(SRC_DIR)/game_init.c \
	$(SRC_DIR)/sanitize.c \
	$(SRC_DIR)/raycasting.c \
	$(SRC_DIR)/get_distance.c \
	$(SRC_DIR)/render.c \
	$(SRC_DIR)/mlx_pixel.c \
	$(SRC_DIR)/key_event.c \
	$(SRC_DIR)/trigo_utils.c \
	$(SRC_DIR)/move.c \
	$(SRC_DIR)/main.c

SRC_PARS = \
	$(PARS_DIR)/parsing_chars.c \
	$(PARS_DIR)/parsing_map.c \
	$(PARS_DIR)/parsing_map2.c \
	$(PARS_DIR)/parsing_sanitize.c \
	$(PARS_DIR)/parsing_struct.c \
	$(PARS_DIR)/parsing_utils.c \
	$(PARS_DIR)/parsing.c \
	$(PARS_DIR)/right_side.c \
	$(PARS_DIR)/parsing_utils2.c \
	$(PARS_DIR)/parsing_chars_utils.c

SRC = \
	$(SRC_MAIN) \
	$(SRC_PARS)


# BONUS FILES

SRC_DIR_BONUS = bonus/src
PARS_DIR_BONUS = $(SRC_DIR_BONUS)/parsing
SHOOT_DIR_BONUS = $(SRC_DIR_BONUS)/shoot
DOOR_DIR_BONUS = $(SRC_DIR_BONUS)/door

SRC_MAIN_BONUS = \
	$(SRC_DIR_BONUS)/game_init.c \
	$(SRC_DIR_BONUS)/sanitize.c \
	$(SRC_DIR_BONUS)/raycasting.c \
	$(SRC_DIR_BONUS)/get_distance.c \
	$(SRC_DIR_BONUS)/render.c \
	$(SRC_DIR_BONUS)/mlx_pixel.c \
	$(SRC_DIR_BONUS)/key_event.c \
	$(SRC_DIR_BONUS)/mouse_event.c \
	$(SRC_DIR_BONUS)/trigo_utils.c \
	$(SRC_DIR_BONUS)/main.c \
	$(SRC_DIR_BONUS)/fog.c \
	$(SRC_DIR_BONUS)/minimap.c \
	$(SRC_DIR_BONUS)/move.c

SRC_SHOOT_BONUS = \
	$(SHOOT_DIR_BONUS)/shoot_init.c \
	$(SHOOT_DIR_BONUS)/shoot_right.c \
	$(SHOOT_DIR_BONUS)/shoot_left.c \
	$(SHOOT_DIR_BONUS)/shoot.c \
	$(SHOOT_DIR_BONUS)/pistol_init.c \
	$(SHOOT_DIR_BONUS)/pistol.c

SRC_DOOR_BONUS = \
	$(DOOR_DIR_BONUS)/door_init.c \
	$(DOOR_DIR_BONUS)/render_doors.c \
	$(DOOR_DIR_BONUS)/render_doors_utils.c \
	$(DOOR_DIR_BONUS)/door_animations.c

SRC_PARS_BONUS = \
	$(PARS_DIR_BONUS)/parsing_chars.c \
	$(PARS_DIR_BONUS)/parsing_map.c \
	$(PARS_DIR_BONUS)/parsing_map2.c \
	$(PARS_DIR_BONUS)/parsing_sanitize.c \
	$(PARS_DIR_BONUS)/parsing_struct.c \
	$(PARS_DIR_BONUS)/parsing_utils.c \
	$(PARS_DIR_BONUS)/parsing.c \
	$(PARS_DIR_BONUS)/right_side.c \
	$(PARS_DIR_BONUS)/parsing_utils2.c \
	$(PARS_DIR_BONUS)/parsing_chars_utils.c

SRC_BONUS = \
	$(SRC_MAIN_BONUS) \
	$(SRC_PARS_BONUS) \
	$(SRC_SHOOT_BONUS) \
	$(SRC_DOOR_BONUS)

# MANDATORY OBJ

OBJ_DIR = src/obj
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

# BONUS OBJ

OBJ_DIR_BONUS = bonus/obj
OBJ_BONUS = $(patsubst $(SRC_DIR_BONUS)/%.c,$(OBJ_DIR_BONUS)/%.o,$(SRC_BONUS))

# MANDATORY

NAME = cub3D
INC = -I./headers -Iminilibx-linux

# BONUS

NAME_BONUS = cub3D_bonus
INC_BONUS = -I./bonus/headers  -Iminilibx-linux

# ALL

RM = rm -rf
CC = cc
CFLAGS = -Wall -Wextra -gdwarf-2 -O3 -Werror
LIBFT = libft/libft.a
LIB = -Lminilibx-linux -lmlx -lXext -lX11 -lm


all : $(NAME)

print_options : $(OPTIONS_PRINTED)

$(OPTIONS_PRINTED) :
	@ /bin/bash -c "echo"
	@ /bin/bash -c "echo -e \"$(_ROSE)Compiling options$(_END) :  $(CC) $(CFLAGS)\""
	@ /bin/bash -c "echo"
	@ touch $(OPTIONS_PRINTED)

$(NAME) : $(LIBFT) $(OPTIONS_PRINTED) $(OBJ_DIR) $(OBJ)
	@ /bin/bash -c "echo"
	@ /bin/bash -c "echo -e \"$(_PURPLE_UNDER)Configuration minilibx-linux$(_END)\""
	@ /bin/bash -c "echo"
	@ make -C minilibx-linux
	@ /bin/bash -c "echo"
	@ /bin/bash -c "echo -e \"$(_NEW_BLUE)Linking files creating binary $(NAME)$(_END)\""
	@ /bin/bash -c "echo -e \"$(CC) $(CFLAGS) $(notdir $(OBJ) $(LIBFT))\""
	@ $(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LIB) -o $(NAME)
	@ /bin/bash -c "echo"
	@ /bin/bash -c "echo -e \"$(_GREEN_BOLD)[DONE]$(_END)\"" 

$(OBJ_DIR) :
	@ mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@ /bin/bash -c "printf \"$(_BLUE)Compiling$(_END) %-21s --> %-21s\n\" $(notdir $<) $(notdir $@)"
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $(INC) -c $< -o $@

$(LIBFT) :
	@ /bin/bash -c "echo -e \"$(_NEW_YELLOW)Entering directory 'libft'$(_END)\""
	@ make -C libft all
	@ /bin/bash -c "echo -e \"$(_NEW_YELLOW)Leaving directory 'libft'$(_END)\""
	@ /bin/bash -c "echo"

clean :
	@ make -C libft clean
	@ /bin/bash -c "echo -e \"$(_LIGHT_GREY)Cleaning object files$(_END)\""
	@ $(RM) $(OBJ_DIR)
	@ $(RM) $(OBJ_DIR_BONUS)
	@ $(RM) $(OPTIONS_PRINTED)

fclean : clean
	@ /bin/bash -c "echo -e \"$(_LIGHT_GREY)Cleaning archive $(LIBFT) $(_END)\""
	@ $(RM) $(LIBFT)
	@ /bin/bash -c "echo -e \"$(_LIGHT_GREY)Cleaning binary$(_END)\""
	@ $(RM) $(NAME)
	@ $(RM) $(NAME_BONUS)

re : fclean all

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(LIBFT) $(OPTIONS_PRINTED) $(OBJ_DIR_BONUS) $(OBJ_BONUS)
	@ /bin/bash -c "echo"
	@ /bin/bash -c "echo -e \"$(_PURPLE_UNDER)Configuration minilibx-linux$(_END)\""
	@ /bin/bash -c "echo"
	@ make -C minilibx-linux
	@ /bin/bash -c "echo"
	@ /bin/bash -c "echo -e \"$(_NEW_BLUE)Linking files creating binary $(NAME)$(_END)\""
	@ /bin/bash -c "echo -e \"$(CC) $(CFLAGS) $(notdir $(OBJ_BONUS) $(LIBFT))\""
	@ $(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) $(LIB) -o $(NAME_BONUS)
	@ /bin/bash -c "echo"
	@ /bin/bash -c "echo -e \"$(_GREEN_BOLD)[DONE]$(_END)\""

$(OBJ_DIR_BONUS) :
	@ mkdir -p $@

$(OBJ_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c
	@ /bin/bash -c "printf \"$(_BLUE)Compiling$(_END) %-21s --> %-21s\n\" $(notdir $<) $(notdir $@)"
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $(INC_BONUS) -c $< -o $@
