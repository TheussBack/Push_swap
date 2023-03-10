# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/09 14:19:48 by hrobin            #+#    #+#              #
#    Updated: 2023/03/09 23:31:28 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := push_swap
SRC_DIR        := src
BUILD_DIR:= .build
SRCS        :=     \
			parsing.c \
			utils.c \
			split.c \
			exit.c \
			uttils2.c \
			actions.c \
			actions2.c \
			push.c \
			sort_short.c \
			get_index.c \
			sort.c \
			free.c \
			main.c


SRCS        := $(SRCS:%=$(SRC_DIR)/%)
OBJS        := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS        := $(OBJS:.o=.d)

CC            := gcc -g3
CFLAGS        := -Wall -Wextra -Werror
CPPFLAGS    := -MMD -MP -I include
RM            := rm -f
MAKEFLAGS    += --no-print-directory
DIR_DUP        = mkdir -p $(@D)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)
	$(info CREATED $@)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -c $< -o $@
	$(info CREATED $@)

-include $(DEPS)

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: clean fclean re
