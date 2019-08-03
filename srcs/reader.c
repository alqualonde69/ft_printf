/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 17:24:05 by huller            #+#    #+#             */
/*   Updated: 2019/06/18 17:24:07 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_k(t_rd **read, const char *format, va_list **ap, t_out *out)
{
	if (format[(*read)->smb_cnt] == 'o')
		chck_o(read, ap);
	else if (format[(*read)->smb_cnt] == 'b')
		chck_b(read, ap);
	else if (format[(*read)->smb_cnt] == 'x')
		chck_x(read, ap);
	else if (format[(*read)->smb_cnt] == 'X')
		chck_xu(read, ap);
	else if (format[(*read)->smb_cnt] == 'c' || format[(*read)->smb_cnt] == 'C')
		chck_c(read, ap);
	else if (format[(*read)->smb_cnt] == 'u' || format[(*read)->smb_cnt] == 'U')
	{
		if (format[(*read)->smb_cnt] == 'U')
			(*read)->size = 2;
		chck_u(read, ap);
	}
	else if (format[(*read)->smb_cnt] == '%')
		ft_put_percent(read);
	else
		chck_nthng(format, out, read);
}

void	ft_chck_mod(t_rd **read, const char *format, va_list **ap, t_out *out)
{
	(*read)->mod = NULL;
	(*read)->mod2 = NULL;
	(*read)->mod_smb = 0;
    if (format[(*read)->smb_cnt] == '*')
        (*read)->smb_cnt++;
	if (format[(*read)->smb_cnt] == 's' || format[(*read)->smb_cnt] == 'r')
		format[(*read)->smb_cnt] == 's' ? chck_sr(read, ap, 1) :
		chck_sr(read, ap, 0);
	else if (format[(*read)->smb_cnt] == 'd' || format[(*read)->smb_cnt] == 'i')
		format[(*read)->smb_cnt] == 'd' ? chck_di(read, ap, 1) :
		chck_di(read, ap, 0);
	else if (format[(*read)->smb_cnt] == 'f' || format[(*read)->smb_cnt] == 'F')
		format[(*read)->smb_cnt] == 'f' ? chck_f(read, ap, 1) :
		chck_f(read, ap, 0);
	else if (format[(*read)->smb_cnt] == 'e' || format[(*read)->smb_cnt] == 'E')
		format[(*read)->smb_cnt] == 'e' ? chck_e(read, ap, 1) :
		chck_e(read, ap, 0);
	else if (format[(*read)->smb_cnt] == 'g' || format[(*read)->smb_cnt] == 'G')
		format[(*read)->smb_cnt] == 'g' ? chck_g(read, ap, 1) :
		chck_g(read, ap, 0);
	else if (format[(*read)->smb_cnt] == 'p')
		chck_p(read, ap);
	else
		ft_k(read, format, ap, out);
	(*read)->prs < 0 ? (*read)->prs = 0 : 0;
}

void    ft_chck_size(t_rd **read, const char *format)
{
    (*read)->size = 0;
	if (format[(*read)->smb_cnt])
	{
		if (format[(*read)->smb_cnt] == 'l' &&
            format[(*read)->smb_cnt + 1] != 'l')
			(*read)->size |= LONG_INT;
		else if (format[(*read)->smb_cnt] == 'l' &&
		         format[(*read)->smb_cnt + 1] == 'l')
			(*read)->size |= LONG_LONG_INT;
		else if (format[(*read)->smb_cnt] == 'h' &&
                 format[(*read)->smb_cnt + 1] != 'h')
			(*read)->size |= SHORT_INT;
		else if (format[(*read)->smb_cnt] == 'h' &&
		         format[(*read)->smb_cnt + 1] == 'h')
			(*read)->size |= SIGNED_CHAR;
		else if (format[(*read)->smb_cnt] == 'j')
			(*read)->size |= INT_MAX;
		else if (format[(*read)->smb_cnt] == 'z')
			(*read)->size |= SIZE_T;
		else if (format[(*read)->smb_cnt] == 't')
			(*read)->size |= PTRDIFF_T;
		else if (format[(*read)->smb_cnt] == 'L')
			(*read)->size |= INT_64;
		while (format[(*read)->smb_cnt] == 'l' || format[(*read)->smb_cnt] == 'h' ||
			   format[(*read)->smb_cnt] == 'j' || format[(*read)->smb_cnt] == 'z' ||
			   format[(*read)->smb_cnt] == 'L' || format[(*read)->smb_cnt] == 't')
			++(*read)->smb_cnt;
	}
}

void    ft_chck_precision(t_rd **read, const char *format, va_list **ap)
{
    int     r;

    (*read)->prs = 6;
	(*read)->kostil = 0;
	if (format[(*read)->smb_cnt + 1])
	{
		if (format[(*read)->smb_cnt] == '.')
		{
			r = 0;
			if (format[++(*read)->smb_cnt] == '*')
				r = va_arg(**ap, int);
			while (format[(*read)->smb_cnt] >= '0' &&
			       format[(*read)->smb_cnt] <= '9')
			{
				r += format[(*read)->smb_cnt] - '0';
				if (format[(*read)->smb_cnt + 1] >= '0'
				    && format[(*read)->smb_cnt + 1] <= '9')
					r *= 10;
				(*read)->smb_cnt++;
			}
			if (r == 6)
				(*read)->kostil = 1;
			(*read)->prs = r;
		}
	}
}

void    ft_chck_wdth(t_rd **read, const char *format, va_list **ap)
{
    int     r;

    (*read)->width = 0;
	if (format[(*read)->smb_cnt + 1])
	{
		r = 0;
		if (format[(*read)->smb_cnt] == '*')
		{
			r = va_arg(**ap, int);
			(*read)->smb_cnt++;
			if (r < 0)
			{
				(*read)->flag |= F_MINUS;
				r *= -1;
			}
		}
		(*read)->width = r;
		if (format[(*read)->smb_cnt] >= '0'
		     && format[(*read)->smb_cnt] <= '9')
			r = 0;
		while (format[(*read)->smb_cnt] >= '0'
		        && format[(*read)->smb_cnt] <= '9')
		{
			r += format[(*read)->smb_cnt] - '0';
			if (format[(*read)->smb_cnt + 1] >= '0'
			    && format[(*read)->smb_cnt + 1] <= '9')
				r *= 10;
			(*read)->smb_cnt++;
		}
		(*read)->width = r;
	}
}

void    ft_chck_flags(t_rd **read, const char *format)
{
    (*read)->flag = 0;
    if ((*read)->smb_cnt < (*read)->strlen)
    {
    	while ((format[(*read)->smb_cnt] == '-' ||
		            format[(*read)->smb_cnt] == '+' ||
		            format[(*read)->smb_cnt] == ' ' ||
		            format[(*read)->smb_cnt] == '0' ||
		            format[(*read)->smb_cnt] == '#'))
    	{
    		if (format[(*read)->smb_cnt] == '+')
    			(*read)->flag |= F_PLUS;
    		else if (format[(*read)->smb_cnt] == '-')
    			(*read)->flag |= F_MINUS;
    		else if (format[(*read)->smb_cnt] == ' ')
    			(*read)->flag |= F_SPACE;
    		else if (format[(*read)->smb_cnt] == '0')
    			(*read)->flag |= F_ZERO;
    		else if (format[(*read)->smb_cnt] == '#')
    			(*read)->flag |= F_OCT;
    		++(*read)->smb_cnt;
    	}
    }
}
