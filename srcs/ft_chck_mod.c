/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chck_mod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 23:42:08 by shunt             #+#    #+#             */
/*   Updated: 2019/07/13 23:47:34 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_k(t_rd **read, const char *restrict format, va_list **ap)
{
	if (format[(*read)->smb_cnt] == 'o')
		chck_o(read, ap);
	else if (format[(*read)->smb_cnt] == 'b')
		chck_b(read, ap);
	else if (format[(*read)->smb_cnt] == 'x')
		chck_x(read, ap);
	else if (format[(*read)->smb_cnt] == 'X')
		chck_xu(read, ap);
	else if (format[(*read)->smb_cnt] == 'c')
		chck_c(read, ap);
}

void		ft_chck_mod(t_rd **read, const char *restrict format, va_list **ap)
{
	(*read)->mod = NULL;
	(*read)->mod2 = NULL;
	if (format[(*read)->smb_cnt] == 's' || format[(*read)->smb_cnt] == 'r')
		format[(*read)->smb_cnt] == 's' ? chck_sr(read, ap, 1) :
			chck_sr(read, ap, 0);
	else if (format[(*read)->smb_cnt] == 'd' || format[(*read)->smb_cnt] == 'i')
		format[(*read)->smb_cnt] == 'd' ? chck_di(read, ap, 1) :
			chck_di(read, ap, 0);
	else if (format[(*read)->smb_cnt] == 'f' || format[(*read)->smb_cnt] == 'F')
		format[(*read)->smb_cnt] == 'f' ? chck_f(read, ap, 1) :
			chck_f(read, ap, 0);
	else if (format[(*read)->smb_cnt] == 'e' || format[(*read)->smb_cnt] == 'E')
		format[(*read)->smb_cnt] == 'e' ? chck_e(read, ap, 1) :
			chck_e(read, ap, 0);
	else if (format[(*read)->smb_cnt] == 'g' || format[(*read)->smb_cnt] == 'G')
		format[(*read)->smb_cnt] == 'g' ? chck_g(read, ap, 1) :
			chck_g(read, ap, 0);
	else if (format[(*read)->smb_cnt] == 'p')
		chck_p(read, ap);
	else
		ft_k(read, format, ap);
}
