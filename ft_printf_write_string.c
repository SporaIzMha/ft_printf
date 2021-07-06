/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_write_string.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:34:22 by marvin            #+#    #+#             */
/*   Updated: 2021/01/28 21:57:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_string(t_struct_pars *flags_struct, char *s)
{
	int	lg;
	int	zeros;
	int	blank;
	int	i;

	if (!s)
	{
		s = "(null)";
	}
	if (flags_struct->precision >= 0 &&
			flags_struct->precision < (int)(ft_strlen((const char *)s)))
		lg = flags_struct->precision;
	else
		lg = ft_strlen((const char *)s);
	zeros = reckon_zero_str(flags_struct, lg);
	blank = reckon_space_str(flags_struct, lg);
	if (flags_struct->minus)
		i = write_s_minus(blank, s, lg);
	else
		i = write_s(zeros, blank, s, lg);
	flags_struct->len += i;
}

int		reckon_zero_str(t_struct_pars *flags_struct, int len)
{
	if (flags_struct->zero && !(flags_struct->minus) &&
			flags_struct->width > len)
	{
		return (flags_struct->width - len);
	}
	return (0);
}

int		write_s_minus(int blank, char *s, int lg)
{
	int i;

	i = 0;
	while (*s && lg--)
	{
		ft_putchar_fd(*s, 1);
		s++;
		i++;
	}
	while (blank--)
	{
		write(1, " ", 1);
		i++;
	}
	return (i);
}

int		write_s(int zeros, int blank, char *s, int lg)
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
		while (*s && lg--)
		{
			ft_putchar_fd(*s, 1);
			s++;
			i++;
		}
	}
	return (i);
}

int		reckon_space_str(t_struct_pars *flags_struct, int len)
{
	if (flags_struct->minus)
	{
		if (flags_struct->width > len)
			return (flags_struct->width - len);
	}
	else
	{
		if (!(flags_struct->zero) && (flags_struct->width > len))
			return (flags_struct->width - len);
	}
	return (0);
}
