/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkisala <mkisala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:32:22 by mkisala           #+#    #+#             */
/*   Updated: 2026/02/23 17:43:27 by mkisala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

long	ft_atol(const char *str, int *err)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	*err = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!(*str >= '0' && *str <= '9'))
		*err = 1;
	while (!*err && *str >= '0' && *str <= '9')
	{
		if (res > (LONG_MAX - (*str - '0')) / 10)
			*err = 1;
		res = res * 10 + (*str++ - '0');
	}
	if (*str != '\0' || res > INT_MAX || res < INT_MIN)
		*err = 1;
	return (res * sign);
}

int	is_sorted(t_stack *a)
{
	t_node	*tmp;
	int		i;

	tmp = a->top;
	i = 0;
	while (i < a->size - 1)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

static int	total_len(int ac, char **av)
{
	int	len;
	int	i;

	len = 0;
	i = 1;
	while (i < ac)
	{
		len += ft_strlen(av[i]);
		if (i < ac - 1)
			len++;
		i++;
	}
	return (len);
}

char	*ft_strjoin_args(int ac, char **av)
{
	int		len;
	char	*res;
	int		pos;
	int		i;
	int		j;

	len = total_len(ac, av);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	pos = 0;
	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
			res[pos++] = av[i][j++];
		if (i < ac - 1)
			res[pos++] = ' ';
		i++;
	}
	res[pos] = '\0';
	return (res);
}
