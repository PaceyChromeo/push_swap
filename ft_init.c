/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 16:55:25 by pjacob            #+#    #+#             */
/*   Updated: 2021/06/29 15:57:06 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	check_number(char **av, int index)
{
	int	i;

	if (!av[index])
		return (1);
	while (av[index])
	{
		i = 0;
		if (av[index][i] == '-')
			i++;
		while (av[index][i])
		{
			if (av[index][i] > '9' || av[index][i] < '0')
				return (1);
			i++;
		}
		index++;
	}
	return (0);
}

int	check_digit(char **av, int index)
{
	int			i;
	long int	n;

	n = 0;
	while (av[index])
	{
		if (check_number(av, index) == 1)
			return (1);
		if (ft_strlen(av[index]) > 11)
			return (1);
		n = ft_atoi(av[index]);
		if (n > 2147483647 || n < -2147483648)
			return (1);
		i = index + 1;
		while (av[i])
		{
			if (n == ft_atoi(av[i]))
				return (1);
			i++;
		}
		index++;
	}
	return (0);
}

void	init_piles(t_pile *h_a, t_pile *h_b, char **av, int begin)
{
	h_a->first = digit_init(ft_atoi(av[begin]));
	h_b->first = NULL;
	while (av[++begin])
		add_back(h_a, ft_atoi(av[begin]));
	h_a->nbr = begin;
	find_all(h_a);
}

void	init_arg(t_pile *a, t_pile *b, char **av)
{
	char	**split;
	int		i;

	i = -1;
	split = ft_split(av[1], ' ');
	if (split[0] == NULL)
		exit_error(a, b);
	if (check_digit(split, 0))
	{
		while (split[++i])
			free(split[i]);
		free(split);
		exit_error(a, b);
	}
	init_piles(a, b, split, 0);
	while (split[++i])
		free(split[i]);
	free(split);
}

void	dispatch_sort(t_pile *h_a, t_pile *h_b)
{
	if (h_a->nbr == 2)
	{
		if (h_a->first->n > h_a->first->next->n)
		{
			swap(h_a);
			ft_putstr_fd("sa\n", STDOUT_FILENO);
		}
	}
	else if (h_a->nbr == 3)
		small_sort(h_a);
	else if (h_a->nbr == 4 || h_a->nbr == 5)
		medium_sort(h_a, h_b);
	else
		large_sort(h_a, h_b);
}
