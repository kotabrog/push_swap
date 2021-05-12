/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 22:14:31 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/05/04 20:07:32 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	decide_which_command(int i, int j, int k)
{
	if (i == 0 && j == 0 && k == 3)
		return (COMMAND_SA);
	if (i == 0 && j == 1 && k == 3)
		return (COMMAND_SB);
	if (i == 0 && j == 2 && k == 3)
		return (COMMAND_SS);
	if (i == 1 && j == 0 && k == 3)
		return (COMMAND_PA);
	if (i == 1 && j == 1 && k == 3)
		return (COMMAND_PB);
	if (i == 2 && j == 0 && k == 3)
		return (COMMAND_RA);
	if (i == 2 && j == 1 && k == 3)
		return (COMMAND_RB);
	if (i == 2 && j == 3 && k == 3)
		return (COMMAND_RR);
	if (i == 2 && j == 3 && k == 0)
		return (COMMAND_RRA);
	if (i == 2 && j == 3 && k == 1)
		return (COMMAND_RRB);
	if (i == 2 && j == 3 && k == 2)
		return (COMMAND_RRR);
	return (ERROR);
}

char	parse_line(ssize_t n, char *buf)
{
	int	i;
	int	j;
	int	k;

	i = ft_strchr_n("spr", *buf);
	j = ft_strchr_n("absr", *(buf + 1));
	k = ft_strchr_n("abr\n", *(buf + 2));
	if (i == -1 || j == -1 || k == -1)
		return (ERROR);
	if (k == 3)
		return (decide_which_command(i, j, k));
	else if (n == 3 || *(buf + 3) != '\n')
		return (ERROR);
	return (decide_which_command(i, j, k));
}

int	parse_input(t_command *command, ssize_t n, char *buf)
{
	char	flag;
	int		i;

	i = 0;
	while (i < n)
	{
		if (n - i < 3)
			return (ERROR);
		flag = parse_line(n - i, buf + i);
		if (flag == ERROR)
			return (ERROR);
		if (flag < 10)
			i += 3;
		else
			i += 4;
		if (update_command(command, flag))
			return (ERROR);
	}
	return (SUCCESS);
}

int	read_input(char **s, ssize_t *total)
{
	ssize_t	n;
	char	*buf;

	if (ft_malloc(&buf, sizeof(char), BUFF_SIZE))
		return (ERROR);
	while (1)
	{
		n = read(0, buf, BUFF_SIZE);
		if (n <= 0)
			break ;
		if ((n + *total) / BUFF_SIZE > *total / BUFF_SIZE)
		{
			if (expand_malloc(s, *total, \
					BUFF_SIZE * ((n + *total) / BUFF_SIZE + 1)))
			{
				free(buf);
				return (ERROR);
			}
		}
		ft_strcpy(*s + *total, buf, n);
		*total += n;
	}
	free(buf);
	return (n < 0);
}

int	read_and_parse(t_command *command)
{
	char	*temp;
	ssize_t	n;

	if (ft_malloc(&temp, sizeof(char), BUFF_SIZE))
		return (ERROR);
	n = 0;
	if (read_input(&temp, &n))
	{
		free(temp);
		return (ERROR);
	}
	n = parse_input(command, n, temp);
	free(temp);
	command->len = command->point;
	command->point = 0;
	return (n);
}
