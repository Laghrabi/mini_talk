CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c helpers.c put_idcs.c put_pXux.c specifiers.c 
AR = ar
ARFLAGS = rcs
NAME = libftprintf.a
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $^

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.SECONDARY: $(OBJS) $(SRCS)
