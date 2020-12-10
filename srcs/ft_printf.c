/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 12:27:44 by kyuki             #+#    #+#             */
/*   Updated: 2020/11/30 12:27:45 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_put_zero(t_tab *tab)
{
	int	i;

	i = 0;
	while (i < tab->accuracy_width - tab->keta_count)
	{
		write(1, "0", 1);
		tab->len++;
		i++;
	}
}

static void		ft_printf_choice_format(t_tab *tab, int i)
{
	if (tab->copy[i] == '%')
		ft_print_percent(tab);
	else if (tab->copy[i] == 's')
		ft_print_s(tab);
	else if (tab->copy[i] == 'c')
		ft_print_c(tab);
	else if (tab->copy[i] == 'd' || tab->copy[i] == 'i')
		ft_print_int(tab, 10);
	else if (tab->copy[i] == 'x' || tab->copy[i] == 'X')
		ft_print_unsigned(tab, 16);
	else if (tab->copy[i] == 'u')
		ft_print_unsigned(tab, 10);
	else if (tab->copy[i] == 'o')
		ft_print_unsigned(tab, 8);
	else if (tab->copy[i] == 'p')
		ft_print_unsigned_long(tab, 16);
	else if (tab->field_width > 0)
		tab->error_percent_nonfmt = 1;
}

void			ft_printf_putstr(t_tab *tab)
{
	int i;

	i = 0;
	while (tab->copy[i] != '\0')
	{
		if (tab->copy[i] == '%')
		{
			i += 1;
			ft_printf_flag(tab, &i);
			ft_set_field_accu_fmt(tab, i);
			ft_printf_choice_format(tab, i);
			if (tab->error_percent_nonfmt == 1)
				return ;
		}
		else
		{
			write(1, &tab->copy[i], 1);
			tab->len++;
		}
		ft_initialize_again(tab);
		i++;
	}
}

void			ft_printf_main(t_tab *tab, const char *fmt)
{
	tab->copy = fmt;
	if (ft_strchr(tab->copy, '%') == -1)
	{
		ft_putstr(tab->copy);
		tab->len = ft_strlen(tab->copy);
	}
	else
		ft_printf_putstr(tab);
}

int				ft_printf(const char *fmt, ...)
{
	t_tab *tab;

	if (fmt == NULL)
		return (-1);
	if (!(tab = (t_tab *)malloc(sizeof(t_tab))))
		return (-1);
	ft_initialize(tab);
	if (fmt && *fmt != *"")
	{
		va_start(tab->args, fmt);
		ft_printf_main(tab, fmt);
		va_end(tab->args);
	}
	free(tab);
	return (tab->len);
}
