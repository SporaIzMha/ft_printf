/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_write_hex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:32:43 by marvin            #+#    #+#             */
/*   Updated: 2021/01/28 21:55:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_hexa(t_struct_pars *flags_struct, unsigned int digit)
{
	char	*str_hex;
	int		zeros;
	int		blank;
	int		i;

	if (flags_struct->precision == 0 && digit == 0)
		str_hex = ft_strdup("");
	else
		str_hex = itoa_for_hex(digit, flags_struct);
	zeros = reckon_zero_in_char(flags_struct, str_hex, 0);
	blank = reckon_blank_in_char(flags_struct, str_hex, zeros, 0);
	if (flags_struct->minus)
		i = write_x_minus(zeros, blank, str_hex);
	else
		i = write_x(zeros, blank, str_hex);
	flags_struct->len += i;
	free(str_hex);
}

int		write_x_minus(int zeros, int blank, char *str_hex)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (zeros--)
	{
		write(1, "0", 1);
		i++;
	}
	while (str_hex[j])
	{
		ft_putchar_fd(str_hex[j], 1);
		i++;
		j++;
	}
	while (blank--)
	{
		write(1, " ", 1);
		i++;
	}
	return (i);
}

int		write_x(int zeros, int blank, char *str_hex)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (blank--)
	{
		write(1, " ", 1);
		i++;
	}
	while (zeros--)
	{
		write(1, "0", 1);
		i++;
	}
	while (str_hex[j])
	{
		ft_putchar_fd(str_hex[j], 1);
		i++;
		j++;
	}
	return (i);
}

int		reckon_zero_in_char(t_struct_pars *flags_struct,
						char *str_hex, int for_pointer)
{
	int size;

	size = ft_strlen((const char *)str_hex);
	if (flags_struct->precision > size)
		return (flags_struct->precision - size);
	else if (!(flags_struct->minus) && flags_struct->precision == -1
						&& flags_struct->zero
		&& flags_struct->width > size + for_pointer)
		return (flags_struct->width - size - for_pointer);
	return (0);
}

int		reckon_blank_in_char(t_struct_pars *flags_struct, char *str_hex,
	int zeros, int for_pointer)
{
	int size;

	size = ft_strlen((const char *)str_hex);
	if (flags_struct->width > size + zeros + for_pointer)
		return (flags_struct->width - size - zeros - for_pointer);
	return (0);
}
