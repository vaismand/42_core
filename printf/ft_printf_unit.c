#include "ft_printf.h"

int ft_printf_unit(t_printf_flags *flags, int offset)
{
    if (flags->width_set && flags->precision_set)
    {
        if (flags->width_neg && !flags->precision_neg)
            return (flags->precision);
        else if (!flags->width_neg && flags->precision_neg)
            return (flags->padding_char == '0' ? flags->width - offset : 0);
        else if (flags->width_neg && flags->precision_neg)
            return (0);
        else
        {
            if (flags->padding_char == '0' && flags->precision == 0)
                return(flags->precision > flags->width ?
					ft_zero_if_neg(flags->width - offset) : flags->precision);
			else
				return (flags->precision);
        }
    }
    else if (flags->width_set && !flags->precision_set)
		return (!flags->width_neg && flags->padding_char == '0' ?
				flags->width - offset : 0);
	else if (!flags->width_set && flags->precision_set)
		return (!flags->precision_neg ? flags->precision : 0);
	return (0);
}