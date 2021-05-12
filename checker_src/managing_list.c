/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   managing_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 21:53:50 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/05/04 19:43:56 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	make_new_element(t_dcl_list **list, int *v)
{
	if (ft_malloc(list, sizeof(t_dcl_list), 1))
		return (ERROR);
	(*list)->v = v;
	(*list)->next = *list;
	(*list)->prev = *list;
	return (SUCCESS);
}

int	int_to_element(t_dcl_list **list, int v)
{
	int	*p;

	if (ft_malloc(&p, sizeof(int), 1))
		return (ERROR);
	*p = v;
	if (make_new_element(list, p))
	{
		ft_free(&p);
		return (ERROR);
	}
	return (SUCCESS);
}

void	free_list(t_dcl_list **list)
{
	t_dcl_list	*temp;

	if (*list == NULL)
		return ;
	while ((*list)->v)
	{
		ft_free(&((*list)->v));
		temp = *list;
		*list = (*list)->next;
		ft_free(&temp);
	}
	ft_free(list);
	*list = NULL;
}

int	is_sorted_list(t_dcl_list *list)
{
	int	temp;

	if (list->v == NULL)
		return (SUCCESS);
	temp = *(list->v);
	list = list->next;
	while (list->v)
	{
		if (temp > *(list->v))
			return (KO);
		temp = *(list->v);
		list = list->next;
	}
	return (SUCCESS);
}

int	len_list(t_dcl_list *list)
{
	int	i;

	i = 0;
	while (list->v)
	{
		list = list->next;
		++i;
	}
	return (i);
}
