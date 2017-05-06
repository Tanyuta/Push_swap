/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprysiaz <tprysiaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 17:00:36 by tprysiaz          #+#    #+#             */
/*   Updated: 2017/05/06 17:08:23 by tprysiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# define BUFF_SIZE 1
# define STRCMP(x, y) ft_strcmp(x, y)
# define IS_DIGIT(x) x >= 48 && x <= 57 ? 1 : 0
# define IS_S_N_T(x) (x == ' ' || x == '\n' || x == '\t') ? 1 : 0
# define IS_F_R_V(x) (x == '\f' || x == '\r' || x == '\v') ? 1 : 0

typedef struct		s_funcs
{
	int		(*funcs[11])();
	char	*str[11];
}					t_funcs;

typedef	struct		s_str
{
	int		*a;
	int		*b;
	int		*temp_a;
	int		*temp_b;
	char	buf[100000];
	char	flag[2];
	int		size;
	int		a_size;
	int		b_size;
	int		fd;
	int		ac;
	char	**ag;
	t_funcs funcs;
}					t_str;
/*
** push_swap
*/
void				ft_flags_push_swap(char **ag, t_str *lst);
void				ft_zeroer(t_str *lst);
/*
** checker
*/
void				ft_flags_checker(char **ag, t_str *lst, int *i, int ac);
void				ft_read_instruction(t_str *lst);
void				ft_initializer(t_str *lst);
void				ft_arg_writer(int i, int j, t_str *lst);
/*
** alhorithm
*/
void				ft_push_to_stack_b(t_str *lst, int len);
void				ft_push_to_b_add(t_str *lst, int len);
void				ft_push_to_stack_a(t_str *lst, int len);
void				ft_push_to_a_add(t_str *lst, int len);
int					ft_issort(t_str *lst);
/*
** read_arguments
*/
void				ft_flag_s_read(char *ag, t_str *lst);
void				ft_flag_s_write(t_str *lst, char *s, char *ag);
int					ft_strlen_arr(char *s);
int					ps_ft_atoi_file(char **str);
int					ps_ft_atoi(char *str);
/*
** func_for_push_swap
*/
void				quicksort(int *ar, int start, int end);
int					*ft_copy_arr(int *a, int size);
int					ft_check_less_med(int med, int *s, int size, int flag);
int					ft_mediana(int *s, int size);
/*
** instruction
*/
void				ft_buffer(t_str *lst);
int					ft_sa_sb_ss(t_str *lst, char *instruction);
int					ft_pa_pb(t_str *lst, char *instruction);
int					ft_ra_rb_rr(t_str *lst, char *instruction);
int					ft_rra_rrb_rrr(t_str *lst, char *instruction);
/*
** sort_3_elem
*/
void				ft_sort_3(t_str *lst, int *s);
void				ft_sort_3_in_stack_a(t_str *lst, int *s);
void				ft_sort_3_in_stack_b(t_str *lst, int *s);
void				ft_sort_3_in_stack_b_continue(t_str *lst, int *s);
/*
** general_funcs
*/
void				check_string(char *str);
void				put_to_string(char *str, char *s, int l);
int					ft_check_array_sort(int *s, int len);
void				ft_dublicate(int *a, int n);
void				allmighty_free(t_str *lst);
/*
** size_count
*/
int					ft_size_count(int ac, char **ag);
int					ft_size_count_cheker(int ac, char **ag);
void				ft_flag_v_write(t_str *lst);
/*
** G_N_L
*/
int					get_next_line(const int fd, char **line);

#endif
