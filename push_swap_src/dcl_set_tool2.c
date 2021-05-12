/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dcl_set_tool2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 17:05:07 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/05/04 20:18:06 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dcl_set	*set_pop_list(t_dcl_set **list)
{
	t_dcl_set	*out;

	if ((*list)->command == NULL)
		return (NULL);
	out = *list;
	((*list)->next)->prev = (*list)->prev;
	*list = (*list)->next;
	return (out);
}

void	set_free_list(t_dcl_set **list)
{
	t_dcl_set	*temp;

	if (*list == NULL)
		return ;
	while ((*list)->command)
	{
		free_command(&((*list)->command));
		free_list(&((*list)->list1));
		free_list(&((*list)->list2));
		temp = *list;
		*list = (*list)->next;
		free(temp);
	}
	free(*list);
	*list = NULL;
}

t_dcl_set	*set_cpy(t_dcl_set *list)
{
	t_dcl_set	*out;
	t_command	*cmd;
	t_dcl_list	*list1;
	t_dcl_list	*list2;

	if (set_init(&out, NULL, NULL, NULL))
		return (NULL);
	while (list && list->command)
	{
		cmd = command_cpy(list->command);
		list1 = list_cpy(list->list1);
		list2 = list_cpy(list->list2);
		if (!cmd || !list1 || !list2 || set_push_back(&out, cmd, list1, list2))
		{
			free_command(&cmd);
			free_list(&list1);
			free_list(&list2);
			set_free_list(&out);
			return (NULL);
		}
		list = list->next;
	}
	return (out);
}

int	set_cpy_element(t_dcl_set **dst, t_dcl_set *src)
{
	t_command	*cmd;
	t_dcl_list	*list1;
	t_dcl_list	*list2;

	cmd = command_cpy(src->command);
	list1 = list_cpy(src->list1);
	list2 = list_cpy(src->list2);
	if (!cmd || !list1 || !list2 || set_init(dst, cmd, list1, list2))
	{
		free_command(&cmd);
		free_list(&list1);
		free_list(&list2);
		return (ERROR);
	}
	return (SUCCESS);
}

void	set_free_element(t_dcl_set **list)
{
	if (*list == NULL)
		return ;
	free_command(&((*list)->command));
	free_list(&((*list)->list1));
	free_list(&((*list)->list2));
	free(*list);
	*list = NULL;
}
