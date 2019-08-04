/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rnd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 06:00:46 by shunt             #+#    #+#             */
/*   Updated: 2019/06/20 06:00:48 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//static void	rndel(char **s, int a, int i, int b)
//{
//	char    *t;
//	int     l;
//
//	if ((!(a % 2) && (a < 4 || a > 9)) || (a == 6 && !b))
//	{
//		if ((*s)[i + a + 1] < '5' || ((*s)[i + a + 1] == '5' &&
//									  !((*s)[i + a] % 2)))
//			(*s)[i + a + 1] = '\0';
//		else if ((*s)[i + a + 1] > '5' || ((*s)[i + a + 1] == '5' &&
//										   (*s)[i + a] % 2))
//		{
//			(*s)[i + a + 1] = '\0';
//			l = ft_strlen(*s);
//			t = (char *) malloc(sizeof(char) * (l + 1));
//			ft_memset(t, '0', l);
//			t[l] = '\0';
//			t[l - 1] = '1';
//			str_ad(s, t);
//			free(t);
//		}
//	}
//	else
//	{
//		if ((*s)[i + a + 1] < '5' || ((*s)[i + a + 1] == '5' &&
//									  (*s)[i + a] % 2))
//			(*s)[i + a + 1] = '\0';
//		else if ((*s)[i + a + 1] > '5' || ((*s)[i + a + 1] == '5' &&
//										   !((*s)[i + a] % 2))) {
//			(*s)[i + a + 1] = '\0';
//			l = ft_strlen(*s);
//			t = (char *) malloc(sizeof(char) * (l + 1));
//			ft_memset(t, '0', l);
//			t[l] = '\0';
//			t[l - 1] = '1';
//			str_ad(s, t);
//			free(t);
//		}
//	}
//}

void		rnd(char **s, int a, int i, int b)
{
    char    *t;
    int     l;

//    if ((*s)[i + a + 1] == '5')
//		return (rndel(s, a, i, b));
	if ((*s)[i + a + 1] < '5' || ((*s)[i + a + 1] == '5' &&
								  !((*s)[i + a] % 2)))
		(*s)[i + a + 1] = '\0';
	else if ((*s)[i + a + 1] > '5' || ((*s)[i + a + 1] == '5' &&
									   (*s)[i + a] % 2))
	{
		(*s)[i + a + 1] = '\0';
		l = ft_strlen(*s);
		t = (char *) malloc(sizeof(char) * (l + 1));
		ft_memset(t, '0', l);
		t[l] = '\0';
		t[l - 1] = '1';
		str_ad(s, t);
		free(t);
	}
}