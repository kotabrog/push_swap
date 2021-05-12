/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 13:18:20 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/05/05 09:31:49 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

# define SUCCESS 0
# define ERROR 1
# define KO 2
# define BUFF_SIZE 1024
# define COMMAND_SIZE 1024
# define COMMAND_NEXT 0
# define COMMAND_SA 2
# define COMMAND_SB 3
# define COMMAND_SS 4
# define COMMAND_PA 5
# define COMMAND_PB 6
# define COMMAND_RA 7
# define COMMAND_RB 8
# define COMMAND_RR 9
# define COMMAND_RRA 10
# define COMMAND_RRB 11
# define COMMAND_RRR 12

typedef struct s_dcl_list {
	int					*v;
	struct s_dcl_list	*next;
	struct s_dcl_list	*prev;
}						t_dcl_list;

typedef struct s_int_data {
	int					number_of_digits;
	int					int_max_over_ten;
	int					first_digit_of_int_max;
}						t_int_data;

typedef struct s_num {
	int					v;
	int					digits;
	int					sign;
}						t_num;

typedef struct s_command {
	char				*list;
	int					len;
	int					point;
}						t_command;

int			ft_isdigit(int c);
int			ft_strchr_n(const char *s, int c);
void		ft_strcpy(char *p, char const *s, size_t n);
void		int_cpy(int *p, const int *s, size_t n);
int			ft_malloc(void *pointer, size_t type_size, size_t n);
int			ft_free(void *pointer);
int			expand_malloc(char **s, size_t cpy_n, size_t after_n);

int			set_int_data(t_int_data **data);
int			set_int(char *s, t_int_data *data, t_num *num);

int			check_argment(int argc, char **argv, t_dcl_list **list);
int			check_duplicate(t_dcl_list *list);

int			read_and_parse(t_command *command);

int			command_init(t_command **command);
void		free_command(t_command **command);
int			update_command(t_command *command, char flag);

int			make_new_element(t_dcl_list **list, int *v);
int			int_to_element(t_dcl_list **list, int v);
void		free_list(t_dcl_list **list);
int			is_sorted_list(t_dcl_list *list);
int			len_list(t_dcl_list *list);

void		push_element(t_dcl_list **list, t_dcl_list *element);
void		push_back_element(t_dcl_list *list, t_dcl_list *element);
int			push_int(t_dcl_list **list, int v);
t_dcl_list	*pop_list(t_dcl_list **list);
int			push_to_anather_list(t_dcl_list **giver, t_dcl_list **receiver);

int			swap_list(t_dcl_list **list);
int			swap_two_list(t_dcl_list **list1, t_dcl_list **list2);

int			rotate_list(t_dcl_list **list);
int			rotate_two_list(t_dcl_list **list1, t_dcl_list **list2);
int			rotate_reverse_list(t_dcl_list **list);
int			rotate_reverse_two_list(t_dcl_list **list1, t_dcl_list **list2);

int			operate_commands(t_dcl_list **list, t_command *command);

#endif
