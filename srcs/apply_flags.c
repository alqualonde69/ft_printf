/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 17:25:32 by huller            #+#    #+#             */
/*   Updated: 2019/06/24 17:25:34 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	ft_app_d_prs(t_rd **read)
{
	unsigned long		i;
	int 	            b;
	unsigned long 	    strlen;
	char 	            *res;
	char	            *tmp;

	i = 0;
	b = -1;
	if ((*read)->mod)
	{
		strlen = (*read)->mod[0] == '-' ? ft_strlen((*read)->mod) - 1 :
				ft_strlen((*read)->mod);
		if (!(*read)->prs && (*read)->mod[0] == '0' && !(*read)->mod[1] &&
			(*read)->kostil == 1)
		{
			if (!(res = (char *)malloc(sizeof(char) * 1)))
				return (0);
			res[0] = '\0';
			tmp = (*read)->mod;
			(*read)->mod = res;
			free((void *)tmp);
		}
		else if ((*read)->prs > strlen)
		{
			if (!(res = (char *)malloc(sizeof(char)*((*read)->prs + 1))))
				return (0);
			res[(*read)->prs] = '\0';
			if ((*read)->mod[0] == '-')
			{
				res[0] = '-';
				++b;
				while (i != ((*read)->prs - strlen - 1))
				{
					res[++b] = '0';
					++i;
				}
			}
			else
			{
				while (i != ((*read)->prs - strlen))
				{
					res[++b] = '0';
					++i;
				}
			}
			i = 0;
			(*read)->mod[0] == '-' ? (*read)->mod[0] = '0' : 0;
			while ((*read)->mod[i])
			{
				res[++b] = (*read)->mod[i];
				++i;
			}
			tmp = (*read)->mod;
			(*read)->mod = res;
			free((void *)tmp);
		}
	}
	return (1);
}

char 	*ft_bufjoin(char *s1, char *s2, int b1, int b2)
{
	char	*p;
	int		i;
	int		k;

	i = 0;
	k = -1;
	if (!s1 || !s2)
		return (0);
	if (!(p = (char *)malloc(sizeof(char) * (b1 + b2 + 1))))
		return (NULL);
	while (i < b1)
		p[i++] = *s1++;
	while (++k < b2)
		p[i++] = *s2++;
	p[i++] = '\0';
	return (p);
}

int 	ft_put_out(t_rd **read, t_out **output)
{
	unsigned long	i;
	int 	        b;
	unsigned long 	strlen;
	char 	        *res;
	char	        *tmp;

	i = 0;
	b = -1;
	b = -1;
	b = -1;
	if ((*read)->mod)
	{
		strlen = (*read)->zero ? ft_strlen((*read)->mod) + 1 : ft_strlen((*read)->mod);
		if (!(res = (char *) malloc(sizeof(char) * (strlen + 1))))
			return (0);
		res[strlen] = '\0';
		while ((*read)->mod[i])
		{
			res[++b] = (*read)->mod[i];
			++i;
		}
		tmp = (*output)->buf;
		(*output)->buf = ft_bufjoin((*output)->buf, res, (*output)->cnt, strlen);
		(*output)->cnt += strlen;
		free((void *)res);
		free((void *)tmp);
	}
	return (SUCCESS);
}

int    ft_app_width(t_rd **read)
{
	unsigned long 	strlen;
	unsigned long	i;
	int 	        b;
	char 	        *res;
	char	        *tmp;

	i = 0;
	b = -1;
	(*read)->sign = 0;
	if ((*read)->mod)
	{
		if ((*read)->width)
		{
			strlen = (*read)->zero ? ft_strlen((*read)->mod) + 1 : ft_strlen((*read)->mod);
			if ((*read)->width > strlen)
			{
				(*read)->sign = 1;
				if (!(res = (char *)malloc(sizeof(char)*((*read)->width) + 1)))
					return (0);
				res[(*read)->width] = '\0';
				if ((*read)->flag IS_MIN) /* if '-' */
				{
					if (((*read)->mod_smb == 'x' || (*read)->mod_smb == 'X') &&
							(*read)->flag IS_O)
					{
						b += 2;
						res[0] = ' ';
						res[1] = ' ';
					}
					else if (((*read)->mod_smb == 'o' && (*read)->flag IS_O))
					{
						b += 1;
						res[0] = ' ';
					}
					while ((*read)->mod[i])
					{
						res[++b] = (*read)->mod[i];
						++i;
					}
					while (++b < (*read)->width)
						res[b] = ' ';
					tmp = (*read)->mod;
					(*read)->mod = res;
					free((void *) tmp);
				}
				else if ((*read)->flag IS_ZE && !((*read)->flag IS_MIN) && ((!(*read)->prs ||
					((*read)->prs == 6 && !(*read)->kostil) || (*read)->mod_smb == 'f' ||
					(*read)->mod_smb == 'F' || (*read)->mod_smb == 'e' || (*read)->mod_smb == 'E' ||
						(*read)->mod_smb == 'g' || (*read)->mod_smb == 'G' ||
						(*read)->mod_smb == 'c' || (*read)->mod_smb == 's'))) /* if '0' */
				{
					if ((*read)->mod[0] == '-')
					{
						res[0] = '-';
						++b;
					}
					while (++i != ((*read)->width - strlen + 1))
						res[++b] = '0';
					(*read)->mod[0] == '-' ? (i = 0) : (i = -1);
					while ((*read)->mod[++i])
						res[++b] = (*read)->mod[i];
					tmp = (*read)->mod;
					(*read)->mod = res;
					free((void *)tmp);
				}
				else /* Whitout flags */
				{
					while (++i != ((*read)->width - strlen + 1))
						res[++b] = ' ';
					i = -1;
					while ((*read)->mod[++i])
						res[++b] = (*read)->mod[i];
					tmp = (*read)->mod;
					(*read)->mod = res;
				    free((void *)tmp);
				}

			}
		}
	}
	return (SUCCESS);
}

int    ft_app_fl(t_rd **read)
{
	unsigned long		i;
	int 	            b;
	unsigned long 	    strlen;
	char 	            *res;
	char	            *tmp;

	i = 0;
	b = 0;
	if ((*read)->mod)
	{
//		if ((*read)->flag IS_PL && (*read)->mod[0] != '-' && (*read)->mod_smb != 'u') /* '+' */
//		{
//			strlen = ft_strlen((*read)->mod);
//			if (!(res = (char *) malloc(sizeof(char) * (strlen + 2))))
//				return (0);
//			res[strlen + 1] = '\0';
//			res[0] = '+';
//			while ((*read)->mod[i])
//			{
//				res[++b] = (*read)->mod[i];
//				++i;
//			}
//			tmp = (*read)->mod;
//			(*read)->mod = res;
//			free((void *) tmp);
//		}
		if ((*read)->flag IS_SP && !((*read)->flag IS_PL) && (*read)->mod[0] != '-' && (*read)->mod_smb != 'u' &&
				!((*read)->flag IS_ZE) && (*read)->mod_smb != '%') /* ' ' */
		{
			strlen = ft_strlen((*read)->mod);
			if (!(res = (char *) malloc(sizeof(char) * (strlen + 2))))
				return (0);
			res[strlen + 1] = '\0';
			res[0] = ' ';
			while ((*read)->mod[i])
			{
				res[++b] = (*read)->mod[i];
				++i;
			}
			tmp = (*read)->mod;
			(*read)->mod = res;
			free((void *) tmp);
		}

	}
	return (SUCCESS);
}

int 	ft_add_pl(t_rd **read)
{
	unsigned long		i;
	int 	            b;
	unsigned long 	    strlen;
	char 	            *res;
	char	            *tmp;

	i = 0;
	b = 0;
	if ((*read)->mod)
	{
		if ((*read)->flag IS_PL && (*read)->mod[0] != '-' && (*read)->mod_smb != 'u') /* '+' */
		{
			if ((*read)->width && (*read)->sign)
			{
				if (!((*read)->flag IS_MIN))
				{
					while ((*read)->mod[b] == ' ')
						b++;
					(b) ? (*read)->mod[--b] = '+' : 0;
					(!b && (*read)->flag IS_ZE) ? ((*read)->mod[b] = '+') : 0;
				}
				else
				{
					strlen = ft_strlen((*read)->mod);
//				if ((*read)->mod[0] == ' ')
//				{
//					strlen--;
//					i++;
//				}
					if (!(res = (char *) malloc(sizeof(char) * (strlen + 1))))
						return (0);
					res[strlen] = '\0';
					/*((*read)->width) ? (res[b] = '+') : */(res[0] = '+');
					b = 0;
					while ((*read)->mod[i] && --strlen > 0)
					{
						res[++b] = (*read)->mod[i];
						++i;
					}
					tmp = (*read)->mod;
					(*read)->mod = res;
					free((void *) tmp);
				}
			}
			else
			{
				strlen = ft_strlen((*read)->mod);
//				if ((*read)->mod[0] == ' ')
//				{
//					strlen--;
//					i++;
//				}
				if (!(res = (char *) malloc(sizeof(char) * (strlen + 2))))
					return (0);
				res[strlen + 1] = '\0';
				((*read)->width) ? (res[b] = '+') : (res[0] = '+');
				b = 0;
				while ((*read)->mod[i]) {
					res[++b] = (*read)->mod[i];
					++i;
				}
				tmp = (*read)->mod;
				(*read)->mod = res;
				free((void *) tmp);
			}
		}
		if ((*read)->flag IS_O) /* '#' */
		{
			if ((*read)->mod_smb == 'o' && !((*read)->mod[0] == '0' && !(*read)->mod[1]))
			{
				if ((*read)->width && ((*read)->mod[0] == ' ' || (*read)->mod[0] == '0'))
				{
					while ((*read)->mod[i] == ' ')
						++i;
					if (i > 0)
						(*read)->mod[i - 1] = '0';
				}
				else
				{
					strlen = ft_strlen((*read)->mod);
					if (!(res = (char *) malloc(sizeof(char) * (strlen + 2))))
						return (0);
					res[strlen + 1] = '\0';
					res[0] = '0';
					while ((*read)->mod[i]) {
						res[++b] = (*read)->mod[i];
						++i;
					}
					tmp = (*read)->mod;
					(*read)->mod = res;
					free((void *) tmp);
				}

			}
			else if (((*read)->mod_smb == 'x' || (*read)->mod_smb == 'X') && !((*read)->mod[0] == '0'
											 && !(*read)->mod[1]) && (*read)->mod[0])
			{
				if ((*read)->width && (((*read)->mod[0] == ' ' && (*read)->mod[1] == ' ')
				|| ((*read)->mod[0] == '0' && (*read)->mod[1] == '0')))
				{
					if ((*read)->mod[i] == ' ')
					{
						while ((*read)->mod[i] == ' ')
							i++;
						(*read)->mod[i - 1] = (*read)->mod_smb == 'x' ? 'x' : 'X';
						(*read)->mod[i - 2] = '0';
					}
					else
						(*read)->mod[1] = (*read)->mod_smb == 'x' ? 'x' : 'X';
				}
				else
				{
					b = 1;
					strlen = ft_strlen((*read)->mod);
					if (!(res = (char *) malloc(sizeof(char) * (strlen + 3))))
						return (0);
					res[strlen + 2] = '\0';
					res[0] = '0';
					res[1] = (*read)->mod_smb == 'x' ? 'x' : 'X';
					while ((*read)->mod[i]) {
						res[++b] = (*read)->mod[i];
						++i;
					}
					tmp = (*read)->mod;
					(*read)->mod = res;
					free((void *) tmp);
				}
			}
		}
	}
	return (SUCCESS);
}

int    ft_solver(t_rd **read, t_out *output)
{
	if ((((*read)->mod_smb == 'd' || (*read)->mod_smb == 'i' || (*read)->mod_smb == 'u')
	    && ((*read)->prs)) || (!(*read)->prs && (*read)->mod[0] == '0' && !(*read)->mod[1]))
	{
		if (!(ft_app_d_prs(read)))
			return (0);
	}
	if ((*read)->mod_smb == 's' && ((*read)->prs))
	    if ((*read)->prs < ft_strlen((*read)->mod))
            (*read)->mod[(*read)->prs] = '\0';
	if (!(ft_app_fl(read)))
		return (0);
	if (!(ft_app_width(read)))
		return (0);
	if (!(ft_add_pl(read)))
		return (0);
	if (!(ft_put_out(read, &output)))
		return (0);
	return (1);
}