/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pw_to_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 08:08:51 by shunt             #+#    #+#             */
/*   Updated: 2019/06/14 08:08:53 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char  *pw_to_str(int a, int b)
{
    char  *s;
    int i;
    int tmp = a;
    if (!(s = (char *)malloc(sizeof(char) * 5001)))
        return (NULL);
    memset(s, '0', 5000);
    s[5000] = '\0';
    if (b == 0)
    {
        s[4999] = '1';
        return (s);
    }
    i = 5000;
    while (a)
    {
        s[--i] = (a % 10) + '0';
        a /= 10;
    }
    while (b-- > 1)
        str_ml(s, tmp);
    return (s);
}
