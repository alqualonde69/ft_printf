/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chck_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 00:16:00 by shunt             #+#    #+#             */
/*   Updated: 2019/07/13 22:01:22 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	chck_c(t_rd **read, va_list **ap)
{
	(*read)->mod_smb = 'c';
	if ((*read)->size == 1)
		(*read)->mod2 = ft_c(va_arg(**ap, wchar_t), 1, read);
	else
		(*read)->mod = ft_c(va_arg(**ap, int), 0, read);
}
