/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 00:07:30 by shunt             #+#    #+#             */
/*   Updated: 2019/07/13 23:27:47 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_k(int i, char *t, int a)
{
	int		k;

	k = i;
	while (t[--i] != '.')
		;
	if (k - i - 1 < a)
		zrs(t, a, i);
	else
		a ? rnd(t, a, i) : rnd_z(t, i);
}

char		*ft_round(char *s, int a)
{
	int		i;
	int		k;
	char	*t;
	char	*c;

	if (s[0] == 'i' || s[0] == 'I' || s[1] == 'i' || s[1] == 'I'
			|| s[0] == 'n' || s[0] == 'N')
		return (s);
	c = NULL;
	k = strlen(s);
	i = t_str(s, &t);
	if (k != i)
		c_str(s, &c, i, k);
	if (t[i - 1] != '.')
		ft_k(i, t, a);
	else
		e_zrs(t, a, i);
	s_str(&s, &t, &c);
	return (s);
}
