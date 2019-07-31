/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 23:06:53 by shunt             #+#    #+#             */
/*   Updated: 2019/06/03 23:06:55 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *ft_c(wchar_t c, int a, t_rd **read)
{
    char    *s;
	(*read)->zero = !c ? 1 : 0;
    if (!a)
    {
        if (!(s = (char *)malloc(sizeof(char) * 2)))
            return (NULL);
        ft_memcpy(s, &c, 1);
        s[1] = '\0';
    }
    else
    {
        if (!(s = (wchar_t *)malloc(sizeof(wchar_t) * 2)))
            return (NULL);
        ft_memcpy(s, &c, 4);
        s[1] = '\0';
    }
    return (s);
}
