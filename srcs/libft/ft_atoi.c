/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 01:24:39 by kyuki             #+#    #+#             */
/*   Updated: 2020/11/30 12:27:01 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str, int *len)
{
	unsigned long long		atoi;
	int						negative;

	atoi = 0;
	negative = 1;
	while (*str == '\t' || *str == '\v' || *str == '\n' ||
		*str == '\r' || *str == '\f' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			negative *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		atoi = atoi * 10 + *str - 48;
		str++;
		(*len)++;
		if (atoi > 9223372036854775807 && negative == -1)
			return (0);
		if (atoi > 9223372036854775806 && negative == 1)
			return (-1);
	}
	return ((int)atoi * negative);
}
