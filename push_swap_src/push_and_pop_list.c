/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_pop_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 21:57:24 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/05/04 20:22:30 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_element(t_dcl_list **list, t_dcl_list *element)
{
	element->next = *list;
	element->prev = (*list)->prev;
	((*list)->prev)->next = element;
	(*list)->prev = element;
	*list = element;
}

void	push_back_element(t_dcl_list *list, t_dcl_list *element)
{
	element->next = list->prev;
	element->prev = (list->prev)->prev;
	((list->prev)->prev)->next = element;
	(list->prev)->prev = element;
}

int	push_int(t_dcl_list **list, int v)
{
	t_dcl_list	*element;

	if (int_to_element(&element, v))
		return (ERROR);
	push_element(list, element);
	return (SUCCESS);
}

t_dcl_list	*pop_list(t_dcl_list **list)
{
	t_dcl_list	*out;

	if ((*list)->v == NULL)
		return (NULL);
	out = *list;
	((*list)->next)->prev = (*list)->prev;
	((*list)->prev)->next = (*list)->next;
	*list = (*list)->next;
	return (out);
}

int	push_to_anather_list(t_dcl_list **giver, t_dcl_list **receiver)
{
	t_dcl_list	*temp;

	temp = pop_list(giver);
	if (temp == NULL)
		return (ERROR);
	push_element(receiver, temp);
	return (SUCCESS);
}
