/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 12:27:14 by kyuki             #+#    #+#             */
/*   Updated: 2020/11/30 12:27:18 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_flag_hyphen(t_tab *tab)
{
	int	i;

	i = 0;
	write(1, &"%", 1);
	tab->len++;
	while (i < tab->field_width - 1)
	{
		write(1, " ", 1);
		tab->len++;
		i++;
	}
}

static void		ft_flag_nonhyphen(t_tab *tab)
{
	int	i;

	i = 0;
	while (i < tab->field_width - 1)
	{
		if (tab->flag_index != 1)
			write(1, " ", 1);
		else
			write(1, "0", 1);
		tab->len++;
		i++;
	}
	write(1, &"%", 1);
	tab->len++;
}

void			ft_print_percent(t_tab *tab)
{
	int	j;

	j = 0;
	if (tab->flag_index != 2)
		ft_flag_nonhyphen(tab);
	else
		ft_flag_hyphen(tab);
}
