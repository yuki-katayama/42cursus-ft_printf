/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s_null.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 12:27:20 by kyuki             #+#    #+#             */
/*   Updated: 2020/12/06 17:23:41 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_flag_nonhyphen(t_tab *tab, char *null, long int diff)
{
	int	i;

	i = 0;
	while (i < diff)
	{
		if (tab->flag_index == 1)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		tab->len++;
		i++;
	}
	if (tab->dot == 0 || tab->accuracy_width < 0)
		tab->len += ft_putstr(null);
	else
		tab->len += ft_putnstr(null, tab->accuracy_width);
}

static void		ft_flag_hyphen(t_tab *tab, char *null, long int diff)
{
	int	i;

	i = 0;
	if (tab->dot == 0)
		tab->len += ft_putstr(null);
	else
		tab->len += ft_putnstr(null, tab->accuracy_width);
	while (i < diff)
	{
		write(1, " ", 1);
		tab->len++;
		i++;
	}
}

void			ft_print_s_null(t_tab *tab)
{
	long int	diff;
	char		*null;

	null = "(null)";
	tab->keta_count = ft_strlen(null);
	diff = tab->field_width - tab->keta_count;
	if (diff < tab->field_width - tab->accuracy_width &&
		tab->dot != 0 && tab->accuracy_width >= 0)
		diff = tab->field_width - tab->accuracy_width;
	if (tab->flag_index != 2)
		ft_flag_nonhyphen(tab, null, diff);
	else if (tab->flag_index == 2)
		ft_flag_hyphen(tab, null, diff);
}
