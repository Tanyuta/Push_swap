/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprysiaz <tprysiaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 16:21:12 by tprysiaz          #+#    #+#             */
/*   Updated: 2017/05/06 19:03:41 by tprysiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_zeroer(t_str *lst)
{
	int counter;

	counter = 100000;
	while (counter-- >= 0)
		lst->buf[counter] = 0;
}

void	ft_flags_push_swap(char **ag, t_str *lst)
{
	int i;
	int j;

	j = -1;
	if ((i = 0) || ag[1][1] != 's')
	{
		lst->a = (int*)malloc(sizeof(int) * (lst->size));
		lst->b = (int*)malloc(sizeof(int) * (lst->size));
		while (ag[++i])
			while (*ag[i])
			{
				while (IS_S_N_T(*ag[i]) || IS_F_R_V(*ag[i]))
					ag[i]++;
				if (!*ag[i] && !ag[i])
					break ;
				lst->a[++j] = ps_ft_atoi(ag[i]);
				while (IS_DIGIT(*ag[i]) || *ag[i] == '-')
					ag[i]++;
			}
	}
	else
	{
		lst->flag[0] = ag[1][1];
		ft_flag_s_read(ag[2], lst);
	}
}

int		main(int ac, char **ag)
{
	int		i;
	t_str	lst;

	lst.size = ft_size_count(ac, ag);
	ft_zeroer(&lst);
	if (ac <= 1)
		exit(write(1, "No arguments\n", 13));
	ft_flags_push_swap(ag, &lst);
	lst.a_size = lst.size;
	if (lst.size < 1 && lst.flag[0] == 's')
		exit(write(1, "Error\n", 6));
	ft_dublicate(lst.a, lst.size);
	ft_push_to_stack_b(&lst, lst.size);
	ft_strcat(lst.buf, "\0");
	check_string(lst.buf);
	i = -1;
	while (lst.buf[++i])
		write(1, &lst.buf[i], 1);
	allmighty_free(&lst);
	return (0);
}
