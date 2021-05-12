/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 13:21:40 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/05/06 14:12:50 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_result_and_exit(int mode, t_dcl_list **list, t_command **command, \
						int free_target)
{
	if (mode == SUCCESS)
		write(1, "OK\n", 3);
	else if (mode == KO)
		write(1, "KO\n", 3);
	else if (mode == ERROR)
		write(2, "Error\n", 6);
	if (free_target > 0)
		free_list(list);
	if (free_target > 1)
		free_command(command);
	exit(0);
}

int	sort_list(int list_len, t_dcl_list *list, t_command **command)
{
	int	flag;

	if (list_len < 6)
		flag = bfs(list, command);
	else
		flag = qs_two_stack(list, command, list_len);
	if (flag || *command == NULL)
		return (ERROR);
	(*command)->len = (*command)->point;
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_dcl_list	*list;
	t_command	*command;

	if (argc == 1)
		return (0);
	if (make_new_element(&list, NULL))
		put_result_and_exit(ERROR, NULL, NULL, 0);
	if (check_argment(argc, argv, &list))
		put_result_and_exit(ERROR, &list, NULL, 1);
	if (!is_sorted_list(list))
		put_result_and_exit(-1, &list, NULL, 1);
	if (sort_list(argc - 1, list, &command))
		put_result_and_exit(ERROR, &list, &command, 2);
	if (print_commands(command))
		put_result_and_exit(ERROR, &list, &command, 2);
	free_list(&list);
	free_command(&command);
}
