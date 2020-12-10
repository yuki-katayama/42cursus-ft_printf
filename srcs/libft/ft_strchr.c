/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 03:09:55 by kyuki             #+#    #+#             */
/*   Updated: 2020/11/30 12:27:58 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strchr(const char *s, int c)
{
	int	length;
	int	i;

	i = 0;
	length = ft_strlen(s) + 1;
	while (i < length)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return (i);
		i++;
	}
	return (-1);
}
