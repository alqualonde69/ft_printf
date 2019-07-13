/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ox.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 01:37:04 by shunt             #+#    #+#             */
/*   Updated: 2019/07/13 23:12:31 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ox(u_int64_t o, int a, int b)
{
	char	*s;

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
	else
	{
		if (!(s = u_itoa_base(o, 2, 1)))
			return (NULL);
	}
	return (s);
}
