/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tool.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 16:06:55 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/05/04 20:20:07 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dcl_list	*list_cpy(t_dcl_list *list)
{
	t_dcl_list	*out;

	if (make_new_element(&out, NULL))
		return (NULL);
	if (list->v == NULL)
		return (out);
	list = (list->prev)->prev;
	while (list->v)
	{
		if (push_int(&out, *(list->v)))
		{
			free_list(&out);
			return (NULL);
		}
		list = list->prev;
	}
	return (out);
}
