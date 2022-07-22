# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 18:34:29 by mbourgeo          #+#    #+#              #
#    Updated: 2022/07/19 04:31:29 by mbourgeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL	= all

PRIM_SRCS	=	main.c fractol.c check_input_1.c check_input_2.c edit_image.c mandelbrot.c mandelbrot_mod.c julia.c \
				newton.c events.c events_key_actions_1.c events_key_actions_2.c coord_manage.c initialize.c \
				color_convert.c color_manage.c color_sets.c zoom_manage.c utils_1.c utils_2.c utils_3.c utils_4.c \
				utils_5.c ft_printf.c ft_printf_utils_1.c ft_printf_utils_2.c
PRIM_SRCDIR	=	prim/src
PRIM_PATH	=	$(addprefix $(PRIM_SRCDIR)/, $(PRIM_SRCS))
PRIM_OBJDIR	=	prim/obj
PRIM_OBJS	=	$(patsubst $(PRIM_SRCDIR)/%, $(PRIM_OBJDIR)/%, $(PRIM_PATH:.c=.o))

DEP_DIR		=	prim/dep
PRIM_DEP	=	$(patsubst $(PRIM_OBJDIR)/%.o, $(DEP_DIR)/%.d, $(PRIM_OBJS))

HEADER_SRCS	=	fractol.h mlx.h
HEADER_DIR	=	includes
HEADER_PATH	=	$(addprefix $(HEADER_DIR)/, $(HEADER_SRCS))

INCL_DIR	=	includes
NAME		=	fractol
CC			=	gcc
RM			=	rm -rvf
MK			=	mkdir -p
#DEBUG.....=	-g3 -fsanitize=address
CFLAGS		=	-Wall -Wextra -Werror
DFLAGS		=	-MMD -MF
COPTIONS	=	-lXext -lX11 -lm
CLIBS		=	-Ilib/mlx -Llib/mlx -lmlx_Linux

#################################

all:		$(NAME)

$(NAME):	$(PRIM_OBJS) | Makefile
				$(CC) $^ $(CLIBS) -o $@ $(COPTIONS)

-include $(PRIM_DEP)
$(PRIM_OBJDIR)/%.o:		$(PRIM_SRCDIR)/%.c | $(PRIM_OBJDIR) $(DEP_DIR) $(HEADER_PATH)
							$(CC) $(CFLAGS) $(DEBUG) $(DFLAGS) $(DEP_DIR)/$*.d -c $< -o $@

$(PRIM_OBJDIR) $(DEP_DIR):		;
				@$(MK) $@

clean:		;
				@$(RM) $(PRIM_OBJDIR) $(DEP_DIR)

fclean:		clean
				@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
