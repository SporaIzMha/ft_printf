/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_write_pointer.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:36:05 by marvin            #+#    #+#             */
/*   Updated: 2021/01/28 21:53:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_pointer(t_struct_pars *flags_struct, unsigned
					long long int pointer)
{
	char	*str_pointer;
	int		zeros;
	int		blank;
	int		i;

	if (flags_struct->precision == 0 && pointer == 0)
		str_pointer = ft_strdup("");
	else
		str_pointer = itoa_for_hex(pointer, flags_struct);
	zeros = reckon_zero_in_char(flags_struct, str_pointer, 2);
	blank = reckon_blank_in_char(flags_struct, str_pointer, zeros, 2);
	if (flags_struct->minus)
		i = write_p_minus(zeros, blank, str_pointer);
	else
		i = write_p(zeros, blank, str_pointer);
	free(str_pointer);
	flags_struct->len += i;
}

int		write_p_minus(int zeros, int blank, char *str_pointer)
{
	int	i;
	int j;

	i = 2;
	j = 0;
	while (zeros--)
	{
		write(1, "0", 1);
		i++;
	}
	ft_putstr_fd("0x", 1);
	while (str_pointer[j])
	{
		ft_putchar_fd(str_pointer[j], 1);
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

int		write_p(int zeros, int blank, char *str_pointer)
{
	int	i;
	int	j;

	i = 2;
	j = 0;
	while (blank--)
	{
		write(1, " ", 1);
		i += 1;
	}
	ft_putstr_fd("0x", 1);
	while (zeros--)
	{
		write(1, "0", 1);
		i += 1;
	}
	while (str_pointer[j])
	{
		ft_putchar_fd(str_pointer[j], 1);
		i++;
		j++;
	}
	return (i);
}
