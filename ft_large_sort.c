/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_large_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 15:21:31 by pjacob            #+#    #+#             */
/*   Updated: 2021/06/07 12:53:55 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	push_min_on_top(t_pile *a)
{
	int	med;

	med = a->nbr / 2;
	if (a->p_min < med)
	{
		while (a->p_min > 0)
		{
			rotate(a);
			ft_putstr_fd("ra\n", STDOUT_FILENO);
			a->p_min--;
		}
	}
	else
	{
		while (a->p_min < a->nbr)
		{
			reverse(a);
			ft_putstr_fd("rra\n", STDOUT_FILENO);
			a->p_min++;
		}
	}	
}

static void	push_back(t_pile *h_a, t_pile *h_b)
{
	find_all(h_a);
	find_all(h_b);
	while (h_b->nbr)
	{
		if (h_b->first->n < h_a->max && h_b->first->n > h_a->min)
		{
			push_inter(h_a, h_b);
			push(h_b, h_a);
			ft_putstr_fd("pa\n", STDOUT_FILENO);
		}
		else
		{
			push_min_on_top(h_a);
			push(h_b, h_a);
			ft_putstr_fd("pa\n", STDOUT_FILENO);
		}
		find_all(h_a);
		find_all(h_b);
	}
}

static void	push_and_check(t_pile *a, t_pile *b)
{
	push(a, b);
	ft_putstr_fd("pb\n", STDOUT_FILENO);
	find_all(b);
	if (b->first->next)
	{
		if (b->first->n < b->first->next->n)
		{
			swap(b);
			ft_putstr_fd("sb\n", STDOUT_FILENO);
		}
	}
}

void	push_digit(t_pile *a, t_pile *b)
{
	int	med;
	int	pos;

	med = a->nbr / 2;
	pos = (int)a->c_pos;
	if (pos < med)
	{
		while (pos > 0)
		{
			rotate(a);
			ft_putstr_fd("ra\n", STDOUT_FILENO);
			pos--;
		}
		push_and_check(a, b);
	}
	else
	{
		while (pos < a->nbr)
		{
			reverse(a);
			ft_putstr_fd("rra\n", STDOUT_FILENO);
			pos++;
		}
		push_and_check(a, b);
	}
}

void	large_sort(t_pile *h_a, t_pile *h_b)
{
	find_all(h_a);
	find_all(h_b);
	first_chunk(h_a);
	parse_chunk(h_a, h_b);
	sort_before_push_back(h_a, h_b);
	push_back(h_a, h_b);
	find_all(h_b);
	final_sort(h_a, h_b);
}
