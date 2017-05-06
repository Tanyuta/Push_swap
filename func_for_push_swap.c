/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_for_push_swap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprysiaz <tprysiaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 21:44:25 by tprysiaz          #+#    #+#             */
/*   Updated: 2017/05/06 18:36:02 by tprysiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_mediana(int *s, int size)
{
	int med;
	int *copy;

	copy = ft_copy_arr(s, size);
	quicksort(copy, 0, size - 1);
	med = copy[size / 2 - 1];
	free(copy);
	return (med);
}

int			ft_check_less_med(int med, int *s, int size, int flag)
{
	int i;

	i = -1;
	while (++i < size)
		if (flag == 1 && s[i] <= med)
			return (1);
		else if (flag == 0 && s[i] > med)
			return (1);
	return (0);
}

int			*ft_copy_arr(int *a, int size)
{
	int *b;

	b = (int *)malloc(sizeof(int) * size);
	while (--size >= 0)
		b[size] = a[size];
	return (b);
}

static int	ft_partition(int *ar, int start, int end)
{
	int pivot;
	int i;
	int j;

	pivot = ar[end];
	j =
	i = start - 1;
	while (++j < end)
		if (ar[j] <= pivot && ++i != j)
		{
			ar[i] = ar[i] + ar[j];
			ar[j] = ar[i] - ar[j];
			ar[i] = ar[i] - ar[j];
		}
	if (ar[i + 1] != ar[end])
	{
		ar[i + 1] = ar[i + 1] + ar[end];
		ar[end] = ar[i + 1] - ar[end];
		ar[i + 1] = ar[i + 1] - ar[end];
	}
	return (i + 1);
}

void		quicksort(int *ar, int start, int end)
{
	int p;

	if (start < end)
	{
		p = ft_partition(ar, start, end);
		quicksort(ar, start, p - 1);
		quicksort(ar, p + 1, end);
	}
}
