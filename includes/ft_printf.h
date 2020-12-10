/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 12:27:46 by kyuki             #+#    #+#             */
/*   Updated: 2020/11/30 12:27:48 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <ctype.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "../srcs/libft/libft.h"

typedef struct	s_tab
{
	va_list		args;
	int			len;
	const char	*copy;
	const char	*flag_kind;
	char		fmt;
	long int	field_width;
	long int	keta_count;
	long int	accuracy_width;
	long int	acu_keta_diff;
	long int	base;
	int			negative_other;
	int			flag_index;
	int			asterisk;
	int			dot;
	int			error_percent_nonfmt;
}				t_tab;

int				ft_printf(const char *fmt, ...);
int				ft_set_diff(t_tab *tab);
int				ft_diff_one_or_more(t_tab *tab, int count);
int				ft_putnbr_write_len(long long nb, long long base,
									char mode, char *putlist);
void			ft_print_c(t_tab *tab);
void			ft_print_percent(t_tab *tab);
void			ft_print_s(t_tab *tab);
void			ft_print_s_null(t_tab *tab);
void			ft_initialize(t_tab *tab);
void			ft_initialize_again(t_tab *tab);
void			ft_print_unsigned(t_tab *tab, int base);
void			ft_print_unsigned_long(t_tab *tab, int base);
void			ft_print_int(t_tab *tab, int base);
void			ft_set_field_accu_fmt(t_tab *tab, int i);
void			ft_flag_hyphen_unsigned(t_tab *tab, int i, unsigned int x);
void			ft_printf_flag(t_tab *tab, int *i);
void			ft_put_zero(t_tab *tab);

#endif
