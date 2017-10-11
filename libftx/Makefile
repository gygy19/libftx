# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/25 15:18:38 by jguyet            #+#    #+#              #
#    Updated: 2016/07/12 19:17:15 by jguyet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftx.a

NAMEBASE    =   $(shell basename $(NAME) .a)

LENGTHNAME	=	`printf "%s" $(NAMEBASE) | wc -c`

MAX_COLS	=	$$(echo "$$(tput cols)-20-$(LENGTHNAME)"|bc)

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror -O3 -ggdb

SRCDIR		=	srcs/

OBJDIR		=	.objs/

INCDIR		=	includes/

SRCBASE		=	\
				libx_draw_line_to_img.c					\
				libx_new_img.c							\
				libx_put_pixel_to_img.c					\
				libx_new_line.c							\
				transform/transform.c					\
				transform/transform_look_at.c			\
				transform/transform_builder.c			\
				transform/transform_perspective.c		\
				transform/transform_rotation.c			\
				transform/transform_scale.c				\
				transform/transform_translation.c		\
				transform/transform_orientation.c		\
				model/model.c							\
				view/view.c								\
				mathf/ft_radians.c						\
				matrix4f/matrix4f.c						\
				vector2f/vector2f.c						\
				vector3f/vector3f.c						\
				vector4f/vector4f.c
				

SRCS		=	$(addprefix $(SRCDIR), $(SRCBASE))

OBJS		=	$(addprefix $(OBJDIR), $(SRCBASE:.c=.o))

.SILENT:

all:
	if test -f $(NAME) ; then												\
		echo "make: Nothing to be done for \`all\`.";						\
	else																	\
		$(MAKE) -j $(NAME);													\
	fi
$(NAME):	$(OBJDIR) $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
	echo "MAKE   [$(NAMEBASE)]"

$(OBJDIR):
	mkdir -p $(OBJDIR)
	mkdir -p $(dir $(OBJS))

$(OBJDIR)%.o : $(SRCDIR)%.c | $(OBJDIR)
	$(CC) $(FLAGS) -MMD -c $< -o $@											\
		-I $(INCDIR) 
	printf "\r\033[38;5;117m%s%*.*s\033[0m\033[K"							\
	"MAKE   "$(NAMEBASE)" plz wait ..."										\
		$(MAX_COLS) $(MAX_COLS) "($(@)))"

clean:
	if [[ `rm -R $(OBJDIR) &> /dev/null 2>&1; echo $$?` == "0" ]]; then		\
		echo -en "\r\033[38;5;101mCLEAN  "									\
		"[\033[0m$(NAMEBASE)\033[38;5;101m]\033[K";							\
	else																	\
		printf "\r";														\
	fi

fclean:		clean
	if [[ `rm $(NAME) &> /dev/null 2>&1; echo $$?` == "0" ]]; then			\
		echo -en "\r\033[38;5;124mFCLEAN "									\
		"[\033[0m$(NAMEBASE)\033[38;5;124m]\033[K";							\
	else																	\
		printf "\r";														\
	fi

re:			fclean all

.PHONY:		fclean clean re

-include $(OBJS:.o=.d)

.PHONY: all clean fclean re
