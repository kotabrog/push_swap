/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 11:24:53 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/05/04 18:30:09 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	swap_list(t_dcl_list **list)
{
	t_dcl_list	*temp_first;
	t_dcl_list	*temp_second;

	if ((*list)->v == NULL || ((*list)->next)->v == NULL)
		return (ERROR);
	temp_first = pop_list(list);
	temp_second = pop_list(list);
	push_element(list, temp_first);
	push_element(list, temp_second);
	return (SUCCESS);
}

int	swap_two_list(t_dcl_list **list1, t_dcl_list **list2)
{
	int	flag1;
	int	flag2;

	flag1 = swap_list(list1);
	flag2 = swap_list(list2);
	if (flag1 == ERROR || flag2 == ERROR)
		return (ERROR);
	return (SUCCESS);
}
