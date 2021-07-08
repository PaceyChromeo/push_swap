/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_large_sort_utils1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 14:00:31 by pjacob            #+#    #+#             */
/*   Updated: 2021/06/02 14:00:32 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	search_insert(t_pile *head, int n)
{
	t_pile	*pile;
	t_digit	*tmp;
	int		pos;

	tmp = head->first;
	pile = head;
	pile ->first = tmp;
	find_all(pile);
	pos = 1;
	while (tmp->next)
	{
		if (tmp->n < pile->f_n && tmp->n > pile->l_n)
			return (0);
		else if (tmp->n < n && tmp->next->n > n)
			return (pos);
		pos++;
		tmp = tmp->next;
	}
	return (pos);
}

void	parse_chunk(t_pile *h_a, t_pile *h_b)
{
	while (find_best_digit(h_a) && h_a->nbr > 5)
	{
		push_digit(h_a, h_b);
		find_all(h_a);
	}
	while (next_chunk(h_a) && h_a->nbr > 5)
	{
		find_all(h_a);
		while (find_best_digit(h_a))
		{
			push_digit(h_a, h_b);
			find_all(h_a);
		}
	}
}

void	sort_before_push_back(t_pile *h_a, t_pile *h_b)
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
	else if (h_a->nbr > 3)
	{
		if (h_a->nbr > 5)
		{
			while (h_a->nbr > 5)
			{
				push(h_a, h_b);
				ft_putendl_fd("pb", STDOUT_FILENO);
				h_a->nbr--;
			}
		}
		medium_sort(h_a, h_b);
	}
}

void	push_inter(t_pile *h_a, t_pile *h_b)
{
	int	pos;

	pos = search_insert(h_a, h_b->first->n);
	if (pos)
	{
		if (pos <= h_a->nbr / 2)
		{
			while (pos > 0)
			{
				rotate(h_a);
				ft_putstr_fd("ra\n", STDOUT_FILENO);
				pos--;
			}
		}
		else
		{
			while (pos < h_a->nbr)
			{
				reverse(h_a);
				ft_putstr_fd("rra\n", STDOUT_FILENO);
				pos++;
			}
		}
	}
}

void	final_sort(t_pile *h_a, t_pile *h_b)
{
	if (h_b->nbr == 1)
	{
		push(h_b, h_a);
		ft_putendl_fd("pa", STDOUT_FILENO);
		if (h_a->first->n > h_a->first->next->n)
		{
			swap(h_a);
			ft_putendl_fd("sa", STDOUT_FILENO);
		}
	}
	if (h_a->p_min != 0)
		push_min_on_top(h_a);
}
