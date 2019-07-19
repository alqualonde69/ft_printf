/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 01:37:28 by shunt             #+#    #+#             */
/*   Updated: 2019/06/04 01:37:43 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int  ft_tail(float f)
{
    int     t;
    float   b;
    char    c;
    int a;

    a = 0;
    t = (int)f;
    while ((b = (float)t) != f)
    {
        t = (int)f;
        c = t + '0';
        write(1, &c, 1);
        f = (f * 10) - ((float)t * 10);
        a++;
    }
    return (a);
}

int         ft_f(float f)
{
    float   b;
    int     t;
    int     a[2];
    char    c;

    a[0] = 0;
    while ((t = (int)f) != 0)
    {
        f /= 10;
        ++a[0];
    }
    f *= 10;
    a[1] = a[0];
    while (a[0]-- > 0)
    {
        t = (int)f;
        c = t + '0';
        write(1, &c, 1);
        f = (f * 10) - ((float)t * 10);
    }
    t = (int)f;
    if ((b = (float)t) != f)
    {
        write(1, ".", 1);
        a[1] += ft_tail(f);
    }
    return (a[1] + 1);
}