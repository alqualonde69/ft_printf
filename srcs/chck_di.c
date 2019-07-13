/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chck_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 00:16:00 by shunt             #+#    #+#             */
/*   Updated: 2019/07/13 22:01:55 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	chck_di(t_rd **read, va_list **ap, int a)
{
	(*read)->mod_smb = a ? 'd' : 'i';
	if ((*read)->size == 0)
		(*read)->mod = ft_d(va_arg(**ap, int));
	else if ((*read)->size == 1)
		(*read)->mod = ft_d(va_arg(**ap, long));
	else if ((*read)->size == 2)
		(*read)->mod = ft_d(va_arg(**ap, long long));
	else if ((*read)->size == 4)
		(*read)->mod = ft_d((short)va_arg(**ap, int));
	else if ((*read)->size == 8)
		(*read)->mod = ft_d((char)va_arg(**ap, int));
	else if ((*read)->size == 16)
		(*read)->mod = ft_d(va_arg(**ap, uintmax_t));
	else if ((*read)->size == 32 || (*read)->size == 64)
		(*read)->mod = ft_d(va_arg(**ap, ssize_t));
	else if ((*read)->size == 128)
		(*read)->mod = ft_d(va_arg(**ap, u_int64_t));
}
