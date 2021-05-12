/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 11:34:10 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/05/04 20:28:18 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_list(t_dcl_list **list)
{
	t_dcl_list	*temp;

	if ((*list)->v == NULL || ((*list)->next)->v == NULL)
		return (ERROR);
	temp = pop_list(list);
	push_back_element(*list, temp);
	return (SUCCESS);
}

int	rotate_two_list(t_dcl_list **list1, t_dcl_list **list2)
{
	int	flag1;
	int	flag2;

	flag1 = rotate_list(list1);
	flag2 = rotate_list(list2);
	if (flag1 == ERROR || flag2 == ERROR)
		return (ERROR);
	return (SUCCESS);
}

t_dcl_list	*pop_back_list(t_dcl_list *list)
{
	t_dcl_list	*out;

	if (list->v == NULL)
		return (NULL);
	out = (list->prev)->prev;
	(((list->prev)->prev)->prev)->next = (list->prev);
	(list->prev)->prev = out->prev;
	return (out);
}

int	rotate_reverse_list(t_dcl_list **list)
{
	t_dcl_list	*temp;

	if ((*list)->v == NULL || ((*list)->next)->v == NULL)
		return (ERROR);
	temp = pop_back_list(*list);
	push_element(list, temp);
	return (SUCCESS);
}

int	rotate_reverse_two_list(t_dcl_list **list1, t_dcl_list **list2)
{
	int	flag1;
	int	flag2;

	flag1 = rotate_reverse_list(list1);
	flag2 = rotate_reverse_list(list2);
	if (flag1 == ERROR || flag2 == ERROR)
		return (ERROR);
	return (SUCCESS);
}
