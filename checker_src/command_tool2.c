/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 12:08:05 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/05/04 18:21:53 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	operate_one_command(t_dcl_list **list1, t_dcl_list **list2, \
							char command)
{
	if (command == COMMAND_SA)
		swap_list(list1);
	else if (command == COMMAND_SB)
		swap_list(list2);
	else if (command == COMMAND_SS)
		swap_two_list(list1, list2);
	else if (command == COMMAND_PA)
		push_to_anather_list(list2, list1);
	else if (command == COMMAND_PB)
		push_to_anather_list(list1, list2);
	else if (command == COMMAND_RA)
		rotate_list(list1);
	else if (command == COMMAND_RB)
		rotate_list(list2);
	else if (command == COMMAND_RR)
		rotate_two_list(list1, list2);
	else if (command == COMMAND_RRA)
		rotate_reverse_list(list1);
	else if (command == COMMAND_RRB)
		rotate_reverse_list(list2);
	else if (command == COMMAND_RRR)
		rotate_reverse_two_list(list1, list2);
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
