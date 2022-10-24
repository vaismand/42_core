#include "ft_printf.h"

void    ft_printf_flag_validate(t_printf_flags *flags, int *should_end)
{
	if (flags->valid)
		return ;
	flags->valid = (flags->width_set || flags->precision_set
					|| flags->hex_upper || flags->hashtag);
	flags->valid = flags->valid && flags->letter != '\0';
	*should_end = flags->letter == '\0';
}