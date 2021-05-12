/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_tool2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 12:08:05 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/05/04 22:04:58 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	operate_one_command(t_dcl_list **list1, t_dcl_list **list2, \
							char command)
{
	if (command == COMMAND_SA)
		return (swap_list(list1));
	else if (command == COMMAND_SB)
		return (swap_list(list2));
	else if (command == COMMAND_SS)
		return (swap_two_list(list1, list2));
	else if (command == COMMAND_PA)
		return (push_to_anather_list(list2, list1));
	else if (command == COMMAND_PB)
		return (push_to_anather_list(list1, list2));
	else if (command == COMMAND_RA)
		return (rotate_list(list1));
	else if (command == COMMAND_RB)
		return (rotate_list(list2));
	else if (command == COMMAND_RR)
		return (rotate_two_list(list1, list2));
	else if (command == COMMAND_RRA)
		return (rotate_reverse_list(list1));
	else if (command == COMMAND_RRB)
		return (rotate_reverse_list(list2));
	else if (command == COMMAND_RRR)
		return (rotate_reverse_two_list(list1, list2));
	return (ERROR);
}

int	operate_commands(t_dcl_list **list, t_command *command)
{
	t_dcl_list	*list2;

	if (make_new_element(&list2, NULL))
		return (ERROR);
	while (command->point < command->len)
	{
		operate_one_command(list, &list2, (command->list)[command->point]);
		++(command->point);
	}
	free_list(&list2);
	return (SUCCESS);
}
