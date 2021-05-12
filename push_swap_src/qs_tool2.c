/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qs_tool2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 21:37:58 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/05/04 21:39:45 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_and_rotate_min_loop(t_dcl_set *set, int *start)
{
	int		i;

	i = 0;
	while (set->list1->v && *(set->list1->v) != set->min_value)
	{
		if (command_loop(set, 1, COMMAND_PA))
			return (ERROR);
		++i;
	}
	if (command_loop(set, i, COMMAND_RA))
		return (ERROR);
	*start += i;
	set->min_value += i;
	return (SUCCESS);
}

int	push_and_rotate_min_flag(t_dcl_set *set)
{
	int			i;
	t_dcl_list	*list;

	list = set->list2;
	if (list->v == NULL)
		return (0);
	i = *(list->v);
	while (list->v && i != set->min_value && \
			list->next->v && i - 1 == *(list->next->v))
	{
		--i;
		list = list->next;
	}
	if (set->min_value == i)
		return (1);
	return (0);
}

int	qs_first_half(t_dcl_set *set, int *start, int end, int middle)
{
	int		j;
	char	flag;

	j = end;
	while (*start < end && middle < j)
	{
		if (*(set->list2->v) >= middle)
			--j;
		if (push_and_rotate_min_flag(set))
		{
			if (push_and_rotate_min_loop(set, start))
				return (ERROR);
		}
		else
		{
			flag = COMMAND_RB;
			if (*((set->list2)->v) >= middle)
				flag = COMMAND_PA;
			if (command_loop(set, 1, flag))
				return (ERROR);
			--end;
		}
	}
	return (SUCCESS);
}

int	double_r_flag(t_dcl_set *set, int middle)
{
	int		semi_middle;

	semi_middle = (middle - set->min_value - 1) / 2 + set->min_value;
	if (set->list2->v && set->list2->next->v && *(set->list2->v) < semi_middle)
		return (1);
	return (0);
}

int	first_qs_first_half(t_dcl_set *set, int n, int middle)
{
	int		i;
	int		j;
	char	flag;

	i = 0;
	j = 0;
	while (i < n && j < middle)
	{
		if (*(set->list1->v) >= middle)
		{
			if (double_r_flag(set, middle))
				flag = COMMAND_RR;
			else
				flag = COMMAND_RA;
		}
		else
		{
			++j;
			flag = COMMAND_PB;
		}
		if (command_loop(set, 1, flag))
			return (ERROR);
		++i;
	}
	return (SUCCESS);
}
