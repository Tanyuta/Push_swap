/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprysiaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 12:28:21 by tprysiaz          #+#    #+#             */
/*   Updated: 2016/11/29 12:28:30 by tprysiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int s;
	int numb;

	s = 1;
	numb = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' ||
		*str == '\f' || *str == '\r' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			s = -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		numb = numb * 10 + (*str - '0');
		str++;
	}
	return (numb * s);
}
