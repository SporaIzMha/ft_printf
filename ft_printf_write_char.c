/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_write_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:32:27 by marvin            #+#    #+#             */
/*   Updated: 2021/01/28 21:56:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		write_char(t_struct_pars *flags_struct, char c)
{
	int zeros;
	int blank;
	int i;

	zeros = reckon_zero_str(flags_struct, 1);
	blank = reckon_space_str(flags_struct, 1);
	i = 0;
	if (flags_struct->minus)
	{
		i = write_c_minus(c, blank);
	}
	else
	{
		i = write_c(c, zeros, blank);
	}
	flags_struct->len += i;
}

int			write_c_minus(char c, int blank)
{
	int i;

	i = 0;
	ft_putchar_fd(c, 1);
	i++;
	while (blank--)
	{
		write(1, " ", 1);
		i++;
	}
	return (i);
}

int			write_c(char c, int zeros, int blank)
{
	int i;

	i = 0;
	{
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
		ft_putchar_fd(c, 1);
		i++;
	}
	return (i);
}
