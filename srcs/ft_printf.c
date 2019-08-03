/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 11:19:18 by shunt             #+#    #+#             */
/*   Updated: 2019/06/02 11:19:44 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_pt_frst(const char *format, t_out *output, t_rd **rd)
{
	char	*res;
	char	*tmp2;
	int		tmp;
	int		i;
	int		b;

	i = 0;
	b = -1;
	tmp = (*rd)->smb_cnt;
	while (format[(*rd)->smb_cnt] && format[(*rd)->smb_cnt] != '%')
	{
		(*rd)->smb_cnt++;
		i++;
	}
	if (!(res = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	res[i] = '\0';
	tmp--;
	while (++b < i)
		res[b] = format[++tmp];
	if (!(*output).buf)
		(*output).buf = ft_strnew(0);
	tmp2 = (*output).buf;
	(*output).buf = ft_bufjoin((*output).buf, res, (*output).cnt, i);
	free((void *)res);
	(*output).cnt += i;
	tmp2 ? free((void *)tmp2) : 0;
	return (SUCCESS);
}

void    ft_reader(t_rd **read, va_list *ap, const char *format, t_out *out)
{
	(*read)->zero = 0;
	format[(*read)->smb_cnt] == '%' ? ++(*read)->smb_cnt : 0;
	ft_chck_flags(read, format);
	ft_chck_wdth(read, format, &ap);
	ft_chck_precision(read, format, &ap);
	ft_chck_size(read, format);
	ft_chck_mod(read, format, &ap, out);
	if (((*read)->mod_smb == 'd' || (*read)->mod_smb == 'i' ||
	     (*read)->mod_smb == 's' || (*read)->mod_smb == 'u' ||
	     (*read)->mod_smb == 'p') && !(*read)->prs)
		(*read)->kostil = 3;
	else if (((*read)->mod_smb == 'd' || (*read)->mod_smb == 'i' ||
	    (*read)->mod_smb == 's' || (*read)->mod_smb == 'u' ||
	    (*read)->mod_smb == 'p') && (*read)->prs == 6 && (*read)->kostil != 1)
		(*read)->prs = 0;
}

void    ft_free_lists(t_rd **read)
{
	t_rd *tmp;

	while ((*read))
	{
		tmp = (*read);
		(*read)->mod ? free((*read)->mod) : 0;
		(*read)->mod2 ? free((*read)->mod2) : 0;
		*read = (*read)->prev;
		free(tmp);
	}
}

void	ft_putbuf(char *s, int b)
{
	int		i;

	i = -1;
	while (++i < b)
		write(1, &s[i], 1);
}

t_rd  *ft_newlist(t_rd **t)
{
	t_rd    *l;

	if (!(l = (t_rd *)malloc(sizeof(t_rd))))
		return (NULL);
	l->mod = NULL;
	l->mod2 = NULL;
	l->mod_smb = 0;
	l->zero = 0;
	l->kostil = 0;
	l->width = 0;
	l->flag = 0;
	l->prs = 6;
	l->size = 0;
	l->next = NULL;
	l->prev = *t;
	l->smb_cnt = 0;
	l->sign = 0;
	l->strlen = 0;
	return (l);
}

int ft_printf(const char *format, ...)
{
	t_printf	p;

	if (!(*format))
		return (0);
	p.output.cnt = 0;
	va_start (p.ap, format);
	p.output.buf = NULL;
	if (!(p.read = (t_rd *)malloc(sizeof(t_rd))))
		return (0);
	p.read->strlen = ft_strlen(format);
	p.read->smb_cnt = 0;
	p.read->prev = NULL;
	while (format[p.read->smb_cnt])
	{
		if (!(p.read->next = ft_newlist(&p.read)))
			return (0);
		if (!(ft_pt_frst(format, &p.output, &p.read)))
			return (0);
		ft_reader(&p.read, &p.ap, format, &p.output);
		if (!(ft_solver(&p.read, &p.output)))
			return (0);
		p.read = p.read->next;
		p.read->smb_cnt = p.read->prev->smb_cnt;
		p.read->strlen = p.read->prev->strlen;
        format[p.read->smb_cnt] ? ++p.read->smb_cnt : 0;
	}
	va_end(p.ap);
	ft_putbuf(p.output.buf, p.output.cnt);
	p.output.buf ? free(p.output.buf) : 0;
	ft_free_lists(&p.read);
	return (p.output.cnt);
}