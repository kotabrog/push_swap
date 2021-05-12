/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 00:34:38 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/05/04 21:57:31 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_strcpy(char *p, char const *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		p[i] = s[i];
		i++;
	}
}

void	int_cpy(int *p, const int *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		p[i] = s[i];
		++i;
	}
}
