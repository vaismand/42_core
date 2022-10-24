LIBFT	= libft
LIBFT_LIB = libft.a
SRCS	= ft_printf.c \
			ft_printf_putchar.c \
			ft_printf_putstr.c \
			ft_printf_format.c \
			ft_printf_format_char.c \
			ft_printf_format_str.c \
			ft_printf_format_reg.c \
			ft_printf_parse_flags.c \
			ft_printf_d.c \
			ft_printf_unit.c \
			ft_printf_handle.c \
			ft_printf_flag_def.c \
			ft_printf_flag_handle.c \
			ft_printf_flag_validate.c \

OBJS	= ${SRCS:.c=.o}
NAME	= libftprintf.a
LIBC	= ar -rcs
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror
INCS 	= .
COMPILER = cc

.c.o:
	${COMPILER} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

${NAME}: ${OBJS}
	make all -C ${LIBFT}
	cp ${LIBFT}/${LIBFT_LIB} ${NAME}
	${LIBC} ${NAME} ${OBJS}

all: ${NAME}

fclean: clean
	${RM} ${NAME} ${bonus}
	make fclean -C ${LIBFT}
	
clean:
	${RM} -f ${OBJS} ${OBJS_B}
	make clean -C ${LIBFT}

re: fclean all

bonus: all