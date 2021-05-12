/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 15:24:55 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/05/04 22:18:34 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bfs_init(t_dcl_list *list, t_dcl_set **queue)
{
	int			flag;
	t_command	*cmd;
	t_dcl_list	*list1;
	t_dcl_list	*list2;

	flag = 0;
	if (set_init(queue, NULL, NULL, NULL))
		return (ERROR);
	if (command_init(&cmd))
		flag = ERROR;
	list1 = list_cpy(list);
	if (make_new_element(&list2, NULL))
		flag = ERROR;
	if (flag || !list1 || set_push(queue, cmd, list1, list2))
	{
		free_command(&cmd);
		free_list(&list1);
		free_list(&list2);
		set_free_list(queue);
		return (ERROR);
	}
	return (SUCCESS);
}

int	before_cmd_check(t_dcl_set *target, char flag)
{
	char	before;

	if ((target->command)->point == 0)
		return (SUCCESS);
	before = ((target->command)->list)[(target->command)->point - 1];
	if ((before <= COMMAND_SS && flag <= COMMAND_SS) || \
		(COMMAND_RA <= before && flag == before + 3) || \
		(COMMAND_RA <= before && before <= COMMAND_RR && \
			flag == COMMAND_RRR) || \
		(before == COMMAND_RRR && COMMAND_RA <= flag && \
			flag <= COMMAND_RR) || \
		(before == COMMAND_RR && COMMAND_RRA <= flag && \
			flag <= COMMAND_RRR) || \
		(COMMAND_RRA <= before && before <= COMMAND_RRR && \
			flag == COMMAND_RR) || \
		(COMMAND_RRA <= before && flag == before - 3) || \
		(before == COMMAND_RA && flag == COMMAND_RB) || \
		(before == COMMAND_RB && flag == COMMAND_RA) || \
		(before == COMMAND_RRA && flag == COMMAND_RRB) || \
		(before == COMMAND_RRB && flag == COMMAND_RRA) || \
		(before == COMMAND_PA && flag == COMMAND_PB) || \
		(before == COMMAND_PB && flag == COMMAND_PA))
		return (ERROR);
	return (SUCCESS);
}

int	all_operate(t_dcl_set **queue, t_dcl_set *target)
{
	char		i;
	t_dcl_set	*temp;

	i = 2;
	while (i < 13)
	{
		if (!before_cmd_check(target, i))
		{
			if (set_cpy_element(&temp, target))
				return (ERROR);
			if (operate_one_command(&(temp->list1), &(temp->list2), i))
				set_free_element(&temp);
			else
			{
				if (command_update(temp->command, i))
				{
					set_free_element(&temp);
					return (ERROR);
				}
				set_push_back_element(queue, temp);
			}
		}
		++i;
	}
	return (SUCCESS);
}

int	bfs(t_dcl_list *list, t_command **command)
{
	t_dcl_set	*queue;
	t_dcl_set	*temp;

	if (bfs_init(list, &queue))
		return (ERROR);
	temp = NULL;
	while (queue->command)
	{
		temp = set_pop_list(&queue);
		if (len_list(temp->list2) == 0 && !is_sorted_list(temp->list1))
			break ;
		if (all_operate(&queue, temp))
		{
			set_free_element(&temp);
			set_free_list(&queue);
			return (ERROR);
		}
		set_free_element(&temp);
	}
	*command = command_cpy(temp->command);
	set_free_element(&temp);
	set_free_list(&queue);
	if (*command == NULL)
		return (ERROR);
	return (SUCCESS);
}
