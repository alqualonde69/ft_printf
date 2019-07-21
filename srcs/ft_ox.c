/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ox.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 01:37:04 by shunt             #+#    #+#             */
/*   Updated: 2019/07/11 02:02:32 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *ft_ox(u_int64_t o, int a, int b, size_t prs)
{
	char *s;

    if (!o && !prs)
    {
        if (!(s = (char *)malloc(sizeof(char))))
            return (NULL);
        s[0] = '\0';
        return (s);
    }
	if (a == 8)
	{
	    if (!(s = u_itoa_base(o, 8, 1)))
		    return (NULL);
	}
	else if (a == 16)
	{
		if (!(s = (b) ? u_itoa_base(o, 16, 1) : u_itoa_base(o, 16, 0)))
			return (NULL);
	}
	else if (a == 2)
		if (!(s = u_itoa_base(o, 2, 1)))
			return (NULL);
	return (s);
}
