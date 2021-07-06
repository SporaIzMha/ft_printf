/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:34:47 by marvin            #+#    #+#             */
/*   Updated: 2021/01/28 21:23:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_struct_pars
{
	int		width;
	int		precision;
	char	type;
	int		len;
	int		end;
	int		minus;
	int		zero;
}				t_struct_pars;

int				ft_printf(const char *s, ...);
int				parse_s(t_struct_pars *flags_struct, const char *s,
									int i, va_list ap);
int				flags_struct_fill(const char *s, va_list ap,
									t_struct_pars *flags_struct);
int				write_c_minus(char c, int blank);
int				write_c(char c, int zeros, int blank);
void			write_char(t_struct_pars *flags_struct, char c);
int				write_x_minus(int zeros, int blank, char *str_hex);
int				write_x(int zeros, int blank, char *str_hex);
int				reckon_zero_in_char(t_struct_pars *flags_struct,
								char *str_hex, int for_pointer);
int				reckon_blank_in_char(t_struct_pars *flags_struct, char *str_hex,
									int zeros, int for_pointer);
void			write_hexa(t_struct_pars *flags_struct, unsigned int digit);
int				reckon_z_in_integer(t_struct_pars *flags_struct, int digit);
int				reckon_s_in_integer(t_struct_pars *flags_struct,
									int digit, int zeros);
int				write_i(t_struct_pars *flags_struct, int digit, int zeros);
int				write_s_minus(int blank, char *s, int lg);
int				write_s(int zeros, int blank, char *s, int lg);
void			write_string(t_struct_pars *flags_struct, char *s);
int				ft_size_base(unsigned long long int digit, int len);
char			*itoa_for_hex(unsigned long long int digit, t_struct_pars
									*flags_struct);
int				len_unum(unsigned int i);
char			*ft_urevstring(char *str);
int				ft_usize(unsigned int num);
char			*ft_uitoa(unsigned int n);
void			write_integer(t_struct_pars *flags_struct, int digit);
int				write_p_minus(int zeros, int blank, char *str_pointer);
int				write_p(int zeros, int blank, char *str_pointer);
void			write_pointer(t_struct_pars *flags_struct, unsigned long
									long int pointer);
int				reckon_zero_str(t_struct_pars *flags_struct, int len);
int				reckon_space_str(t_struct_pars *flags_struct, int len);
char			*ft_unum_str(unsigned int n, unsigned int size);
int				write_u(t_struct_pars *flags_struct, unsigned int digit,
									int zeros);
int				reckon_z_in_uinteger(t_struct_pars *flags_struct,
									unsigned int digit);
int				reckon_s_in_uinteger(t_struct_pars *flags_struct,
									unsigned int digit, int zeros);
void			write_uinteger(t_struct_pars *flags_struct, unsigned int digit);

void			ft_putchar_fd(char c, int fd);
int				ft_isdigit(int ch);
size_t			ft_strlen(const char *str);
char			*ft_strdup(char *str);
int				type_there(char c);
int				numlen(int i);
void			new_struct_pars(t_struct_pars *flags_struct);
void			type_print(t_struct_pars *flags_struct, va_list ap);
void			write_blank(int blank, int *i);
void			precision_fill(t_struct_pars *flags_struct, const char *s,
									va_list ap, int *i);
void			star_fill(t_struct_pars *flags_struct, va_list ap);
void			width_fill(t_struct_pars *flags_struct, const char *s, int *i);
int				ft_atoi(const char *str);
char			*ft_itoa(int n);
void			ft_putstr_fd(char *s, int fd);

#endif
