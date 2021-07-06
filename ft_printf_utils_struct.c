/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_struct.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:31:57 by marvin            #+#    #+#             */
/*   Updated: 2021/01/28 22:01:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	new_struct_pars(t_struct_pars *flags_struct)
{
	flags_struct->minus = 0;
	flags_struct->zero = 0;
	flags_struct->width = -1;
	flags_struct->precision = -1;
	flags_struct->type = -1;
}

void	star_fill(t_struct_pars *flags_struct, va_list ap)
{
	flags_struct->width = va_arg(ap, int);
	if (flags_struct->width < 0)
	{
		flags_struct->minus = 1;
		flags_struct->width = flags_struct->width * (-1);
	}
}

void	precision_fill(t_struct_pars *flags_struct,
				const char *s, va_list ap, int *i)
{
	flags_struct->precision = 0;
	*i = *i + 1;
	if (ft_isdigit(s[*i]) || s[*i] == '-')
	{
		flags_struct->precision = ft_atoi(s + *i);
		while (ft_isdigit(s[*i]) || s[*i] == '-')
			*i = *i + 1;
		*i = *i - 1;
	}
	else if (s[*i] == '*')
		flags_struct->precision = va_arg(ap, int);
	else
	{
		*i = *i - 1;
	}
	if (flags_struct->precision < 0)
		flags_struct->precision = -1;
}

void	width_fill(t_struct_pars *flags_struct, const char *s, int *i)
{
	flags_struct->width = ft_atoi(s + *i);
	*i += numlen(flags_struct->width);
	if (flags_struct->width < 0)
	{
		flags_struct->minus = 1;
		flags_struct->width = flags_struct->width * (-1);
	}
}

void	write_blank(int blank, int *i)
{
	while (blank--)
	{
		write(1, " ", 1);
		*i = *i + 1;
	}
}
