/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_hex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:31:22 by marvin            #+#    #+#             */
/*   Updated: 2021/01/28 22:01:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_size_base(unsigned long long int digit, int len)
{
	int reckon;

	if (!len)
	{
		return (0);
	}
	if (digit == 0)
	{
		return (1);
	}
	reckon = 0;
	while (digit)
	{
		digit /= len;
		reckon++;
	}
	return (reckon);
}

char	*itoa_for_hex(unsigned long long int digit, t_struct_pars *flags_struct)
{
	char	*string_x;
	char	*string_xx;
	int		size;
	char	*tmp;

	string_x = "0123456789abcdef";
	string_xx = "0123456789ABCDEF";
	size = ft_size_base(digit, 16);
	if (!(tmp = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	tmp[size] = '\0';
	if (flags_struct->type == 'x' || flags_struct->type == 'p')
		while (size--)
		{
			tmp[size] = string_x[digit % 16];
			digit /= 16;
		}
	else if (flags_struct->type == 'X')
		while (size--)
		{
			tmp[size] = string_xx[digit % 16];
			digit /= 16;
		}
	return (tmp);
}
