/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chck_sr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 00:16:00 by shunt             #+#    #+#             */
/*   Updated: 2019/07/13 22:07:32 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	chck_sr(t_rd **read, va_list **ap, int a)
{
	(*read)->mod_smb = a ? 's' : 'r';
	if ((*read)->size == 1 || !a)
		(*read)->mod2 = (va_arg(**ap, wchar_t *));
	else
		(*read)->mod = (va_arg(**ap, char *));
}
