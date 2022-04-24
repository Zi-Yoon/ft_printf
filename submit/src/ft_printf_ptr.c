/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byan <byan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 23:11:36 by byan              #+#    #+#             */
/*   Updated: 2022/01/17 23:14:53 by byan             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ptr_len(uintptr_t ptr)
{
	int	len;

	len = 0;
	while (ptr != 0)
	{
		len++;
		ptr = ptr / 16;
	}
	return (len);
}

void	put_ptr(uintptr_t ptr)
{
	if (ptr >= 16)
	{
		put_ptr(ptr / 16);
		put_ptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			print_char(ptr + '0');
		else
			print_char(ptr - 10 + 'a');
	}
}

int	print_ptr(unsigned long long ptr)
{
	int	len;

	len = 2;
	put_str("0x");
	if (ptr == 0)
		len += print_char('0');
	else
	{
		put_ptr(ptr);
		len += ptr_len(ptr);
	}
	return (len);
}
