/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 12:27:09 by kyuki             #+#    #+#             */
/*   Updated: 2020/11/30 12:27:13 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_write_minus_space(t_tab *tab, int count, int diff, char mode)
{
	int i;

	i = -1;
	if (mode == 'y')
	{
		if (diff > 0)
		{
			while (++i < tab->field_width -
				(tab->keta_count + tab->acu_keta_diff + tab->negative_other))
			{
				write(1, " ", 1);
				tab->len++;
			}
		}
	}
	else
	{
		if (tab->negative_other == 1 && tab->flag_index == 1 && tab->dot == 0)
			write(1, "-", 1);
		if (diff > 0)
			ft_diff_one_or_more(tab, count);
		if (tab->negative_other == 1 &&
			(tab->flag_index != 1 || (tab->flag_index == 1 && tab->dot == 1)))
			write(1, "-", 1);
	}
}

int				ft_putnbr_int(t_tab *tab, long int nbr, char mode)
{
	int	len;

	len = 0;
	if (nbr < 0)
		nbr *= -1;
	if (mode == 'w')
	{
		ft_put_zero(tab);
		if (nbr == 0 && (tab->field_width - tab->accuracy_width) > 0 &&
			tab->accuracy_width == 0 && tab->dot > 0)
		{
			write(1, " ", 1);
			return (1);
		}
		if (tab->field_width == 0 && nbr == 0
			&& tab->accuracy_width == 0 && tab->dot == 1)
		{
			tab->len--;
			return (0);
		}
		ft_putnbr_write_len(nbr, tab->base, mode, "0123456789abcdef");
	}
	else if (mode == 'l')
		len = ft_putnbr_write_len(nbr, tab->base, mode, "0123456789abcdef");
	return (len);
}

static void		ft_flag_hyphen(t_tab *tab, int d)
{
	int	diff;

	if (tab->field_width < 0)
		tab->field_width *= -1;
	tab->len += ft_putnbr_int(tab, d, 'l');
	if (d < 0)
	{
		d *= -1;
		tab->len += 1;
		tab->negative_other += 1;
		write(1, "-", 1);
	}
	tab->keta_count += ft_putnbr_int(tab, d, 'l');
	diff = ft_set_diff(tab);
	ft_putnbr_int(tab, d, 'w');
	ft_write_minus_space(tab, 0, diff, 'y');
}

static void		ft_flag_nonhyphen(t_tab *tab, int d)
{
	int	diff;
	int	count;

	count = 0;
	tab->len += ft_putnbr_int(tab, d, 'l');
	if (d < 0)
	{
		tab->len += 1;
		if (tab->asterisk > 0 && tab->dot == 0 && d > 0)
		{
			write(1, "-", 1);
			count += 1;
		}
		else
		{
			d *= -1;
			tab->negative_other += 1;
		}
	}
	tab->keta_count += ft_putnbr_int(tab, d, 'l');
	diff = ft_set_diff(tab);
	ft_write_minus_space(tab, count, diff, 'n');
	ft_putnbr_int(tab, d, 'w');
}

void			ft_print_int(t_tab *tab, int base)
{
	int	d;

	d = (va_arg(tab->args, int));
	tab->base = base;
	if (tab->flag_index != 2 && tab->field_width >= 0)
		ft_flag_nonhyphen(tab, d);
	else if (tab->flag_index == 2 || tab->field_width < 0)
		ft_flag_hyphen(tab, d);
}
