/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 12:27:38 by kyuki             #+#    #+#             */
/*   Updated: 2020/11/30 12:27:43 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_set_field_accu_flag(t_tab *tab, int dot_index)
{
	if (tab->asterisk == 1)
	{
		if (dot_index == -1 || tab->copy[dot_index - 1] == '*')
		{
			if ((tab->field_width = va_arg(tab->args, int)) < 0)
			{
				tab->field_width *= -1;
				tab->flag_index = 2;
			}
		}
		else if (tab->copy[dot_index + 1] == '*')
			tab->accuracy_width = va_arg(tab->args, int);
	}
	else if (tab->asterisk == 2)
	{
		if ((tab->field_width = va_arg(tab->args, int)) < 0)
		{
			tab->field_width *= -1;
			tab->flag_index = 2;
		}
		tab->accuracy_width = (va_arg(tab->args, int));
	}
}

void			ft_set_field_accu_fmt(t_tab *tab, int i)
{
	int	tmp;
	int	dot_index;

	dot_index = -1;
	tab->fmt = tab->copy[i];
	if ((tmp = ft_strchr(tab->copy, '%')) >= 0)
	{
		if ((tmp = ft_strnchr(tab->copy, '.', tmp, tab->fmt)) != -1)
			dot_index = tmp;
	}
	ft_set_field_accu_flag(tab, dot_index);
}

int				ft_set_diff(t_tab *tab)
{
	int	diff;

	diff = (int)tab->field_width - (int)tab->accuracy_width;
	if ((int)tab->accuracy_width - (int)tab->keta_count > 0)
		tab->acu_keta_diff = (int)tab->accuracy_width - (int)tab->keta_count;
	else
		tab->acu_keta_diff = 0;
	return (diff);
}

int				ft_diff_one_or_more(t_tab *tab, int count)
{
	while (count < tab->field_width -
		(tab->keta_count + tab->acu_keta_diff + tab->negative_other))
	{
		if (tab->flag_index != 1 || (tab->flag_index == 1 &&
			tab->field_width > tab->accuracy_width && tab->accuracy_width > 0))
		{
			write(1, " ", 1);
			tab->len++;
			count++;
		}
		else
		{
			write(1, "0", 1);
			tab->len++;
			count++;
		}
	}
	return (count);
}

int				ft_putnbr_write_len(long long nb, long long base,
								char mode, char *putlist)
{
	int	len;

	len = 0;
	if (nb > base - 1)
		len = ft_putnbr_write_len(nb / base, base, mode, putlist);
	if (mode == 'w')
		write(1, &putlist[nb % base], 1);
	return (len + 1);
}
