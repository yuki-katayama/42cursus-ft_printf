/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 03:18:11 by kyuki             #+#    #+#             */
/*   Updated: 2020/10/11 03:18:14 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBFT_H
# define _LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <unistd.h>
# include <ctype.h>

int		ft_putstr(const char *str);
int		ft_putnstr(const char *str, long int end);
int		ft_strchr(const char *s, int c);
int		ft_strlen(const char *s);
int		ft_atoi(const char *str, int *len);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strnchr(const char *s, int c, int start, int end);

#endif
