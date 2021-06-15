NAME	= libft.a

DIR_SRCS	= srcs
DIR_OBJS	= objs
SUBDIRS		= libft

SRCS_DIRS	= $(foreach dir, $(SUBDIRS), $(addprefix $(DIR_SRCS)/, $(dir)))
OBJS_DIRS	= $(foreach dir, $(SUBDIRS), $(addprefix $(DIR_OBJS)/, $(dir)))
SRCS		= $(foreach dir, $(SRCS_DIRS), $(FILES))
OBJS		= $(subst $(DIR_SRCS), $(DIR_OBJS), $(SRCS:.c=.o))

FILES = $(dir)/ft_atoi.c\
		$(dir)/ft_itoa.c\
		$(dir)/ft_bzero.c\
		$(dir)/ft_memcpy.c\
		$(dir)/ft_memset.c\
		$(dir)/ft_split.c\
		$(dir)/ft_strchr.c\
		$(dir)/ft_strclen.c\
		$(dir)/ft_strcmp.c\
		$(dir)/ft_strdel.c\
		$(dir)/ft_strdup.c\
		$(dir)/ft_strjoin_free.c\
		$(dir)/ft_strjoin.c\
		$(dir)/ft_strlcpy.c\
		$(dir)/ft_strlen_pointer.c\
		$(dir)/ft_strlen.c\
		$(dir)/ft_strndup.c\
		$(dir)/ft_strstr.c\
		$(dir)/ft_strtrim.c\
		$(dir)/ft_substr.c\
		$(dir)/get_next_line.c\
		$(dir)/ft_putendl.c\
		$(dir)/ft_putchar.c\
		$(dir)/ft_putstr.c\
		$(dir)/ft_calloc.c\
		$(dir)/ft_strsub.c


INCLUDES	= -I includes

CC		= clang
CFLAGS	= -Wall -Wextra -Werror
RM		= /bin/rm -f

$(DIR_OBJS)/%.o :	$(DIR_SRCS)/%.c
			@mkdir -p $(DIR_OBJS) $(OBJS_DIRS)
			@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			@ar -rcs $(NAME) $(OBJS)
			@ranlib $(NAME)

clean:
			@$(RM) $(OBJS)
			@$(RM) -r $(DIR_OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
