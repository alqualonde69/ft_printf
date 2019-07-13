/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fld_edge.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 09:10:52 by shunt             #+#    #+#             */
/*   Updated: 2019/07/13 22:30:21 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*fld_edge(char **man, int sign, int c)
{
	int		i;

	if ((*man)[0] == '1' || ((*man)[0] == '1' && (*man)[1] == '1'))
	{
		i = (*man)[1] == '1' ? 1 : 0;
		while ((*man)[++i])
			if ((*man)[i] != '0')
				return (NULL);
		if ((*man)[1] == '1')
		{
			free(*man);
			return (c ? "nan" : "NAN");
		}
		else
		{
			free(*man);
			if (sign)
				return (c ? "-inf" : "-INF");
			else
				return (c ? "inf" : "INF");
		}
	}
	return (NULL);
}
