/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprysiaz <tprysiaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 18:26:46 by tprysiaz          #+#    #+#             */
/*   Updated: 2017/05/06 19:01:40 by tprysiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_initializer(t_str *lst)
{
	lst->size = 0;
	lst->funcs.str[0] = "sa";
	lst->funcs.funcs[0] = &ft_sa_sb_ss;
	lst->funcs.str[1] = "sb";
	lst->funcs.funcs[1] = &ft_sa_sb_ss;
	lst->funcs.str[2] = "ss";
	lst->funcs.funcs[2] = &ft_sa_sb_ss;
	lst->funcs.str[3] = "pa";
	lst->funcs.funcs[3] = &ft_pa_pb;
	lst->funcs.str[4] = "pb";
	lst->funcs.funcs[4] = &ft_pa_pb;
	lst->funcs.str[5] = "ra";
	lst->funcs.funcs[5] = &ft_ra_rb_rr;
	lst->funcs.str[6] = "rb";
	lst->funcs.funcs[6] = &ft_ra_rb_rr;
	lst->funcs.str[7] = "rr";
	lst->funcs.funcs[7] = &ft_ra_rb_rr;
	lst->funcs.str[8] = "rra";
	lst->funcs.funcs[8] = &ft_rra_rrb_rrr;
	lst->funcs.str[9] = "rrb";
	lst->funcs.funcs[9] = &ft_rra_rrb_rrr;
	lst->funcs.str[10] = "rrr";
	lst->funcs.funcs[10] = &ft_rra_rrb_rrr;
}

void	ft_read_instruction(t_str *lst)
{
	char	*line;
	int		i;

	while ((i = -1) && get_next_line(0, &line) > 0)
	{
		while (++i < 11 && STRCMP(lst->funcs.str[i], line))
			;
		if (i < 11)
		{
			lst->funcs.funcs[i](lst, lst->funcs.str[i]);
			if (lst->flag[0] == 'v' || lst->flag[1] == 'v')
			{
				write(1, lst->funcs.str[i], 3);
				ft_flag_v_write(lst);
			}
		}
		else
			exit(write(2, "Wrong Command\n", 14));
		free(line);
	}
	free(line);
	(!ft_check_array_sort(lst->a, lst->size) && !lst->b_size) ?
	write(1, "OK\n", 3) : write(1, "KO\n", 3);
}

void	ft_flags_checker(char **ag, t_str *lst, int *i, int ac)
{
	if (ag[1] && ag[1][0] == '-' && (ag[1][1] == 'v' || ag[1][1] == 's'))
	{
		if (ac <= 2)
			exit(write(1, "There is no such file\n", 22));
		lst->flag[0] = ag[1][1];
		if (lst->flag[0] == 's' && ag[2] && ag[2][1] != 'v')
			ft_flag_s_read(ag[2], lst);
		else if (lst->flag[0] == 's' && ag[2] && ag[2][1] == 'v')
			ft_flag_s_read(ag[3], lst);
		else if (lst->flag[0] == 'v')
			*i = 1;
	}
	if (ag[2] && ag[2][0] == '-' && ag[2][1] == 'v' &&
		lst->flag[0] == 's' && ac > 3)
		lst->flag[1] = 'v';
}

void	ft_arg_writer(int i, int j, t_str *lst)
{
	while (lst->ag[++i])
		while (*(lst->ag[i]))
		{
			while (IS_S_N_T(*(lst->ag[i])) || IS_F_R_V(*(lst->ag[i])))
				lst->ag[i]++;
			if (!*(lst->ag[i]))
				break ;
			lst->a[++j] = ps_ft_atoi(lst->ag[i]);
			while (IS_DIGIT(*lst->ag[i]) || *lst->ag[i] == '-')
				lst->ag[i]++;
		}
}

int		main(int ac, char **ag)
{
	int		i;
	int		j;
	t_str	lst;

	i = 0;
	j = -1;
	if ((lst.ac = ac) <= 1)
		exit(write(1, "No arguments\n", 13));
	ft_initializer(&lst);
	ft_flags_checker((lst.ag = ag), &lst, &i, ac);
	if (lst.flag[0] != 's')
	{
		lst.size = ft_size_count_cheker(ac, ag);
		lst.a = (int*)malloc(sizeof(int) * (lst.size));
		lst.b = (int*)malloc(sizeof(int) * (lst.size));
		ft_arg_writer(i, j, &lst);
	}
	if ((lst.a_size = lst.size) == 1)
		exit(write(1, "Only one element!\n", 18));
	else if (lst.size < 1 && lst.flag[0] == 's')
		exit(write(1, "Error\n", 6));
	ft_dublicate(lst.a, lst.size);
	ft_read_instruction(&lst);
	allmighty_free(&lst);
	return (0);
}
