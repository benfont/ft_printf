/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:27:23 by aitlopez          #+#    #+#             */
/*   Updated: 2022/12/27 14:01:13 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

/*
 * ft_printf_hexp
 * el dato recibido sera transformado a formato hexadecimal
 * ej: 127 -> 0x7f -> numeracion en base 16
*/

static int	ft_printf_hexp(unsigned long long nb)
{
	int		cont;
	int		sub_ret;
	char	*s;

	cont = 0;
	sub_ret = 0;
	s = "0123456789abcdef";
	if (nb >= 16)
	{
		sub_ret = ft_printf_hexp(nb / 16);
		if (sub_ret == -1)
			return (-1);
		cont = cont + sub_ret;
		sub_ret = ft_printf_hexp(nb % 16);
		if (sub_ret == -1)
			return (-1);
		cont = cont + sub_ret;
	}
	else
	{
		if (write (1, &s[nb], 1) - 1)
			return (-1);
		cont++;
	}
	return (cont);
}

/*
 * funcion principal
 * el argumento sera llevado a la funcion ft_printf_ptr
*/
int	ft_printf_ptr(void *p)
{
	int		cont;

	cont = 0;
	if (!p)
		return (ft_putstr("0x0"));
	if (write(1, "0x", 2) == -1)
		return (-1);
	return (ft_printf_hexp((unsigned long long) p) + 2);
}
