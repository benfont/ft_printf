/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_decs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitor <aitor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:17:04 by aitlopez          #+#    #+#             */
/*   Updated: 2022/12/27 17:44:25 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * ft_print_bsten
 * 
 * imprime un entero en base 10 %i
 * ft_itoa -> convierte enteros en una string
 * ft_putstr -> escribe una secuencia de chars
*/

int	ft_printf_bsten(int nb)
{
	int		cont;
	char	*s;

	cont = 0;
	s = ft_printf_itoa(nb);
	cont = ft_putstr(s);
	free(s);
	return (cont);
}

/*
 * ft_print_decu
 *
 * imprime un numero decimal (base 10) %d
 * ft_u_itoa -> convierte un float en una string
 * ft_putstr -> escribe una secuencia de chars
*/

int	ft_printf_decs(unsigned int nb)
{
	int		cont;
	char	*s;

	cont = 0;
	s = ft_printf_u_itoa(nb);
	cont = ft_putstr(s);
	free(s);
	return (cont);
}
