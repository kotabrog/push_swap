/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 23:26:35 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/05/04 20:19:19 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strchr_n(const char *s, int c)
{
	int	n;

	n = 0;
	if (c == 0)
		return (-1);
	while (*(s + n) && *(s + n) != c)
		n++;
	if (*(s + n) == c)
		return (n);
	return (-1);
}
