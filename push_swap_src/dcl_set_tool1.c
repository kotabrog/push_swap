/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dcl_set_tool1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 15:47:39 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/05/04 20:17:45 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set_init(t_dcl_set **list, t_command *cmd, \
			t_dcl_list *list1, t_dcl_list *list2)
{
	*list = (t_dcl_set *)malloc(sizeof(t_dcl_set));
	if (*list == NULL)
		return (ERROR);
	(*list)->command = cmd;
	(*list)->list1 = list1;
	(*list)->list2 = list2;
	(*list)->next = *list;
	(*list)->prev = *list;
	return (SUCCESS);
}

void	set_push_element(t_dcl_set **list, t_dcl_set *element)
{
	element->next = *list;
	element->prev = (*list)->prev;
	((*list)->prev)->next = element;
	(*list)->prev = element;
	*list = element;
}

int	set_push(t_dcl_set **list, t_command *cmd, \
			t_dcl_list *list1, t_dcl_list *list2)
{
	t_dcl_set	*element;

	if (set_init(&element, cmd, list1, list2))
		return (ERROR);
	set_push_element(list, element);
	return (SUCCESS);
}

void	set_push_back_element(t_dcl_set **list, t_dcl_set *element)
{
	if ((*list)->command == NULL)
	{
		set_push_element(list, element);
		return ;
	}
	element->next = (*list)->prev;
	element->prev = ((*list)->prev)->prev;
	(((*list)->prev)->prev)->next = element;
	((*list)->prev)->prev = element;
}

int	set_push_back(t_dcl_set **list, t_command *cmd, \
			t_dcl_list *list1, t_dcl_list *list2)
{
	t_dcl_set	*element;

	if (set_init(&element, cmd, list1, list2))
		return (ERROR);
	set_push_back_element(list, element);
	return (SUCCESS);
}
