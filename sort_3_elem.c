/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprysiaz <tprysiaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 19:41:18 by tprysiaz          #+#    #+#             */
/*   Updated: 2017/05/06 18:36:08 by tprysiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_str *lst, int *s)
{
	while (!(s[0] < s[1] && s[1] < s[2]) && ft_issort(lst))
	{
		if (s[0] < s[1] && s[1] > s[2] && s[0] > s[2] &&
			ft_strcat(lst->buf, "rra\n"))
			ft_rra_rrb_rrr(lst, "rra");
		else if (s[0] < s[1] && s[1] > s[2] && s[0] < s[2] &&
			ft_strcat(lst->buf, "sa\nra\n"))
		{
			ft_sa_sb_ss(lst, "sa");
			ft_ra_rb_rr(lst, "ra");
		}
		else if (s[0] > s[1] && s[0] > s[2] && s[1] > s[2] &&
			ft_strcat(lst->buf, "sa\nrra\n"))
		{
			ft_sa_sb_ss(lst, "sa");
			ft_rra_rrb_rrr(lst, "rra");
		}
		else if (s[0] > s[1] && s[0] > s[2] && s[1] < s[2] &&
			ft_strcat(lst->buf, "ra\n"))
			ft_ra_rb_rr(lst, "ra");
		else if (s[0] > s[1] && s[1] < s[2] && s[0] < s[2] &&
			ft_strcat(lst->buf, "sa\n"))
			ft_sa_sb_ss(lst, "sa");
	}
}

void	ft_sort_3_in_stack_a(t_str *lst, int *s)
{
	while (!(s[0] < s[1] && s[1] < s[2]) && ft_issort(lst))
	{
		if (s[0] < s[1] && s[1] > s[2])
		{
			ft_strcat(lst->buf, "ra\nsa\nrra\n");
			ft_ra_rb_rr(lst, "ra");
			ft_sa_sb_ss(lst, "sa");
			ft_rra_rrb_rrr(lst, "rra");
			if (s[0] > s[1] && ft_strcat(lst->buf, "sa\n"))
				ft_sa_sb_ss(lst, "sa");
		}
		else if (s[0] > s[1] && s[0] > s[2])
		{
			ft_strcat(lst->buf, "sa\nra\nsa\nrra\n");
			ft_sa_sb_ss(lst, "sa");
			ft_ra_rb_rr(lst, "ra");
			ft_sa_sb_ss(lst, "sa");
			ft_rra_rrb_rrr(lst, "rra");
			if (s[0] > s[1] && ft_strcat(lst->buf, "sa\n"))
				ft_sa_sb_ss(lst, "sa");
		}
		else if (s[0] > s[1] && s[1] < s[2] && s[0] < s[2] &&
			ft_strcat(lst->buf, "sa\n"))
			ft_sa_sb_ss(lst, "sa");
	}
}

void	ft_sort_3_in_stack_b(t_str *lst, int *s)
{
	if (s[0] < s[1] && s[1] > s[2])
	{
		ft_strcat(lst->buf, "sb\npa\n");
		ft_sa_sb_ss(lst, "sb");
		ft_pa_pb(lst, "pa");
		if (s[0] < s[1] && ft_strcat(lst->buf, "sb\n"))
			ft_sa_sb_ss(lst, "sb");
		ft_strcat(lst->buf, "pa\npa\n");
		ft_pa_pb(lst, "pa");
		ft_pa_pb(lst, "pa");
	}
	else if (s[0] > s[1] && s[0] > s[2])
	{
		ft_strcat(lst->buf, "pa\n");
		ft_pa_pb(lst, "pa");
		if (s[0] < s[1] && ft_strcat(lst->buf, "sb\n"))
			ft_sa_sb_ss(lst, "sb");
		ft_strcat(lst->buf, "pa\npa\n");
		ft_pa_pb(lst, "pa");
		ft_pa_pb(lst, "pa");
	}
	else
		ft_sort_3_in_stack_b_continue(lst, s);
}

void	ft_sort_3_in_stack_b_continue(t_str *lst, int *s)
{
	if (s[0] > s[1] && s[1] < s[2] && s[0] < s[2] &&
		ft_strcat(lst->buf, "rb\nrb\npa\nrrb\nrrb\npa\npa\n"))
	{
		ft_ra_rb_rr(lst, "rb");
		ft_ra_rb_rr(lst, "rb");
		ft_pa_pb(lst, "pa");
		ft_rra_rrb_rrr(lst, "rrb");
		ft_rra_rrb_rrr(lst, "rrb");
		ft_pa_pb(lst, "pa");
		ft_pa_pb(lst, "pa");
	}
	else if (s[1] > s[0] && s[2] > s[1] &&
		ft_strcat(lst->buf, "rb\nsb\npa\npa\nrrb\npa\n"))
	{
		ft_ra_rb_rr(lst, "rb");
		ft_sa_sb_ss(lst, "sb");
		ft_pa_pb(lst, "pa");
		ft_pa_pb(lst, "pa");
		ft_rra_rrb_rrr(lst, "rrb");
		ft_pa_pb(lst, "pa");
	}
	ft_issort(lst);
}
