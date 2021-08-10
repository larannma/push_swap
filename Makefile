NAME		=	push_swap

SRCS_FILES	= 	${shell find ./source -name "*.c"}

UTILS_FILES	= 	${shell find ./utils -name "*.c"}

SRCS		= 	$(SRCS_FILES)
OBJS		=	$(patsubst %.c,%.o,$(SRCS))
SRCS_UTILS_FILES	=	$(UTILS_FILES)
OBJS_UTILS		=	$(patsubst %.c,%.o,$(SRCS_UTILS_FILES))

INCLUDE		=	-I./include/ -I./libs/libft/

LIB = ./libs/libft/libft.a

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

.PHONY:		all clean fclean re

all:		$(NAME)

%.o:		%.c
			$(CC) $(CFLAGS) $(INCLUDE) -c -g $< -o $@
		
$(NAME):	$(OBJS)
			$(MAKE) -C $(dir $(LIB))
			$(CC) $(INCLUDE) $(LIB) -o $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)
			@make -C $(dir $(LIB)) clean

fclean:		clean
			@make -C $(dir $(LIB)) fclean
			$(RM) $(NAME)

re:			fclean all