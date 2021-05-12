/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_tool3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 15:04:16 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/05/04 22:05:50 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_command	*command_cpy(t_command *command)
{
	t_command	*temp;

	temp = (t_command *)malloc(sizeof(t_command));
	if (temp == NULL)
		return (NULL);
	temp->list = (char *)malloc(command->len);
	if (temp->list == NULL)
	{
		free(temp);
		return (NULL);
	}
	ft_strcpy(temp->list, command->list, command->point);
	temp->len = command->len;
	temp->point = command->point;
	return (temp);
}

int	command_update(t_command *command, char flag)
{
	char	*temp;

	if (command->len == command->point)
	{
		temp = (char *)malloc(command->len + COMMAND_SIZE);
		if (temp == NULL)
			return (ERROR);
		ft_strcpy(temp, command->list, command->len);
		free(command->list);
		command->list = temp;
		temp = NULL;
		command->len += COMMAND_SIZE;
	}
	(command->list)[command->point] = flag;
	++(command->point);
	return (SUCCESS);
}

void	command_delete_push(t_command *cmd)
{
	int		check_num;

	cmd->point = 0;
	check_num = 1;
	while (check_num < cmd->len)
	{
		if (((cmd->list)[cmd->point] == COMMAND_PA && \
			(cmd->list)[check_num] == COMMAND_PB) || \
			((cmd->list)[cmd->point] == COMMAND_PB && \
			(cmd->list)[check_num] == COMMAND_PA))
		{
			(cmd->list)[cmd->point] = 0;
			(cmd->list)[check_num] = 0;
			++check_num;
			while (cmd->point != 0 && (cmd->list)[cmd->point] == 0)
				--(cmd->point);
		}
		else
		{
			++(cmd->point);
			if (check_num == cmd->point)
				++check_num;
		}
	}
}

void	command_refactor_rotate(t_command *cmd)
{
	int		check_num;

	cmd->point = 0;
	check_num = 1;
	while (check_num < cmd->len)
	{
		if (((cmd->list)[cmd->point] == COMMAND_RA && \
			(cmd->list)[check_num] == COMMAND_RB) || \
			((cmd->list)[cmd->point] == COMMAND_RB && \
			(cmd->list)[check_num] == COMMAND_RA))
		{
			(cmd->list)[cmd->point] = COMMAND_RR;
			(cmd->list)[check_num] = 0;
			cmd->point = check_num + 1;
			check_num += 2;
		}
		else
		{
			if ((cmd->list)[check_num] != 0)
				cmd->point = check_num;
			++check_num;
		}
	}
}

int	command_refactoring(t_command *cmd)
{
	int		i;
	char	*list;

	command_delete_push(cmd);
	command_refactor_rotate(cmd);
	list = (char *)malloc(cmd->len);
	if (list == NULL)
		return (ERROR);
	i = 0;
	cmd->point = 0;
	while (cmd->point < cmd->len)
	{
		if ((cmd->list)[cmd->point] != 0)
		{
			list[i] = (cmd->list)[cmd->point];
			++i;
		}
		++(cmd->point);
	}
	free(cmd->list);
	cmd->list = list;
	cmd->len = i;
	cmd->point = 0;
	return (SUCCESS);
}
