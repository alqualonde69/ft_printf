/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_z.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 08:04:09 by shunt             #+#    #+#             */
/*   Updated: 2019/07/13 21:58:59 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*add_z(char *s, int z)
{
	int		i;

	i = 0;
	while (s[i] && !(s[i + 1] != '0'))
		++i;
	while (s[++i])
	{
		s[i - z] = s[i];
		s[i] = '0';
	}
	return (s);
}