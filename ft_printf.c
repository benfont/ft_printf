/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitor <aitor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:25:56 by aitlopez          #+#    #+#             */
/*   Updated: 2022/12/27 17:31:45 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
* ft_what_is
*
* identifica que tipo de dato queremos imprimir
*/

static int	ft_what_is(va_list lst, char c)
{
	if (c == 'c')
		return (ft_printf_char(va_arg(lst, int)));
	else if (c == 's')
		return (ft_printf_str(va_arg(lst, char *)));
	else if (c == 'p')
		return (ft_printf_ptr(va_arg(lst, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_printf_bsten(va_arg(lst, int)));
	else if (c == 'u')
		return (ft_printf_decs(va_arg(lst, unsigned int)));
	else if (c == 'x')
		return (ft_printf_hex(va_arg(lst, unsigned int)));
	else if (c == 'X')
		return (ft_printf_hexmay(va_arg(lst, unsigned int)));
	else if (c == '%')
	{
		if (write (1, "%", 1) == -1)
			return (-1);
		return (1);
	}
	return (0);
}

/* 
* ft_printing define
*
* tipo de conversion
* espacio de memoria que necesitaremos para imprimir
*/

static int	ft_printing(char const *str, va_list lst, int cont, int ret_tot)
{
	int	sub_ret;

	while (str[cont])
	{
		if (str[cont] == '%' && str[cont + 1])
		{
			sub_ret = ft_what_is(lst, str[cont + 1]);
			if (sub_ret == -1)
				return (-1);
			ret_tot = ret_tot + sub_ret;
			cont = cont + 2;
		}
		else
		{
			if (write (1, &str[cont], 1) == -1)
				return (-1);
			ret_tot++;
			cont++;
		}
	}	
	return (ret_tot);
}
/*
* ft_printf
*
* funcion principal
* contiene las variables que derivan a ft_printing define y ft_what_is   
*/

int	ft_printf(char const *str, ...)
{
	va_list	lst;
	int		cont;
	int		ret_tot;

	va_start(lst, str);
	cont = 0;
	ret_tot = 0;
	ret_tot = ft_printing(str, lst, cont, ret_tot);
	va_end(lst);
	return (ret_tot);
}
/*
int	main(void)
{
	int				k;
	char			*c;
	char			*d;
	unsigned int	h;
	void			*p;
	int				n;
	int				*i;

	k = 65;
	c = "hola";
	d = NULL;
	h = 2394732;
	p = &k;
	n = -214;
	i = 0;
	ft_printf("Esto es un char %c\n", k);
	ft_printf("Esto es una string %s\n", c);
	ft_printf("Esto es un null %s\n", d);
	ft_printf("Esto es un por ciento %%\n");
	ft_printf("esto es una prueba %u\n", -10);
	ft_printf("Esto es un hexadecimal mayuscula %X\n", h);
	ft_printf("Esto es un hexadecimal minuscula %x\n", h);
	ft_printf("Esta es la direccion de un puntero %p\n", p);
	ft_printf("Esto es un decimal %d\n", n);
	ft_printf("Esto es un entero %i\n", i);
	ft_printf("Esto es un puntero %p\n", &c);
	return (0);
}
*/
