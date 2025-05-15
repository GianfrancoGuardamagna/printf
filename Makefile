NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SOURCE = ft_printf.c \
		ft_printchar.c \
		ft_printnbr.c \
		ft_printptr.c \
		ft_printstr.c \
		ft_printhex.c \
		ft_printunbr.c

OBJ = $(SOURCE:.c=.o)

INCLUDE = libftprintf.h

AR = ar rcs
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $@ $^

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re