/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alhorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprysiaz <tprysiaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 19:33:32 by tprysiaz          #+#    #+#             */
/*   Updated: 2017/04/28 20:10:20 by tprysiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_issort(t_str *lst)
{
	int i;

	i = -1;
	if (!ft_check_array_sort(lst->a, lst->size) && !lst->b_size)
	{
		ft_strcat(lst->buf, "\0");
		check_string(lst->buf);
		allmighty_free(lst);
		while (lst->buf[++i])
			write(1, &lst->buf[i], 1);
		exit(15);
	}
	return (1);
}

void	ft_push_to_a_add(t_str *lst, int len)
{
	int l;
	int med;
	int b_len;

	l = 0;
	b_len = len;
	med = ft_mediana(lst->b, len);
	while (ft_check_less_med(med, lst->a, b_len, 0) && ft_issort(lst))
	{
		if (lst->b[0] > med && ft_strcat(lst->buf, "pa\n"))
			ft_pa_pb(lst, "pa");
		else if (ft_strcat(lst->buf, "rb\n") && ++l)
			ft_ra_rb_rr(lst, "rb");
		b_len--;
	}
	if (l && l < lst->b_size - l && lst->a_size != len)
		while (l-- && ft_strcat(lst->buf, "rrb\n"))
			ft_rra_rrb_rrr(lst, "rrb");
	else if (l && l >= lst->b_size - l && lst->a_size != len)
		while (lst->b_size - l > 0 && l++ && ft_strcat(lst->buf, "rb\n"))
			ft_ra_rb_rr(lst, "rb");
	ft_push_to_stack_b(lst, len - (len / 2));
	ft_push_to_stack_a(lst, len / 2);
}

void	ft_push_to_stack_a(t_str *lst, int len)
{
	ft_issort(lst);
	if (len == 2)
	{
		if (lst->b[0] < lst->b[1] && ft_strcat(lst->buf, "sb\npa\npa\n"))
			ft_sa_sb_ss(lst, "sb");
		else
			ft_strcat(lst->buf, "pa\npa\n");
		ft_pa_pb(lst, "pa");
		ft_pa_pb(lst, "pa");
	}
	else if (len == 3)
		ft_sort_3_in_stack_b(lst, lst->b);
	else if (len == 4 && lst->a[3] == ft_max(lst->b, (unsigned)len))
	{
		ft_sort_3_in_stack_b(lst, lst->b);
		ft_strcat(lst->buf, "pa\n");
		ft_pa_pb(lst, "pa");
	}
	else
		ft_push_to_a_add(lst, len);
}

void	ft_push_to_b_add(t_str *lst, int len)
{
	int l;
	int med;
	int a_len;

	l = 0;
	a_len = len;
	med = ft_mediana(lst->a, len);
	while (ft_check_less_med(med, lst->a, a_len, 1) && ft_issort(lst))
	{
		if (lst->a[0] <= med && ft_strcat(lst->buf, "pb\n"))
			ft_pa_pb(lst, "pb");
		else if (ft_strcat(lst->buf, "ra\n") && ++l)
			ft_ra_rb_rr(lst, "ra");
		a_len--;
	}
	if (l && l < lst->a_size - l && lst->a_size != len)
		while (l-- && ft_strcat(lst->buf, "rra\n") && ft_issort(lst))
			ft_rra_rrb_rrr(lst, "rra");
	else if (l && l > lst->a_size - l && lst->a_size != len)
		while (lst->a_size - l > 0 && l++ && ft_strcat(lst->buf, "ra\n") &&
		ft_issort(lst))
			ft_ra_rb_rr(lst, "ra");
	ft_push_to_stack_b(lst, len - len / 2);
	ft_push_to_stack_a(lst, len / 2);
}

void	ft_push_to_stack_b(t_str *lst, int len)
{
	ft_issort(lst);
	if (ft_check_array_sort(lst->a, len) == 0)
		return ;
	if (len == 2 && lst->a[0] > lst->a[1] && ft_strcat(lst->buf, "sa\n"))
		ft_sa_sb_ss(lst, "sa");
	else if (len == 3 && lst->a_size == len)
		ft_sort_3(lst, lst->a);
	else if (len == 3 && lst->a_size > len)
		ft_sort_3_in_stack_a(lst, lst->a);
	else if (len == 4 && lst->a[3] == ft_max(lst->a, (unsigned)len))
		ft_sort_3_in_stack_a(lst, lst->a);
	else if (len >= 4)
		ft_push_to_b_add(lst, len);
}
