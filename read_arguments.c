/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_arguments.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprysiaz <tprysiaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 21:39:01 by tprysiaz          #+#    #+#             */
/*   Updated: 2017/05/06 18:36:06 by tprysiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ps_ft_atoi(char *str)
{
	int		s;
	long	numb;

	s = 1;
	numb = 0;
	while (IS_S_N_T(*str) || IS_F_R_V(*str))
		str++;
	if (*str == '-')
	{
		s = -1;
		str++;
	}
	while (IS_DIGIT(*str))
	{
		numb = numb * 10 + (*str++ - '0');
		if ((numb > 2147483647) || (numb * s < -2147483648))
			exit(write(1, "Argument is over or less INT\n", 29));
	}
	if (*str && !(IS_DIGIT(*str)) && !(IS_S_N_T(*str) || IS_F_R_V(*str)))
		exit(write(2, "Not valid arguments\n", 20));
	return (numb * s);
}

int		ps_ft_atoi_file(char **str)
{
	int		s;
	long	numb;

	s = 1;
	numb = 0;
	while (IS_S_N_T(**str) || IS_F_R_V(**str))
		(*str)++;
	if (**str == '-')
	{
		s = -1;
		(*str)++;
	}
	while (IS_DIGIT(**str))
	{
		numb = numb * 10 + (*(*str)++ - '0');
		if ((numb > 2147483647) || (numb * s < -2147483648))
			exit(write(1, "Argument is over or less INT\n", 29));
	}
	if (**str && !(IS_DIGIT(**str)) && !(IS_S_N_T(**str) || IS_F_R_V(**str)))
		exit(write(2, "Not valid arguments\n", 20));
	return (numb * s);
}

int		ft_strlen_arr(char *s)
{
	int i;
	int k;
	int n;

	i = -1;
	n = 0;
	while (s[++i])
	{
		k = 0;
		while ((IS_S_N_T(s[i]) || IS_F_R_V(s[i])) && ++i)
			k++;
		if (((IS_DIGIT(s[i])) || (s[i] == '-' && IS_DIGIT(s[i + 1]))) && ++i)
		{
			n++;
			k++;
			while (s[i] >= 48 && s[i] <= 57)
				i++;
		}
		if (s[i] && !(IS_S_N_T(s[i]) || IS_F_R_V(s[i])))
			exit(write(2, "Not valid arguments\n", 20));
		k > 0 ? --i : 0;
	}
	return (n);
}

void	ft_flag_s_write(t_str *lst, char *s, char *ag)
{
	int		len;
	int		fd;
	char	*line;
	int		i;

	i = -1;
	len = 0;
	fd = open(ag, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		len += ft_strlen_arr(line);
		s = ft_strcat(s, line);
		free(line);
	}
	free(line);
	lst->a = (int *)malloc(sizeof(int) * len);
	lst->b = (int *)malloc(sizeof(int) * len);
	lst->temp_a = lst->a;
	lst->temp_b = lst->b;
	while (*s)
		lst->a[++i] = ps_ft_atoi_file(&s);
	lst->size = len;
}

void	ft_flag_s_read(char *ag, t_str *lst)
{
	int		len;
	int		fd;
	int		res;
	char	buf[BUFF_SIZE + 1];
	char	*s;

	len = 0;
	fd = open(ag, O_RDONLY);
	while ((res = read(fd, buf, BUFF_SIZE)) > 0)
		len += res;
	if (fd < 0)
		exit(write(1, "There is no such file\n", 22));
	if (len < 1)
		exit(write(1, "Empty file\n", 11));
	close(fd);
	s = (char *)malloc(sizeof(char) * len + 1);
	ft_flag_s_write(lst, s, ag);
	free(s);
}
