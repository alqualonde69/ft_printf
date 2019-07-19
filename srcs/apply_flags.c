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
		if ((*read)->prs > ft_strlen((*read)->mod))
		{
			strlen = ft_strlen((*read)->mod);
			if (!(res = (char *)malloc(sizeof(char)*((*read)->prs + 1))))
				return (0);
			res[strlen] = '\0';
			while (i != ((*read)->prs - strlen))
			{
				res[++b] = '0';
				++i;
			}
			i = 0;
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
		strlen = ft_strlen((*read)->mod);
		if (!(res = (char *) malloc(sizeof(char) * (strlen + 1))))
			return (0);
		res[strlen] = '\0';
		while ((*read)->mod[i])
		{
			res[++b] = (*read)->mod[i];
			++i;
		}
		tmp = (*output)->buf;
		(*output)->buf = ft_strjoin((*output)->buf, res);
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
	if ((*read)->mod)
	{
		if ((*read)->width)
		{
			strlen = ft_strlen((*read)->mod);
			if ((*read)->width > strlen)
			{
				if (!(res = (char *)malloc(sizeof(char)*((*read)->width) + 1)))
					return (0);
				res[(*read)->width] = '\0';
				if ((*read)->flag == 1) /* if '-' */
				{
					while ((*read)->mod[i])
					{
						res[++b] = (*read)->mod[i];
						++i;
					}
					while (res[++b])
						res[b] = ' ';
					tmp = (*read)->mod;
					(*read)->mod = res;
					free((void *) tmp);
				}
				else if ((*read)->flag == 16) /* if '0' */
				{
					while (++i != ((*read)->width - strlen + 1))
						res[++b] = '0';
					i = -1;
					while ((*read)->mod[++i])
						res[++b] = (*read)->mod[i];
					tmp = (*read)->mod;
					(*read)->mod = res;
					free((void *) tmp);
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
					free((void *) tmp);
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
		if ((*read)->flag == 2 && (*read)->mod[0] != '-')
		{
			strlen = ft_strlen((*read)->mod);
			if (!(res = (char *) malloc(sizeof(char) * (strlen + 2))))
				return (0);
			res[strlen + 1] = '\0';
			res[0] = '+';
			while ((*read)->mod[i])
			{
				res[++b] = (*read)->mod[i];
				++i;
			}
			tmp = (*read)->mod;
			(*read)->mod = res;
			free((void *) tmp);
		}
		if ((*read)->flag == 4 && (*read)->mod[0] != '-') /* ' ' flag */
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
//	вместо знака у положит чисел (если есть ширина, то не выводится)
//		;
		if ((*read)->flag == 8) /* '#' */
		{
			if ((*read)->mod_smb == 'o')
			{
				strlen = ft_strlen((*read)->mod);
				if (!(res = (char *) malloc(sizeof(char) * (strlen + 2))))
					return (0);
				res[strlen + 1] = '\0';
				res[0] = '0';
				while ((*read)->mod[i])
				{
					res[++b] = (*read)->mod[i];
					++i;
				}
				tmp = (*read)->mod;
				(*read)->mod = res;
				free((void *) tmp);

			}
			if ((*read)->mod_smb == 'x')
			{
				b = 1;
				strlen = ft_strlen((*read)->mod);
				if (!(res = (char *) malloc(sizeof(char) * (strlen + 3))))
					return (0);
				res[strlen + 2] = '\0';
				res[0] = '0';
				res[1] = 'x';
				while ((*read)->mod[i])
				{
					res[++b] = (*read)->mod[i];
					++i;
				}
				tmp = (*read)->mod;
				(*read)->mod = res;
				free((void *) tmp);
			}
			if ((*read)->mod_smb == 'X')
			{
				b = 1;
				strlen = ft_strlen((*read)->mod);
				if (!(res = (char *) malloc(sizeof(char) * (strlen + 3))))
					return (0);
				res[strlen + 2] = '\0';
				res[0] = '0';
				res[1] = 'X';
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
	}
	return (SUCCESS);
}

int    ft_solver(t_rd **read, t_out *output)
{
	if (((*read)->mod_smb == 'd' || (*read)->mod_smb == 'i') &&
		((*read)->prs))
	{
		if (!(ft_app_d_prs(read)))
			return (0);
	}
	if (!(ft_app_fl(read)))
		return (0);
	if (!(ft_app_width(read)))
		return (0);
	if (!(ft_put_out(read, &output)))
		return (0);
	return (1);
}