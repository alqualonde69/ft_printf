/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 16:12:16 by huller            #+#    #+#             */
/*   Updated: 2019/07/19 16:12:18 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    chck_nthng(const char *format, t_out *output, t_rd **read)
{
	char	*res;
	char	*tmp2;
	int		tmp;
	int		i;
	int		b;

	i = 0;
	b = -1;
	while (format[(*read)->smb_cnt] == 'l' || format[(*read)->smb_cnt] == 'h' ||
		format[(*read)->smb_cnt] == 'j' || format[(*read)->smb_cnt] == 'z' ||
			format[(*read)->smb_cnt] == 'L' || format[(*read)->smb_cnt] == 't')
		++(*read)->smb_cnt;
	tmp = (*read)->smb_cnt;
    if ((format[(*read)->smb_cnt] >= 'A' && format[(*read)->smb_cnt] <= 'Z') ||
        (format[(*read)->smb_cnt] >= 'a' && format[(*read)->smb_cnt] <= 'z'))
    {
        while (format[(*read)->smb_cnt] && format[(*read)->smb_cnt] != '%') {
            (*read)->smb_cnt++;
            i++;
        }
        if (!(res = (char *) malloc(sizeof(char) * (i + 1))))
            return ;
        res[i] = '\0';
        tmp--;
        while (++b < i)
            res[b] = format[++tmp];
        tmp2 = (*output).buf;
        (*output).buf = ft_bufjoin((*output).buf, res, (*output).cnt, i);
        free((void *)res);
        tmp2 ? free((void *) tmp2) : 0;
        --(*read)->smb_cnt;
		(*output).cnt += i;
    }
}

void    ft_put_percent(t_rd **read)
{
		(*read)->mod = (char *) malloc(sizeof(char) * 2);
		(*read)->mod[0] = '%';
		(*read)->mod[1] = '\0';
		(*read)->mod_smb = '%';
}