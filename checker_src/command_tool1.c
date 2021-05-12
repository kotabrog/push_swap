/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   managing_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 01:00:42 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/05/04 19:41:32 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	command_init(t_command **command)
{
	if (ft_malloc(command, sizeof(t_command), 1))
		return (ERROR);
	if (ft_malloc(&((*command)->list), sizeof(char), COMMAND_SIZE))
	{
		ft_free(command);
		return (ERROR);
	}
	(*command)->len = COMMAND_SIZE;
	(*command)->point = 0;
	return (SUCCESS);
}

void	free_command(t_command **command)
{
	if (*command == NULL)
		return ;
	ft_free(&((*command)->list));
	ft_free(command);
}

int	update_command(t_command *command, char flag)
{
	char	*temp;

	if (command->len == command->point)
	{
		if (ft_malloc(&temp, sizeof(char), command->len + COMMAND_SIZE))
			return (ERROR);
		ft_strcpy(temp, command->list, command->len);
		ft_free(&(command->list));
		command->list = temp;
		temp = NULL;
		command->len += COMMAND_SIZE;
	}
	(command->list)[command->point] = flag;
	++(command->point);
	return (SUCCESS);
}
