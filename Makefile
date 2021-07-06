FLAGS 		= -Wall -Wextra -Werror

NAME		= libftprintf.a

SRC			= ft_printf.c ft_printf_write_unint.c ft_printf_write_string.c ft_printf_write_pointer.c \
			ft_printf_write_int.c ft_printf_write_hex.c ft_printf_write_char.c ft_printf_utils_unint.c \
			ft_printf_utils_type.c ft_printf_utils_struct.c ft_printf_utils_hex.c \
			ft_strlen.c ft_strdup.c ft_putchar_fd.c ft_atoi.c ft_isdigit.c ft_itoa.c ft_putstr_fd.c

OBJS 		= $(SRC:.c=.o)

all: 		$(NAME)

.c.o:
			gcc $(FLAGS) -I. -c $< -o $(<:.c=.o)

$(NAME): 	$(OBJS)
			@ar rcs $(NAME) $(OBJS)

clean:
			@rm -f $(OBJS)

fclean: 	clean
			@rm -f $(NAME)

re:			fclean all

.PHONY: 	all clean fclean re
