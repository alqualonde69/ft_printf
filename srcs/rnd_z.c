/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rnd_z.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 10:04:30 by shunt             #+#    #+#             */
/*   Updated: 2019/07/13 23:56:25 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	rnd_z(char *s, int i)
{
	i = -1;
	while (s[++i] && s[i] != '.')
		;
	s[i] = '\0';
}
