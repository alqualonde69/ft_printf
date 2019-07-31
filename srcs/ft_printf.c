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

//void    ft_out_cnt(t_out *output)
//{
//	int i;
//	int b;
//
//	b = 0;
//	i = -1;
//	while ((output)->buf[++i])
//		++b;
//	output->output_cnt = b;
//}

int ft_pt_frst(const char *format, t_out *output, t_rd **rd)
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
	(*output).cnt += i;
	tmp--;
	while (++b < i)
		res[b] = format[++tmp];
	if (!(*output).buf)
		(*output).buf = ft_strnew(0);
	tmp2 = (*output).buf;
	(*output).buf = ft_strjoin((*output).buf, res);
	free((void *)res);
	tmp2 ? free((void *)tmp2) : 0;
//	format[(*rd)->smb_cnt] == '\0' ? (*rd)->smb_cnt-- : 0;
	return (SUCCESS);
}

void ft_reader(t_rd **read, va_list *ap, const char *format, t_out *out)
{
	(*read)->zero = 0;
	format[(*read)->smb_cnt] == '%' ? ++(*read)->smb_cnt : 0;
	ft_chck_flags(read, format);
	ft_chck_wdth(read, format, &ap);
	ft_chck_precision(read, format, &ap);
	ft_chck_size(read, format/*, &ap*/);
	ft_chck_mod(read, format, &ap, out);
	if (((*read)->mod_smb == 'd' || (*read)->mod_smb == 'i' ||
	    (*read)->mod_smb == 's' || (*read)->mod_smb == 'u') && (*read)->prs == 6 && (*read)->kostil != 1)
		(*read)->prs = 0;
}

void ft_free_lists(t_rd **read)
{
	t_rd *tmp;

	while ((*read)->prev)
	{
		tmp = (*read);
		*read = (*read)->prev;
		free(tmp);
	}
}

int		ft_putbuf(char *s, int b)
{
	int		i;

	i = -1;
	while (++i < b)
		write(1, &s[i], 1);
}

int ft_printf(const char *format, ...)
{
	t_printf	p;
	t_rd		*tmp;

	if (!(*format))
		return (0);
//	p.output.output_cnt = 0;
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
		if (!(p.read->next = (t_rd *)malloc(sizeof(t_rd))))
			return (0);
		if (!(ft_pt_frst(format, &p.output, &p.read)))
			return (0);
		ft_reader(&p.read, &p.ap, format, &p.output);
		if (!(ft_solver(&p.read, &p.output)))
			return (0);
		tmp = p.read;
		p.read = p.read->next;
		p.read->prev = tmp;
		p.read->smb_cnt = p.read->prev->smb_cnt;
		p.read->strlen = p.read->prev->strlen;
        format[p.read->smb_cnt] ? ++p.read->smb_cnt : 0;
	}
	va_end(p.ap);
//	ft_out_cnt(&p.output);
	ft_putbuf(p.output.buf, p.output.cnt);
	ft_free_lists(&p.read);
//	return (p.output.output_cnt);
	return (p.output.cnt);
}