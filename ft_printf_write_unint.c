/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_write_unint.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:34:30 by marvin            #+#    #+#             */
/*   Updated: 2021/01/28 21:55:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_uinteger(t_struct_pars *flags_struct, unsigned int digit)
{
	int	zeros;
	int	blank;
	int	i;

	zeros = reckon_z_in_uinteger(flags_struct, digit);
	blank = reckon_s_in_uinteger(flags_struct, digit, zeros);
	i = 0;
	if (flags_struct->minus)
	{
		i += write_u(flags_struct, digit, zeros);
		write_blank(blank, &i);
	}
	else
	{
		write_blank(blank, &i);
		i += write_u(flags_struct, digit, zeros);
	}
	flags_struct->len += i;
}

int		write_u(t_struct_pars *flags_struct, unsigned int digit, int zeros)
{
	char	*num;
	int		i;
	int		j;

	i = 0;
	j = 0;
	num = ft_uitoa(digit);
	while (zeros--)
	{
		write(1, "0", 1);
		i++;
	}
	while (num[j] && (flags_struct->precision || digit != 0))
	{
		ft_putchar_fd(num[j], 1);
		i++;
		j++;
	}
	free(num);
	return (i);
}

int		reckon_z_in_uinteger(t_struct_pars *flags_struct, unsigned int digit)
{
	int	lg_digit;

	if (flags_struct->precision == 0 && digit == 0)
		lg_digit = 0;
	else
		lg_digit = len_unum(digit) + 1;
	if (flags_struct->precision - lg_digit > 0)
		return (flags_struct->precision - lg_digit);
	else if (flags_struct->zero && !(flags_struct->minus) &&
				flags_struct->width - lg_digit >
				0 && flags_struct->precision < 0)
		return (flags_struct->width - lg_digit);
	return (0);
}

int		reckon_s_in_uinteger(t_struct_pars *flags_struct,
				unsigned int digit, int zeros)
{
	int	lg_digit;

	if (flags_struct->precision == 0 && digit == 0)
		lg_digit = 0;
	else
		lg_digit = len_unum(digit) + 1;
	if (flags_struct->width - lg_digit - zeros > 0)
		return (flags_struct->width - lg_digit - zeros);
	return (0);
}
