/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 12:27:30 by kyuki             #+#    #+#             */
/*   Updated: 2020/12/06 17:23:06 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_putnbr_uint(t_tab *tab,
											unsigned int nbr, char mode)
{
	int	len;

	len = 0;
	if (mode != 'l')
	{
		ft_put_zero(tab);
		if (nbr == 0 && (tab->field_width - tab->accuracy_width) > 0 &&
			tab->accuracy_width == 0 && tab->dot > 0)
		{
			write(1, " ", 1);
			return (1);
		}
		if ('a' < tab->fmt && tab->fmt < 'z')
			len += ft_putnbr_write_len(nbr, tab->base, 'w', "0123456789abcdef");
		else
			len += ft_putnbr_write_len(nbr, tab->base, 'w', "0123456789ABCDEF");
	}
	else
		len += ft_putnbr_write_len(nbr, tab->base, 'l', "");
	return (len);
}

static void		ft_diff_over_zero(t_tab *tab)
{
	int	count;

	count = 0;
	while (count < tab->field_width -
		(tab->keta_count + tab->acu_keta_diff + tab->negative_other))
	{
		if (tab->flag_index == 1 && tab->dot == 0)
		{
			write(1, "0", 1);
			tab->len++;
			count++;
		}
		else
		{
			write(1, " ", 1);
			tab->len++;
			count++;
		}
	}
}

static void		ft_flag_hyphen(t_tab *tab, unsigned int x)
{
	int	diff;
	int	count;

	tab->keta_count += ft_putnbr_uint(tab, x, 'l');
	diff = ft_set_diff(tab);
	tab->len += ft_putnbr_uint(tab, x, 'w');
	count = 0;
	if (diff > 0)
	{
		while (count < tab->field_width -
			(tab->keta_count + tab->acu_keta_diff + tab->negative_other))
		{
			write(1, " ", 1);
			tab->len++;
			count++;
		}
	}
}

static void		ft_flag_nonhyphen(t_tab *tab, unsigned int x)
{
	int	diff;

	tab->keta_count += ft_putnbr_uint(tab, x, 'l');
	if (tab->flag_index == 0 && ((tab->base == 16) || (tab->base == 8)))
		tab->negative_other += (tab->base == 16) ? 2 : 1;
	if ((diff = ft_set_diff(tab)) > 0)
		ft_diff_over_zero(tab);
	if (tab->flag_index == 0 && ((tab->base == 16) || (tab->base == 8)))
	{
		write(1, "0", 1);
		tab->len += 1;
		if (tab->base == 16)
		{
			if (tab->fmt == 'x')
				write(1, "x", 1);
			else if (tab->fmt == 'X')
				write(1, "X", 1);
			tab->len += 1;
		}
	}
	tab->len += ft_putnbr_uint(tab, x, 'w');
}

void			ft_print_unsigned(t_tab *tab, int base)
{
	unsigned int	x;

	x = (va_arg(tab->args, unsigned int));
	tab->base = base;
	if (tab->dot > 0 && x == 0 &&
		tab->accuracy_width == 0 && tab->field_width == 0)
		return ;
	if (tab->flag_index != 2)
		ft_flag_nonhyphen(tab, x);
	else if (tab->flag_index == 2)
		ft_flag_hyphen(tab, x);
}
