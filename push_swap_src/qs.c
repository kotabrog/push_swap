/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qs.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 13:14:01 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/05/04 21:39:25 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	qs(t_dcl_set *set, int start, int end)
{
	int	middle;

	if (start >= end)
		return (SUCCESS);
	if (end - start <= 3)
	{
		if (bfs_qs(set, start, end))
			return (ERROR);
		return (SUCCESS);
	}
	middle = (end - start - 1) / 2 + 1 + start;
	if (qs_first_half(set, &start, end, middle))
		return (ERROR);
	if (qs(set, start, middle))
		return (ERROR);
	if (middle < set->min_value)
		middle = set->min_value;
	if (qs_second_half(set, end, &middle))
		return (ERROR);
	if (qs(set, middle, end))
		return (ERROR);
	return (SUCCESS);
}

int	first_qs(t_dcl_set *set, int n)
{
	int		middle;

	middle = (n - 1) / 2 + 1;
	if (first_qs_first_half(set, n, middle))
		return (ERROR);
	while (set->min_value < middle)
		if (qs(set, set->min_value, middle))
			return (ERROR);
	middle = set->min_value;
	if (qs_second_half(set, n, &middle))
		return (ERROR);
	while (set->min_value < n)
		if (qs(set, set->min_value, n))
			return (ERROR);
	return (SUCCESS);
}

int	qs_two_stack(t_dcl_list *list, t_command **command, int list_len)
{
	t_dcl_list	*list1;
	t_dcl_list	*list2;
	t_dcl_set	*set;

	if (command_init(command))
		return (ERROR);
	if (make_new_element(&list2, NULL))
		return (ERROR);
	list1 = list_cpy(list);
	if (list1 == NULL || set_init(&set, *command, list1, list2))
	{
		free_list(&list1);
		free_list(&list2);
		return (ERROR);
	}
	set->min_value = 0;
	list_len = first_qs(set, list_len);
	free_list(&(set->list1));
	free_list(&(set->list2));
	free(set);
	return (list_len);
}
