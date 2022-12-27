/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitordiago <aitordiago@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:13:49 by aitlopez          #+#    #+#             */
/*   Updated: 2022/12/27 13:59:04 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_hex(unsigned int nb)
{
	int		cont;
	int		sub_ret;
	char	*s;

	cont = 0;
	sub_ret = 0;
	s = "0123456789abcdef";
	if (nb >= 16)
	{
		sub_ret = ft_printf_hex(nb / 16);
		if (sub_ret == -1)
			return (-1);
		cont = cont + sub_ret;
		sub_ret = ft_printf_hex(nb % 16);
		if (sub_ret == -1)
			return (-1);
		cont = cont + sub_ret;
	}
	else
	{
		if (write (1, &s[nb], 1) == -1)
			return (-1);
		cont++;
	}
	return (cont);
}

int	ft_printf_hexmay(unsigned int nb)
{
	int		cont;
	int		sub_ret;
	char	*s;

	cont = 0;
	sub_ret = 0;
	s = "0123456789ABCDEF";
	if (nb >= 16)
	{
		sub_ret = ft_printf_hexmay(nb / 16);
		if (sub_ret == -1)
			return (-1);
		cont = cont + sub_ret;
		sub_ret = ft_printf_hexmay(nb % 16);
		if (sub_ret == -1)
			return (-1);
		cont = cont + sub_ret;
	}
	else
	{
		if (write (1, &s[nb], 1) == -1)
			return (-1);
		cont++;
	}
	return (cont);
}
