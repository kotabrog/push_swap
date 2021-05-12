/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bfs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 21:27:56 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/05/04 21:44:59 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_bfs3(t_dcl_set *set)
{
	if (command_loop(set, 1, COMMAND_PB))
		return (ERROR);
	if (command_loop(set, 1, COMMAND_SA))
		return (ERROR);
	if (command_loop(set, 2, COMMAND_RA))
		return (ERROR);
	if (push_and_rotate_loop(set, 1))
		return (ERROR);
	set->min_value += 3;
	return (SUCCESS);
}

int	swap_bfs2(t_dcl_set *set)
{
	if (set->min_value == *(set->list1->next->v) && \
		set->min_value + 1 == *(set->list1->next->next->v))
	{
		if (command_loop(set, 1, COMMAND_SA))
			return (ERROR);
		if (command_loop(set, 1, COMMAND_RA))
			return (ERROR);
		if (command_loop(set, 1, COMMAND_SA))
			return (ERROR);
		if (command_loop(set, 2, COMMAND_RA))
			return (ERROR);
		set->min_value += 3;
	}
	else if (set->min_value + 1 == *(set->list1->next->v) && \
			set->min_value == *(set->list1->next->next->v))
		return (swap_bfs3(set));
	return (SUCCESS);
}

int	swap_bfs(t_dcl_set *set)
{
	if (set->min_value + 1 == *(set->list1->v) && \
		set->min_value + 2 == *(set->list1->next->v) && \
		set->min_value == *(set->list1->next->next->v))
	{
		if (command_loop(set, 1, COMMAND_PB))
			return (ERROR);
		if (command_loop(set, 1, COMMAND_SA))
			return (ERROR);
		if (command_loop(set, 1, COMMAND_RA))
			return (ERROR);
		if (command_loop(set, 1, COMMAND_PA))
			return (ERROR);
		if (command_loop(set, 2, COMMAND_RA))
			return (ERROR);
		set->min_value += 3;
	}
	else if (set->min_value + 2 == *(set->list1->v))
		return (swap_bfs2(set));
	return (SUCCESS);
}

int	swap_bfs_flag(t_dcl_set *set)
{
	if (set->min_value + 1 == *(set->list1->v) && \
		set->min_value + 2 == *(set->list1->next->v) && \
		set->min_value == *(set->list1->next->next->v))
		return (1);
	if (set->min_value + 2 == *(set->list1->v) && \
		set->min_value == *(set->list1->next->v) && \
		set->min_value + 1 == *(set->list1->next->next->v))
		return (1);
	if (set->min_value + 2 == *(set->list1->v) && \
		set->min_value + 1 == *(set->list1->next->v) && \
		set->min_value == *(set->list1->next->next->v))
		return (1);
	return (0);
}
