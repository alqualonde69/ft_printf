/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 03:41:03 by shunt             #+#    #+#             */
/*   Updated: 2019/07/20 22:57:44 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		main()
{
    int a = printf("%s\n", 0);
	int b = ft_printf("%s\n", 0);
    printf("%d, %d\n", a, b);
	return (0);
}