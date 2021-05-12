/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 13:06:51 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/05/03 13:11:20 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	replacement_to_index(t_dcl_list *list, int *array)
{
	int	i;

	while (list->v)
	{
		i = 0;
		while (array[i] != *(list->v))
			++i;
		*(list->v) = i;
		list = list->next;
	}
}
