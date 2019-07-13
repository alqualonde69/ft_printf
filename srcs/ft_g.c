/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_g.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 09:40:37 by shunt             #+#    #+#             */
/*   Updated: 2019/07/13 23:00:23 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_g(long double g, int a, int b)
{
	char	*f;
	char	*e;
	int		i;

	f = ft_fld(g, a);
	e = ft_e(g, a);
	i = -1;
	while (f[++i] && f[i] != '.')
		;
	i = f[0] == '-' ? --i : i;
	if (b < i)
	{
		free(f);
		return (ft_rg(e, b));
	}
	else
	{
		free(e);
		return (ft_rg(f, b));
	}
}
