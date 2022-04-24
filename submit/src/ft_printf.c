/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byan <byan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:48:59 by byan              #+#    #+#             */
/*   Updated: 2022/04/24 20:26:19 by byan             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_formats(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len = print_char(va_arg(args, int));
	else if (format == '%')
		len = print_char('%');
	else if (format == 's')
		len = print_str(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		len = print_dec(va_arg(args, int));
	else if (format == 'u')
		len = print_unsigned(va_arg(args, int));
	else if (format == 'x' || format == 'X')
		len = print_hex(va_arg(args, unsigned int), format);
	else if (format == 'p')
		len = print_ptr(va_arg(args, unsigned long long));
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += check_formats(args, str[i + 1]);
			i++;
		}
		else
			len += print_char(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
