/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitor <aitor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:40:30 by aitlopez          #+#    #+#             */
/*   Updated: 2022/12/27 17:53:06 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

/* MAIN PART */
int		ft_printf_char(int c);
int		ft_printf_decs(unsigned int nb);
int		ft_printf_hex(unsigned int nb);
char	*ft_printf_itoa(int n);
int		ft_printf_str(char *s);
char	*ft_printf_u_itoa(unsigned int n);
int		ft_printf(char const *str, ...);
int		ft_printf_ptr(void *p);
int		ft_printf_bsten(int nb);
int		ft_printf_hexmay(unsigned int nb);
int		ft_putstr(char *str);

#endif
