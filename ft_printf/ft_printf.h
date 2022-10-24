/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvaisman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 09:57:16 by dvaisman          #+#    #+#             */
/*   Updated: 2022/10/24 14:53:22 by dvaisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>

# include "libft/libft.h"

# define FT_PRINTF_CHAR_FORMAT '%'
# define FT_PRINTF_SUPPORTED_FORMATS "cspdiuxX%"
# define FT_PRINTF_FD 1

typedef struct s_printf_settings
{
	int			written;
	int			fd;
	int			end;
	const char	*format;
	va_list		args;
}	t_printf_settings;

typedef struct s_printf_flags
{
	int		valid;
	int		side;
	int		minus_sign;
	int		width;
	int		zero;
	int		width_neg;
	int		width_set;
	int		precision;
	int		precision_set;
	int		precision_neg;
	int		hashtag;
	int		type;
	int		hex_upper;
	char	letter;
	char	padding_char;
}	t_printf_flags;

typedef struct s_printf_comb
{
	t_printf_settings	*settings;
	t_printf_flags		*flags;
	size_t				*i;
	int					len;
}	t_printf_comb;

char	*ft_printf_format_str(t_printf_comb *comb);
char	*ft_printf_format_char(t_printf_comb *comb);
char	*ft_printf_format_hex(t_printf_comb *comb);
char	*ft_printf_format_pointer(t_printf_comb *bundle);
char	*ft_printf_format_empty(t_printf_comb *bundle);
char	*ft_printf_format_percent(t_printf_comb *bundle);
char	*ft_printf_format_dec(t_printf_comb *bundle);
char	*ft_printf_format_octal(t_printf_comb *bundle);
char	*ft_printf_format_uint(t_printf_comb *bundle);
char	*ft_printf_flag_handle(t_printf_comb *bundle, char *formatted);
void	ft_printf_flag_def(t_printf_flags *flags);
void	ft_printf_putchar(t_printf_settings *settings, char c);
void	ft_printf_putstr(char *str, t_printf_settings *settings, int len);
void	ft_printf_flag_parse(t_printf_comb *bundle, size_t start, size_t end);
void	ft_printf_flag_validate(t_printf_flags *flags, int *should_end);
void	ft_printf_handle(t_printf_settings *settings);
void	ft_printf_format(t_printf_settings *settings, size_t *index);
void	*ft_printf_format_reg(char key);
void	ft_printf_format_process(t_printf_comb *bundle, \
		char *(*formatter)(t_printf_comb *));
int		ft_printf(const char *format, ...);
int		ft_printf_parse_flags(const char *format, t_printf_comb *bundle);
int		ft_printf_d(int fd, const char *format, ...);
int		ft_printf_unit(t_printf_flags *flags, int offset);
int		ft_printf(const char *format, ...);
int		ft_printf_flag_char(char c);

char	*g_formatter_key = FT_PRINTF_SUPPORTED_FORMATS;
char	*(*g_formatters[10])(t_printf_comb *) = {
	&ft_printf_format_char,
	&ft_printf_format_str,
	&ft_printf_format_pointer,
	&ft_printf_format_dec,
	&ft_printf_format_dec,
	&ft_printf_format_uint,
	&ft_printf_format_hex,
	&ft_printf_format_hex,
	&ft_printf_format_percent,
	&ft_printf_format_octal
};

#endif
