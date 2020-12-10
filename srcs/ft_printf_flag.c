/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 12:27:33 by kyuki             #+#    #+#             */
/*   Updated: 2020/11/30 12:27:37 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_flag(t_tab *tab, int *i)
{
	if (tab->copy[*i] == '0' && tab->copy[*i + 1] == '-')
		*i += 1;
	if ((tab->flag_index = ft_strchr(tab->flag_kind, tab->copy[*i])) >= 0)
		*i += 1;
	if (tab->copy[*i] == '*')
	{
		*i += 1;
		tab->asterisk += 1;
	}
	if ('0' <= tab->copy[*i] && tab->copy[*i] <= '9')
		tab->field_width = ft_atoi(&tab->copy[*i], &*i);
	if (tab->copy[*i] == '.')
	{
		*i += 1;
		tab->dot += 1;
		tab->accuracy_width = ft_atoi(&tab->copy[*i], &*i);
	}
	if (tab->copy[*i] == '*')
	{
		*i += 1;
		tab->asterisk += 1;
	}
}
