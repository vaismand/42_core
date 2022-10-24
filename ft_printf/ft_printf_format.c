#include "ft_printf.h"

#include "ft_printf.h"

#include "ft_printf.h"

char	*ft_printf_format_percent(t_printf_comb *bundle)
{
	ft_fake_use(&bundle);
	return (ft_chartostr('%'));
}

char	*ft_printf_formatter_empty(t_printf_comb *bundle)
{
	if (bundle->flags->precision_set)
		bundle->flags->precision_set = 0;
	if (bundle->flags->letter == '\0')
		return (ft_emptystr());
	bundle->len = 1;
	return (ft_chartostr(bundle->flags->letter));
}

void	ft_printf_format(t_printf_settings *settings, size_t *index)
{
	t_printf_flags	flags;
	void				*formatter;
	size_t				start;
	t_printf_comb	bundle;

	bundle = (t_printf_comb) { settings, &flags, index, -1 };
	start = *index;
	ft_printf_flag_def(&flags);
	while ((flags.letter = settings->format[*index]))
	{
		formatter = ft_printf_format_reg(flags.letter);
		if (formatter != NULL || !ft_printf_is_flag_char(flags.letter))
			break ;
		*index += 1;
	}
	if (start != *index)
		ft_printf_flag_parse(&bundle, start, *index);
	ft_printf_format_process(&bundle, formatter);
}

void	ft_printf_format_process(t_printf_comb *bundle,
							char *(*formatter)(t_printf_comb *))
{
	char	*str;

	if (formatter == NULL)
		formatter = &ft_printf_formatter_empty;
	*(bundle->i) += 1;
	str = (*(formatter))(bundle);
	str = ft_printf_flag_handle(bundle, str);
	ft_printf_putstr(str, bundle->settings, bundle->len);
	free(str);
}