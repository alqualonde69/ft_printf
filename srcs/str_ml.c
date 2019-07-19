/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_ml.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 08:07:39 by shunt             #+#    #+#             */
/*   Updated: 2019/06/14 08:07:41 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    str_ml(char *s1, int m)
{
    char    *tmp;
    int     i;

    if (!(tmp = (char *)malloc(sizeof(char) * (strlen(s1) + 1))))
        return ;
    i = -1;
    while (s1[++i])
        tmp[i] = s1[i];
    tmp[i] = '\0';
    if (m == 0)
        memset(s1, '0', strlen(s1));
    while (--m > 0)
        str_ad(s1, tmp);
}
