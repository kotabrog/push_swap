/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dcl_set_tool3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 21:33:11 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/05/04 21:35:58 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	command_loop(t_dcl_set *set, int n, char flag)
{
	int	i;

	i = 0;
	while (i < n)
	{
		operate_one_command(&(set->list1), &(set->list2), flag);
		if (command_update(set->command, flag))
			return (ERROR);
		++i;
	}
	return (SUCCESS);
}

int	push_and_rotate_loop(t_dcl_set *set, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		operate_one_command(&(set->list1), &(set->list2), COMMAND_PA);
		if (command_update(set->command, COMMAND_PA))
			return (ERROR);
		operate_one_command(&(set->list1), &(set->list2), COMMAND_RA);
		if (command_update(set->command, COMMAND_RA))
			return (ERROR);
		++i;
	}
	return (SUCCESS);
}
