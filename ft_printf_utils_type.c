/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_type.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:32:13 by marvin            #+#    #+#             */
/*   Updated: 2021/01/28 21:59:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_print(t_struct_pars *flags_struct, va_list ap)
{
	if (flags_struct->type == 's')
		write_string(flags_struct, va_arg(ap, char *));
	if (flags_struct->type == 'c')
		write_char(flags_struct, va_arg(ap, int));
	if (flags_struct->type == 'd' || flags_struct->type == 'i')
		write_integer(flags_struct, va_arg(ap, int));
	if (flags_struct->type == '%')
		write_char(flags_struct, '%');
	if (flags_struct->type == 'u')
		write_uinteger(flags_struct, va_arg(ap, unsigned int));
	if (flags_struct->type == 'x')
		write_hexa(flags_struct, va_arg(ap, unsigned int));
	if (flags_struct->type == 'X')
		write_hexa(flags_struct, va_arg(ap, unsigned int));
	if (flags_struct->type == 'p')
		write_pointer(flags_struct, va_arg(ap, unsigned long long int));
}

int		type_there(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' ||
			c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int		numlen(int i)
{
	int j;

	j = 0;
	while (i / 10)
	{
		i /= 10;
		j++;
	}
	return (j);
}
