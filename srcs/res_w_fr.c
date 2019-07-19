/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res_w_fr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 14:11:15 by shunt             #+#    #+#             */
/*   Updated: 2019/06/14 14:11:17 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *res_ne(char *fr, int i, int sign)
{
    char    *res;
    int     j;

    res = (sign) ? (char *) malloc(sizeof(char) * (5066 - i)) : (char *) malloc(sizeof(char) * (5065 - i));
    if (sign)
        res[5065 - i] = '\0';
    else
        res[5064 - i] = '\0';
    j = -1;
    if (sign)
        res[++j] = '-';
    res[++j] = '0';
    res[++j] = '.';
    i = 4936;
    while (fr[++i])
        res[++j] = fr[i];
    return (res);
}

char    *res_w_fr(int e, char *in, char *fr, int sign)
{
    char    *res;
    int     i;
    int     j;

    i = 0;
    while (in[i] == '0')
        ++i;
    if (e < 0)
        return (res_ne(fr, i, sign));
    res = (sign) ? (char *) malloc(sizeof(char) * (5066 - i - e)) : (char *) malloc(sizeof(char) * (5065 - i - e));
    if (sign)
        res[5065 - i - e] = '\0';
    else
        res[5064 - i - e] = '\0';
    j = -1;
    if (sign)
        res[++j] = '-';
    while (in[i])
        res[++j] = in[i++];
    res[++j] = '.';
    i = 4936 + e;
    while (fr[++i])
        res[++j] = fr[i];
    return (res);
}