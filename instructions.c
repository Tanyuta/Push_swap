/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprysiaz <tprysiaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 21:36:50 by tprysiaz          #+#    #+#             */
/*   Updated: 2017/04/28 19:06:33 by tprysiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_buffer(t_str *lst)
{
	int i;

	i = 100000;
	while (--i > 0 && !(lst->buf[i]))
		;
	if (i > 86000)
	{
		i = -1;
		ft_strcat(lst->buf, "\0");
		check_string(lst->buf);
		while (lst->buf[++i])
			write(1, &lst->buf[i], 1);
		ft_bzero(lst->buf, 100000);
	}
}

int		ft_sa_sb_ss(t_str *lst, char *instruction)
{
	int tmp;

	ft_buffer(lst);
	if (!STRCMP(instruction, "sa") && lst->a_size > 1)
	{
		tmp = lst->a[0];
		lst->a[0] = lst->a[1];
		lst->a[1] = tmp;
	}
	else if (!STRCMP(instruction, "sb") && lst->b_size > 1)
	{
		tmp = lst->b[0];
		lst->b[0] = lst->b[1];
		lst->b[1] = tmp;
	}
	else if (!STRCMP(instruction, "ss"))
	{
		ft_sa_sb_ss(lst, "sa");
		ft_sa_sb_ss(lst, "sb");
	}
	return (0);
}

int		ft_pa_pb(t_str *lst, char *instruction)
{
	int i;
	int j;

	j = -1;
	ft_buffer(lst);
	i = (instruction[1] == 'a') ? lst->a_size : lst->b_size;
	if (!STRCMP(instruction, "pa") && lst->b_size)
	{
		while (i-- > 0)
			lst->a[i + 1] = lst->a[i];
		lst->a[0] = lst->b[0];
		while (++j < lst->b_size)
			lst->b[j] = lst->b[j + 1];
		(++lst->a_size) && (lst->b_size--);
	}
	else if (!STRCMP(instruction, "pb") && lst->a_size)
	{
		while (i-- > 0)
			lst->b[i + 1] = lst->b[i];
		lst->b[0] = lst->a[0];
		while (++j < lst->a_size)
			lst->a[j] = lst->a[j + 1];
		(++lst->b_size) && (lst->a_size--);
	}
	return (0);
}

int		ft_ra_rb_rr(t_str *lst, char *instruction)
{
	int tmp;
	int i;

	i = -1;
	ft_buffer(lst);
	if (!STRCMP(instruction, "ra"))
	{
		tmp = lst->a[0];
		while (++i < lst->a_size - 1)
			lst->a[i] = lst->a[i + 1];
		lst->a[i] = tmp;
	}
	else if (!STRCMP(instruction, "rb"))
	{
		tmp = lst->b[0];
		while (++i < lst->b_size - 1)
			lst->b[i] = lst->b[i + 1];
		lst->b[i] = tmp;
	}
	else if (!STRCMP(instruction, "rr"))
	{
		ft_ra_rb_rr(lst, "ra");
		ft_ra_rb_rr(lst, "rb");
	}
	return (0);
}

int		ft_rra_rrb_rrr(t_str *lst, char *instruction)
{
	int tmp;
	int i;
	int last;

	i = -1;
	ft_buffer(lst);
	if (!STRCMP(instruction, "rra"))
	{
		last = lst->a_size;
		tmp = lst->a[last - 1];
		while (--last > 0)
			lst->a[last] = lst->a[last - 1];
		lst->a[last] = tmp;
	}
	else if (!STRCMP(instruction, "rrb"))
	{
		last = lst->b_size;
		tmp = lst->b[last - 1];
		while (--last > 0)
			lst->b[last] = lst->b[last - 1];
		lst->b[last] = tmp;
	}
	else if (!STRCMP(instruction, "rrr"))
		ft_rra_rrb_rrr(lst, "rra") && ft_rra_rrb_rrr(lst, "rrb");
	return (1);
}
