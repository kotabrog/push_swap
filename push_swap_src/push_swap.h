/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 13:18:20 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/05/05 09:33:05 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

# include <stdio.h>

# define SUCCESS 0
# define ERROR 1
# define KO 2
# define BUFF_SIZE 1024
# define COMMAND_SIZE 64
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

typedef struct s_dcl_set {
	t_command			*command;
	t_dcl_list			*list1;
	t_dcl_list			*list2;
	int					min_value;
	struct s_dcl_set	*next;
	struct s_dcl_set	*prev;
}						t_dcl_set;

int			ft_isdigit(int c);
int			ft_strchr_n(const char *s, int c);
void		ft_strcpy(char *p, char const *s, size_t n);
void		int_cpy(int *p, const int *s, size_t n);
size_t		ft_strlen(const char *s);
int			ft_malloc(void *pointer, size_t type_size, size_t n);
int			ft_free(void *pointer);
int			expand_malloc(char **s, size_t cpy_n, size_t after_n);

int			set_int_data(t_int_data **data);
int			set_int(char *s, t_int_data *data, t_num *num);

int			check_argment(int argc, char **argv, t_dcl_list **list);
int			check_duplicate(t_dcl_list *list);
void		replacement_to_index(t_dcl_list *list, int *array);

int			command_init(t_command **command);
void		free_command(t_command **command);
int			print_commands(t_command *command);

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

t_dcl_list	*list_cpy(t_dcl_list *list);

int			operate_one_command(t_dcl_list **list1, t_dcl_list **list2, \
							char command);
int			operate_commands(t_dcl_list **list, t_command *command);

t_command	*command_cpy(t_command *command);
int			command_update(t_command *command, char flag);

int			set_init(t_dcl_set **list, t_command *cmd, \
			t_dcl_list *list1, t_dcl_list *list2);
void		set_push_element(t_dcl_set **list, t_dcl_set *element);
int			set_push(t_dcl_set **list, t_command *cmd, \
			t_dcl_list *list1, t_dcl_list *list2);
void		set_push_back_element(t_dcl_set **list, t_dcl_set *element);
int			set_push_back(t_dcl_set **list, t_command *cmd, \
			t_dcl_list *list1, t_dcl_list *list2);

t_dcl_set	*set_pop_list(t_dcl_set **list);
void		set_free_list(t_dcl_set **list);
t_dcl_set	*set_cpy(t_dcl_set *list);
int			set_cpy_element(t_dcl_set **dst, t_dcl_set *src);
void		set_free_element(t_dcl_set **list);

int			bfs(t_dcl_list *list, t_command **command);
int			qs_two_stack(t_dcl_list *list, t_command **command, int list_len);
int			command_refactoring(t_command *cmd);

int			command_loop(t_dcl_set *set, int n, char flag);
int			push_and_rotate_loop(t_dcl_set *set, int n);

int			qs_second_half(t_dcl_set *set, int end, int *middle);
int			qs_first_half(t_dcl_set *set, int *start, int end, int middle);
int			first_qs_first_half(t_dcl_set *set, int n, int middle);

int			swap_bfs(t_dcl_set *set);
int			swap_bfs_flag(t_dcl_set *set);
int			bfs_qs(t_dcl_set *set, int start, int end);

#endif
