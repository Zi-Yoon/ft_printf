/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byan <byan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 23:11:37 by byan              #+#    #+#             */
/*   Updated: 2022/01/16 23:58:24 by byan             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	put_hex(unsigned int num, const char format)
{
	if (num >= 16)
	{
		put_hex(num / 16, format);
		put_hex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			print_char(num + '0');
		else
		{
			if (format == 'x')
				print_char(num - 10 + 'a');
			else
				print_char(num - 10 + 'A');
		}
	}
}

int	print_hex(unsigned int num, const char format)
{
	if (num == 0)
		return (print_char('0'));
	else
		put_hex(num, format);
	return (hex_len(num));
}
