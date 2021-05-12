/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_tool1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 01:00:42 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/05/04 22:04:22 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

char	**make_put_command_array(void)
{
	char	**command_array;

	if (ft_malloc(&command_array, sizeof(char *), 13))
		return (NULL);
	command_array[COMMAND_SA] = "sa";
	command_array[COMMAND_SB] = "sb";
	command_array[COMMAND_SS] = "ss";
	command_array[COMMAND_PA] = "pa";
	command_array[COMMAND_PB] = "pb";
	command_array[COMMAND_RA] = "ra";
	command_array[COMMAND_RB] = "rb";
	command_array[COMMAND_RR] = "rr";
	command_array[COMMAND_RRA] = "rra";
	command_array[COMMAND_RRB] = "rrb";
	command_array[COMMAND_RRR] = "rrr";
	return (command_array);
}

int	print_commands(t_command *command)
{
	int		i;
	char	**command_array;
	char	*temp;

	command_array = make_put_command_array();
	if (command_array == NULL)
		return (ERROR);
	i = 0;
	while (i < command->len)
	{
		temp = command_array[(int)(command->list)[i]];
		write(1, temp, ft_strlen(temp));
		write(1, "\n", 1);
		++i;
	}
	free(command_array);
	return (SUCCESS);
}
