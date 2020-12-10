/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 12:27:03 by kyuki             #+#    #+#             */
/*   Updated: 2020/11/30 12:27:05 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_initialize(t_tab *tab)
{
	tab->len = 0;
	tab->field_width = 0;
	tab->keta_count = 0;
	tab->accuracy_width = 0;
	tab->acu_keta_diff = 0;
	tab->negative_other = 0;
	tab->base = 0;
	tab->flag_index = -1;
	tab->asterisk = 0;
	tab->flag_kind = "#0- +";
	tab->dot = 0;
	tab->error_percent_nonfmt = 0;
	tab->fmt = '\0';
}

void	ft_initialize_again(t_tab *tab)
{
	tab->field_width = 0;
	tab->accuracy_width = 0;
	tab->negative_other = 0;
	tab->flag_index = -1;
	tab->keta_count = 0;
	tab->acu_keta_diff = 0;
	tab->base = 0;
	tab->asterisk = 0;
	tab->dot = 0;
	tab->fmt = '\0';
}
