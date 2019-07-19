/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 12:43:13 by shunt             #+#    #+#             */
/*   Updated: 2019/06/14 12:43:14 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *int_p(int e, char *man)
{
    char    *in;
    char    *tmp;
    int     i;

    if (!(in = (char *)malloc(sizeof(char) * 5001)))
        return (NULL);
    memset(in, '0', 5000);
    in[5000] = '\0';
    i = -1;
    while (--e > -1)
        if (man[++i] == '1')
        {
            if (!(tmp = pw_to_str(2, e)))
                return (NULL);
            in = str_ad(in, tmp);
        }
    return (in);
}