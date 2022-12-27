/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u_itoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitor <aitor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:46:40 by aitlopez          #+#    #+#             */
/*   Updated: 2022/12/27 17:53:01 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* ft_u_itoa
 *
 * convierte un numero entero en un texto
 * la cadena contendra tantos caracteres como digitos tenga el resultado 
*/
static int	ft_cifras(long nb)
{
	int	cifras;

	cifras = 0;
	while (nb > 0)
	{
		nb = nb / 10;
		cifras++;
	}
	return (cifras);
}

/*
 * static char
 * crea una string con tantos caracteres como digitos tenga la array
*/
static char	*ft_mayomen(char *s, int cifras, long m)
{
	if (m < 0)
	{
		s[0] = '-';
		m = m * -1;
	}
	while (m > 0)
	{
		s[cifras] = '0' + (m % 10);
		m = m / 10;
		cifras--;
	}
	return (s);
}

char	*ft_printf_u_itoa(unsigned int n)
{
	char			*s;
	int				cifras;
	unsigned int	m;

	m = n;
	cifras = ft_cifras(m);
	if (m == 0)
	{
		s = malloc(sizeof(char) * 2);
		if (!s)
			return (NULL);
		s[0] = '0';
		s[1] = '\0';
		return (s);
	}
	s = malloc(sizeof(char) * (cifras + 1));
	if (!s)
		return (NULL);
	s[cifras] = '\0';
	cifras--;
	s = ft_mayomen(s, cifras, m);
	return (s);
}
