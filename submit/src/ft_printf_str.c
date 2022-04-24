/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byan <byan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 22:35:27 by byan              #+#    #+#             */
/*   Updated: 2022/01/16 23:41:14 by byan             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

void	put_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	print_str(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		put_str("(null)");
		return (6);
	}
	while (str[i])
	{
		print_char(str[i]);
		i++;
	}
	return (i);
}
