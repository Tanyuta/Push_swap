/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprysiaz <tprysiaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 19:52:05 by tprysiaz          #+#    #+#             */
/*   Updated: 2017/05/06 19:02:24 by tprysiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_size_count(int ac, char **ag)
{
	int		i;
	int		size;
	char	*cur;

	size = 0;
	while (--ac)
	{
		cur = ag[ac];
		i = -1;
		while (cur[++i])
		{
			while (cur[i] &&
				(IS_S_N_T(cur[i]) || IS_F_R_V(cur[i])))
				i++;
			while (cur[i] && IS_DIGIT(cur[i]))
				i++;
			if (IS_DIGIT(cur[i - 1]))
				size++;
			if (!cur[i])
				break ;
		}
	}
	return (size);
}

int		ft_size_count_cheker(int ac, char **ag)
{
	int		i;
	int		size;
	char	*cur;

	if ((size = 0) || (ag[1][0] == '-' && ag[1][1] == 'v'))
		while (--ac > 1)
		{
			cur = ag[ac];
			i = -1;
			while (cur[++i])
			{
				while (cur[i] &&
				(IS_S_N_T(cur[i]) || IS_F_R_V(cur[i])))
					i++;
				while (cur[i] && IS_DIGIT(cur[i]))
					i++;
				if (IS_DIGIT(cur[i - 1]))
					size++;
				if (!cur[i])
					break ;
			}
		}
	else
		return (ft_size_count(ac, ag));
	return (size);
}

void	ft_flag_v_write(t_str *lst)
{
	int i;

	i = -1;
	write(1, "            ", 12);
	write(1, "[a]", 3);
	write(1, "     ", 5);
	write(1, "[b]", 3);
	write(1, "\n", 1);
	while (++i < lst->size)
	{
		write(1, "             ", 13);
		i < lst->a_size ? ft_putnbr(lst->a[i]) : write(1, "-", 1);
		write(1, "       ", 7);
		i < lst->b_size ? ft_putnbr(lst->b[i]) : write(1, "-", 1);
		write(1, "\n", 1);
	}
	write(1, "\n", 1);
}
