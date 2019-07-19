/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 12:44:18 by shunt             #+#    #+#             */
/*   Updated: 2019/06/14 12:44:20 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *fr_p(int i, char *man)
{
    char    *fr;
    int     len;
    int     e;

    fr = (char *)malloc(sizeof(char) * 5001);
    memset(fr, '0', 5000);
    fr[5000] = '\0';
    len = strlen(man + i + 1);
    e = 1;
    while (man[++i])
    {
        if (man[i] == '1')
            str_ad(fr, add_z(pw_to_str(5, e), len - e));
        ++e;
    }
    return (fr);
}
