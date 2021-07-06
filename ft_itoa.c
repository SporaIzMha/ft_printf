/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:31:39 by marvin            #+#    #+#             */
/*   Updated: 2021/01/28 19:06:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_leni(int n)
{
	long		l;
	int			i;

	i = 1;
	l = n;
	if (n < 0)
	{
		l = -l;
		i++;
	}
	while (l / 10 > 0)
	{
		i++;
		l = l / 10;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	size_t		i;
	long		l;
	char		*r;

	i = ft_leni(n);
	l = n;
	if (!(r = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	r[i--] = 0;
	if (n < 0)
	{
		r[0] = '-';
		l = -l;
	}
	r[i--] = (l % 10) + '0';
	while (l / 10 > 0)
	{
		l = l / 10;
		r[i--] = (l % 10) + '0';
	}
	return (r);
}
