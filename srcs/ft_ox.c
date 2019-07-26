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

char *ft_ro(char **s, size_t prs, int l)
{
	char *r;
	int i;
	int j;

	if ((*s)[0] == '0' && !(*s)[1] && !prs)
	{

		if (!(r = (char *)malloc(sizeof(char) * 1)))
			return (NULL);
		r[0] = '\0';
		return (r);
	}
	if (!(r = (char *)malloc(sizeof(char) * (prs + 1))))
		return (NULL);
	r[prs] = '\0';
	i = -1;
	while (++i < (int)(prs - l))
		r[i] = '0';
	j = -1;
	while ((*s)[++j])
		r[i++] = (*s)[j];
	free(*s);
	return (r);
}

char    *ft_ox(u_int64_t o, int a, int b)
{
	char *s;

//    if (!o)
//    {
//        if (!(s = (char *)malloc(sizeof(char))))
//            return (NULL);
//        s[0] = '\0';
//        return (s);
//    }
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
