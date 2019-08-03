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
	(*read)->prs < 0 ? (*read)->prs = 6 : 0;
	if ((*read)->size == 1 || !a)
    {
        (*read)->mod2 = (va_arg(**ap, wchar_t *));
        if (!(*read)->mod2)
        {
            (*read)->mod2 = (wchar_t *)malloc(sizeof(wchar_t) * 7);
            (*read)->mod2[0] = '(';
            (*read)->mod2[1] = 'n';
            (*read)->mod2[2] = 'u';
            (*read)->mod2[3] = 'l';
            (*read)->mod2[4] = 'l';
            (*read)->mod2[5] = ')';
            (*read)->mod2[6] = '\0';
        }
    }
	else
	    (*read)->mod = ft_s(va_arg(**ap, char *));
}
