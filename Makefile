# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/25 15:18:38 by jguyet            #+#    #+#              #
#    Updated: 2017/03/19 04:47:40 by jguyet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

STUDENT			=	jguyet

PROG1			=	fdf

NAMEBASE    	=   $(shell basename $(PROG1) .a)

LENGTHNAME		=	`printf "%s" $(NAMEBASE) | wc -c`

MAX_COLS		=	$$(echo "$$(tput cols)-21-$(LENGTHNAME)"|bc)

CC				=	gcc

FLAGS			=	-Wall -Wextra -Werror

SRCDIR			=

OBJDIR			=	.objs/

INCDIR			=	includes/

LIBFTDIR		=	libft/

INCDIRLIBFT		=	$(LIBFTDIR)/includes/

LIBFTXDIR		=	libftx/

INCDIRLIBFTX	=	$(LIBFTXDIR)/includes/

MINILIBXDIR		=	minilibx_macos/

INCDIRMINILIBX	=	$(MINILIBXDIR)/includes/

SRCSPROG1		=	\
					srcs/main.c																\
					srcs/render.c

DSRCSPROG1		=	$(addprefix $(SRCDIR), $(SRCSPROG1))

OBJSPROG1		=	$(addprefix $(OBJDIR), $(DSRCSPROG1:.c=.o))

OPENGL			=	-framework OpenGL -framework AppKit

.SILENT:

all:
	if test -f $(PROG1) ; then																\
		echo "make: Nothing to be done for \`all\`.";										\
	else																					\
		$(MAKE) -j $(STUDENT);																\
	fi

$(STUDENT):
	make -C $(LIBFTDIR)
	make -C $(LIBFTXDIR)
	make -C $(MINILIBXDIR)
	$(MAKE) $(PROG1)

$(PROG1):	$(OBJDIR) $(OBJSPROG1)
	$(CC) $(FLAGS) -o $(PROG1) $(OBJSPROG1) -L $(LIBFTDIR) -L $(LIBFTXDIR) -L $(MINILIBXDIR) -lftprintf -lftx -lmlx $(OPENGL)
	echo "MAKE    [$(PROG1)]"
	echo "\033[38;5;227mAUTHOR  :\033[0m"
	cat auteur

$(OBJDIR):
	mkdir -p $(OBJDIR)
	mkdir -p $(dir $(OBJSPROG1))

$(OBJDIR)%.o : $(SRCDIR)%.c | $(OBJDIR)
	$(CC) $(FLAGS) -MMD -c $< -o $@															\
		-I $(INCDIR) -I $(INCDIRLIBFT) -I $(INCDIRLIBFTX) -I $(INCDIRMINILIBX)
	printf "\r\033[38;5;117m%s\033[38;5;092m%*.*s\033[0m\033[K"								\
	"MAKE    "$(NAMEBASE)" plz wait ..."	$(MAX_COLS)	$(MAX_COLS)	"[$(@)]"

clean:
	echo -en "\r\033[38;5;101mCLEAN  "														\
		"[\033[0m$(NAMEBASE)\033[38;5;101m]\033[K\033[0m";									\
	rm -rf $(OBJDIR)
	make -C $(LIBFTDIR) clean
	make -C $(LIBFTXDIR) clean

fclean:
	echo -en "\r\033[38;5;124mFCLEAN "														\
		"[\033[0m$(NAMEBASE)\033[38;5;124m]\033[K\033[0m";									\
	rm -rf $(PROG1)
	rm -rf $(OBJDIR)
	make -C $(LIBFTDIR) fclean
	make -C $(LIBFTXDIR) fclean

cleanminilibx:
	make -C $(MINILIBXDIR) clean

re:			fclean all

.PHONY: all clean fclean re cleanminilibx
