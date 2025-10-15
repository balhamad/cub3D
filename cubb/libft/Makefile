NAME = libft.a

SRCS = ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c\
	ft_isdigit.c\
	ft_isprint.c \
	ft_memset.c\
	ft_strlen.c\
	ft_bzero.c\
	ft_tolower.c\
	ft_strchr.c\
	ft_strrchr.c\
	ft_strncmp.c\
	ft_memcmp.c\
	ft_strnstr.c\
	ft_atoi.c\
	ft_calloc.c\
	ft_strlcpy.c\
	ft_strlcat.c\
	ft_toupper.c\
	ft_strdup.c\
	ft_memchr.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	ft_itoa.c\
	ft_substr.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_strmapi.c\
	ft_striteri.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_split.c\
	ft_printf.c\
	ft_pointer.c\
	ft_lowhexa.c\
	ft_unsigned.c\
	ft_uphexa.c\
	get_next_line.c

CFLAGS = -Wall -Werror -Wextra
OFILES = $(SRCS:.c=.o)


all: $(NAME)


%.o: %.c
	cc $(CFLAGS) -g -c $< -o $@
	
$(NAME): $(OFILES)
		ar rcs $@ $^
	
	
clean:
	rm -rf $(OFILES)
	
fclean: clean
		rm -rf $(NAME)
		
re: fclean all

.PHONY : all clean fclean re
