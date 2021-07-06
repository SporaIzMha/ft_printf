/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:34:38 by marvin            #+#    #+#             */
/*   Updated: 2021/01/28 21:23:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flags_struct_fill(const char *s, va_list ap, t_struct_pars *flags_struct)
{
	int size;

	size = 1;
	while (!(type_there(s[size])) && s[size + 1] != '\0')
	{
		if (s[size] == '-')
			flags_struct->minus = 1;
		else if (s[size] == '0')
			flags_struct->zero = 1;
		else if (s[size] == '*')
			star_fill(flags_struct, ap);
		else if (ft_isdigit(s[size]))
			width_fill(flags_struct, s, &size);
		else if (s[size] == '.')
			precision_fill(flags_struct, s, ap, &size);
		size++;
	}
	if (type_there(s[size]))
		flags_struct->type = s[size];
	flags_struct->end += size + 1;
	return (size + 1);
}

int	parse_s(t_struct_pars *flags_struct, const char *s, int size, va_list ap)
{
	flags_struct->len = 0;
	flags_struct->end = 0;
	while (s[size])
	{
		if (s[size] == '%')
		{
			new_struct_pars(flags_struct);
			size += flags_struct_fill(s + size, ap, flags_struct);
			type_print(flags_struct, ap);
		}
		else
		{
			write(1, &(s[size]), 1);
			size++;
		}
	}
	if (s[size] == '\n')
		ft_putchar_fd(s[size++], 1);
	return (flags_struct->len += size - flags_struct->end);
}

int	ft_printf(const char *s, ...)
{
	va_list			ap;
	int				size;
	t_struct_pars	*flags_struct;

	va_start(ap, s);
	if (!s)
		return (-1);
	size = 0;
	if (!(flags_struct = (t_struct_pars *)malloc(sizeof(t_struct_pars))))
		return (-1);
	size = parse_s(flags_struct, s, size, ap);
	va_end(ap);
	free(flags_struct);
	return (size);
}
