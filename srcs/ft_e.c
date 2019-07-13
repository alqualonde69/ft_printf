/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_e.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 01:37:48 by shunt             #+#    #+#             */
/*   Updated: 2019/07/14 00:32:05 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len(int k)
{
	int		l;

	l = 4;
	while (k / 100)
	{
		++l;
		k /= 100;
	}
	return (l);
}

static int	ft_k(char *s)
{
	int		i;
	int		k;

	i = (s[0] == '-') ? 0 : -1;
	if (s[++i] != '0')
	{
		while (s[i] && s[i] != '.')
			++i;
		k = (s[0] == '-') ? i - 2 : i - 1;
	}
	else
	{
		i += 2;
		while (s[i] == '0')
			++i;
		k = (s[0] == '-') ? (i - 2) : (i - 1);
	}
	return (k);
}

static int	ft_r(char *r, char *s, int l, int a)
{
	int		i;
	int		j;

	r[l] = '\0';
	i = 0;
	while (s[i] && (s[i] == '-' || s[i] == '0' || s[i] == '.'))
		++i;
	j = 0;
	if (s[0] == '-')
		r[j++] = '-';
	r[j] = (!s[i]) ? '0' : s[i];
	r[++j] = '.';
	while (s[i] && s[++i])
	{
		if (s[i] != '.')
			r[++j] = s[i];
	}
	r[++j] = a ? 'e' : 'E';
	if (s[0] == '-')
		r[++j] = (s[1] == '0') ? '-' : '+';
	else
		r[++j] = (s[0] == '0') ? '-' : '+';
	return (j);
}

static void	ft_f(char *r, int k, int i, int l)
{
	if (k < 10)
	{
		r[++i] = '0';
		r[++i] = k + 48;
	}
	else
		while (k)
		{
			r[--l] = k % 10 + 48;
			k /= 10;
		}
}

char		*ft_e(long double e, int a)
{
	char	*s;
	char	*r;
	int		k;
	int		l;

	s = ft_fld(e, a);
	if (s[0] == 'i' || s[0] == 'I' || s[0] == 'n' ||
			s[0] == 'N' || s[1] == 'i' || s[1] == 'I')
		return (s);
	k = ft_k(s);
	l = ft_strlen(s) + ft_len(k);
	if (!(r = (char *)malloc(sizeof(char) * (l + 1))))
		return (NULL);
	ft_f(r, k, ft_r(r, s, l, a), l);
	free(s);
	return (r);
}
