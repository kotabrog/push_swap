/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qs_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 21:30:10 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/05/04 22:10:23 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bfs_qs4(t_dcl_set *set, int start, int end)
{
	if (end - start == 2)
	{
		set->min_value += 2;
		if (*(set->list2->v) == start)
		{
			if (push_and_rotate_loop(set, 2))
				return (ERROR);
		}
		else
		{
			if (command_loop(set, 2, COMMAND_PA))
				return (ERROR);
			if (command_loop(set, 2, COMMAND_RA))
				return (ERROR);
		}
	}
	else
	{
		set->min_value += 1;
		if (push_and_rotate_loop(set, 1))
			return (ERROR);
	}
	return (SUCCESS);
}

int	bfs_qs3(t_dcl_set *set, int start)
{
	if (*(set->list2->next->v) == start)
	{
		if (command_loop(set, 2, COMMAND_PA))
			return (ERROR);
		if (command_loop(set, 1, COMMAND_RA))
			return (ERROR);
		if (command_loop(set, 1, COMMAND_PA))
			return (ERROR);
		if (command_loop(set, 2, COMMAND_RA))
			return (ERROR);
	}
	else
	{
		if (command_loop(set, 3, COMMAND_PA))
			return (ERROR);
		if (command_loop(set, 3, COMMAND_RA))
			return (ERROR);
	}
	return (SUCCESS);
}

int	bfs_qs2(t_dcl_set *set, int start)
{
	if (*(set->list2->next->v) == start)
	{
		if (command_loop(set, 2, COMMAND_PA))
			return (ERROR);
		if (command_loop(set, 2, COMMAND_RA))
			return (ERROR);
		if (push_and_rotate_loop(set, 1))
			return (ERROR);
	}
	else
	{
		if (command_loop(set, 1, COMMAND_RB))
			return (ERROR);
		if (command_loop(set, 2, COMMAND_PA))
			return (ERROR);
		if (command_loop(set, 1, COMMAND_RA))
			return (ERROR);
		if (command_loop(set, 1, COMMAND_PA))
			return (ERROR);
		if (command_loop(set, 2, COMMAND_RA))
			return (ERROR);
	}
	return (SUCCESS);
}

int	bfs_qs(t_dcl_set *set, int start, int end)
{
	if (end - start == 3)
	{
		set->min_value += 3;
		if (*(set->list2->v) == start && *(set->list2->next->v) == start + 1)
		{
			if (push_and_rotate_loop(set, 3))
				return (ERROR);
		}
		else if (*(set->list2->v) == start)
		{
			if (push_and_rotate_loop(set, 1))
				return (ERROR);
			if (command_loop(set, 2, COMMAND_PA))
				return (ERROR);
			if (command_loop(set, 2, COMMAND_RA))
				return (ERROR);
		}
		else if (*(set->list2->v) == start + 1)
			return (bfs_qs2(set, start));
		else
			return (bfs_qs3(set, start));
	}
	else
		return (bfs_qs4(set, start, end));
	return (SUCCESS);
}
