/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 22:49:05 by shunt             #+#    #+#             */
/*   Updated: 2019/06/02 22:50:07 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>                     // FOR PRINTF (DELETE LATER)
# include "../libft/includes/libft.h"

/*
**  DIFFERENT
*/

# define SUCCESS		1

/*
**  FLAGS (MASKS)
*/

# define F_MINUS         (1u << 0u)		/* '-' */  /*    1 */
# define F_PLUS          (1u << 1u)		/* '+' */  /*    2 */
# define F_SPACE         (1u << 2u)		/* ' ' */  /*    4 */
# define F_OCT           (1u << 3u)		/* '#' */  /*    8 */
# define F_ZERO          (1u << 4u)		/* '0' */  /*   16 */

# define IS_MIN         & F_MINUS       /* '-' */
# define IS_PL          & F_PLUS        /* '+' */
# define IS_SP          & F_SPACE       /* ' ' */
# define IS_O           & F_OCT         /* '#' */
# define IS_ZE          & F_ZERO        /* '0' */

/*
**  SIZE (MASKS)
*/

# define LONG_INT        (1u << 0u)     /* 'l' */  /*    1 */
# define LONG_LONG_INT   (1u << 1u)     /* 'll'*/  /*    2 */
# define SHORT_INT       (1u << 2u)     /* 'h' */  /*    4 */
# define SIGNED_CHAR     (1u << 3u)     /* 'hh'*/  /*    8 */
# define INT_MAX         (1u << 4u)     /* 'j' */  /*   16 */
# define SIZE_T          (1u << 5u)     /* 'z' */  /*   32 */
# define PTRDIFF_T       (1u << 6u)     /* 't' */  /*   64 */
# define INT_64          (1u << 7u)     /* 'L' */  /*  128 */

/*
**  STRUCTURES
*/

typedef struct			s_rd
{
	wchar_t 			*mod2;
	char				*mod;       /* String */
	char				mod_smb;    /* Symbol of Format */
//	int                 sign;       /* Sign */
	unsigned short int	flag;       /* Flags */
	unsigned short int	size;       /* Size of Output */
	size_t      		smb_cnt;    /* Counter for Checking */
	size_t              kostil;     /* Kostil for prs */
	size_t  			width;      /* Field Width */
	size_t				prs;        /* Precision */
	size_t      		strlen;     /* Size Of String */
	struct s_rd			*next;
	struct s_rd			*prev;

}						t_rd;

typedef struct			s_out
{
	char				*buf;
	int					cnt;         /* Array Counter */
	unsigned int		output_cnt;  /* Symbols Sum */

}						t_out;

typedef struct			s_printf
{
	va_list				ap;
	t_rd				*read;
	t_out				output;
}						t_printf;

/*
**  UNION
*/

typedef union			u_flts
{
	long double			u;
	short				y[5];
}						t_flts;

/*
**  READER
*/

void        ft_reader(t_rd **read, va_list *ap, const char *format, t_out *out);
void		ft_chck_flags(t_rd **read, const char *format);
void		ft_chck_mod(t_rd **read, const char *format, va_list **ap, t_out *out);
void		ft_chck_size(t_rd **read, const char *format/*, va_list **ap*/);
void		ft_chck_precision(t_rd **read, const char *format, va_list **ap);
void		ft_chck_wdth(t_rd **read, const char *format, va_list **ap);
void		ft_rd(t_rd **rd, va_list *ap, const char *ft, t_out **out);
int         ft_put_percent(t_rd **read);
void		chck_b(t_rd **read, va_list **ap);
void		chck_c(t_rd **read, va_list **ap);
void		chck_di(t_rd **read, va_list **ap, int a);
void		chck_e(t_rd **read, va_list **ap, int a);
void		chck_f(t_rd **read, va_list **ap, int a);
void		chck_g(t_rd **read, va_list **ap, int a);
void		chck_o(t_rd **read, va_list **ap);
void		chck_p(t_rd **read, va_list **ap);
void		chck_sr(t_rd **read, va_list **ap, int a);
void		chck_x(t_rd **read, va_list **ap);
void		chck_xu(t_rd **read, va_list **ap);
void        chck_u(t_rd **read, va_list **ap);
int         chck_nthng(const char *format, t_out *output, t_rd **rd);

/*
**  MAIN
*/

void		ft_free_lists(t_rd **read);
int			ft_printf(const char *format, ...);
int			ft_pt_frst(const char *format, t_out *output, t_rd **rd);

/*
**  SOLVER
*/

int			ft_solver(t_rd **read, t_out *output);
int			ft_app_fl(t_rd **read);
int 		ft_app_d_prs(t_rd **read);
int			ft_app_width(t_rd **read);
int			ft_app_size(t_rd **read, t_out **output);
int 		ft_put_out(t_rd **read, t_out **output);

/*
**  OUTPUT
*/

void    ft_out_cnt(t_out *output);

/*
**  TYPES
*/

char            *ft_d(int64_t n);
char            *ft_u(u_int64_t n);
char            *ft_c(wchar_t c, int a);
char            *ft_e(long double e, int a);
char            *ft_ox(u_int64_t o, int a, int b);
char            *ft_p(unsigned long long p);
char            *ft_fld(long double f, int c);
char            *ft_g(long double g, int a, size_t b, unsigned short int c);
char            *ft_s(char *s);
int             mexp(t_flts l);
char            *mantis(t_flts l);
long long       pw(long long n, int p);
char    		*str_ad(char *s1, char *s2);
void            str_ml(char *s1, int m);
char            *pw_to_str(int a, int b);
char            *int_p(int e, char *man);
char            *fr_p(int i, char *man);
char            *add_z(char *s, int z);
char            *res_w_fr(int e, char *in, char *fr, int sign);
char            *res_o_fr(char *in, int sign);
char            *u_itoa_base(u_int64_t n, u_int64_t b, int c);
char            *ft_round(char *s, size_t a);
void            rnd(char *s, int a, int i);
void            zrs(char *s, int a, int i);
void            e_zrs(char *s, int a, int i);
int             t_str(char *s, char **t);
void            c_str(char *s, char **c, int i, int k);
void            s_str(char **s, char **t, char **c);
char            *fld_edge(char **man, int sign, int c);
void            rnd_z(char *s, int i);
void            rnd(char *s, int a, int i);
void            rndg(char *s, int i);
void            rndg_z(char *s, int i, unsigned short int c);
char            *ft_rg(char *s, int a, unsigned short int d);
char            *s_itoa(int64_t n);
char            *u_itoa(u_int64_t n);
void            wzrs(char **t);
char            *ft_ro(char **s, size_t prs, int l);

#endif
