/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qs_tool1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 21:36:17 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/05/04 21:44:50 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_or_rotate_min(t_dcl_set *set, int *start)
{
	char	flag;

	if (*((set->list1)->v) == set->min_value)
	{
		flag = COMMAND_RA;
		++(*start);
		++(set->min_value);
	}
	else
		flag = COMMAND_PB;
	operate_one_command(&(set->list1), &(set->list2), flag);
	if (command_update(set->command, flag))
		return (ERROR);
	return (SUCCESS);
}

int	swap_consecutive_min(t_dcl_set *set)
{
	if (*(set->list1->v) == set->min_value + 1 && \
		*(set->list1->next->v) == set->min_value)
		if (command_loop(set, 1, COMMAND_SA))
			return (ERROR);
	return (SUCCESS);
}

int	qs_second_half(t_dcl_set *set, int end, int *middle)
{
	int	i;

	i = *middle;
	while (i < end)
	{
		if (swap_bfs_flag(set))
		{
			if (swap_bfs(set))
				return (ERROR);
			*middle += 3;
			i += 3;
		}
		else
		{
			if (swap_consecutive_min(set))
				return (ERROR);
			if (push_or_rotate_min(set, middle))
				return (ERROR);
			++i;
		}
	}
	return (SUCCESS);
}
