/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 13:21:40 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/05/04 21:58:09 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	if (command_init(&command))
		put_result_and_exit(ERROR, &list, NULL, 1);
	if (read_and_parse(command))
		put_result_and_exit(ERROR, &list, &command, 2);
	operate_commands(&list, command);
	if (!is_sorted_list(list) && argc - 1 == len_list(list))
		put_result_and_exit(SUCCESS, &list, &command, 2);
	else
		put_result_and_exit(KO, &list, &command, 2);
}
