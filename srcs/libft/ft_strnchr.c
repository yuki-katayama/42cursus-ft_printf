/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 12:28:04 by kyuki             #+#    #+#             */
/*   Updated: 2020/11/30 12:28:06 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnchr(const char *s, int c, int start, int end)
{
	while (s[start] != (const char)end)
	{
		if (((unsigned char *)s)[start] == (unsigned char)c)
			return (start);
		start++;
	}
	return (-1);
}
