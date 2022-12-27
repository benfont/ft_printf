/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:55:03 by aitlopez          #+#    #+#             */
/*   Updated: 2022/12/27 14:02:16 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_str(char *s)
{
	int	cont;

	cont = 0;
	if (!s)
	{
		if (write (1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (s[cont])
	{
		if (write (1, &s[cont], 1) == -1)
			return (-1);
		cont++;
	}
	return (cont);
}
/*
int	main(void)
{
	char	s[] = "hola mundo\n";
	int		ret;
	ret = ft_printf_str(s);

	printf("esto es una string %d\n", ret);
}
*/
