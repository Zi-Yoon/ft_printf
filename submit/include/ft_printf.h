/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byan <byan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 19:54:00 by byan              #+#    #+#             */
/*   Updated: 2022/04/24 20:22:04 by byan             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

int		ft_printf(const char *format, ...);
int		print_char(int c);
int		print_str(char *str);
int		print_dec(int n);
int		print_unsigned(unsigned int n);
int		print_hex(unsigned int num, const char format);
int		print_ptr(unsigned long long ptr);
void	put_str(char *str);

#endif
