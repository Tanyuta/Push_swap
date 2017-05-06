/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprysiaz <tprysiaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 19:40:27 by tprysiaz          #+#    #+#             */
/*   Updated: 2017/05/06 18:36:03 by tprysiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_to_string(char *str, char *s, int l)
{
	while (*s)
		*(str++) = *(s++);
	str--;
	while (*(++str + l))
		*str = *(str + l);
	while (--l)
		*(str++) = 0;
}

void	check_string(char *str)
{
	char	*res;

	while ((res = ft_strstr(str, "\npa\npb\n")))
		put_to_string(res, "\n", 6);
	while ((res = ft_strstr(str, "\npb\npa\n")))
		put_to_string(res, "\n", 6);
	while ((res = ft_strstr(str, "\nrra\nra\n")))
		put_to_string(res, "\n", 7);
	while ((res = ft_strstr(str, "sa\nsb")))
		put_to_string(res, "ss", 3);
	while ((res = ft_strstr(str, "sa\nsb")))
		put_to_string(res, "ss", 3);
	while ((res = ft_strstr(str, "\nrrb\nrb\n")))
		put_to_string(res, "\n", 7);
	while ((res = ft_strstr(str, "\nra\nrra\n")))
		put_to_string(res, "\n", 7);
	while ((res = ft_strstr(str, "\nrb\nrrb\n")))
		put_to_string(res, "\n", 7);
	while ((res = ft_strstr(str, "rra\nrrb")))
		put_to_string(res, "rrr", 4);
	while ((res = ft_strstr(str, "rrb\nrra")))
		put_to_string(res, "rrr", 4);
}

void	allmighty_free(t_str *lst)
{
	free(lst->a);
	free(lst->b);
}

void	ft_dublicate(int *a, int n)
{
	int i;
	int j;

	i = -1;
	while (++i < n - 1)
	{
		j = i;
		while (++j < n)
			if (a[i] == a[j])
				exit(write(2, "Duplication of numbers\n", 23));
	}
}

int		ft_check_array_sort(int *s, int len)
{
	while (--len > 0)
		if (s[len] < s[len - 1] && len - 1 >= 0)
			return (len);
	return (0);
}
