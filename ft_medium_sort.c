/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:16:21 by pjacob            #+#    #+#             */
/*   Updated: 2021/06/29 12:54:04 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	bool_switch(t_pile *head, int bool)
{
	if (bool)
		return (head->p_max);
	else
		return (head->p_min);
}

static void	put_on_top(t_pile *head, int pos, int bool)
{
	if (pos <= 2)
	{
		while (pos)
		{
			rotate(head);
			ft_putstr_fd("ra\n", STDOUT_FILENO);
			find_pos(head);
			pos = bool_switch(head, bool);
		}
	}
	else
	{
		while (pos)
		{
			reverse(head);
			ft_putstr_fd("rra\n", STDOUT_FILENO);
			find_pos(head);
			pos = bool_switch(head, bool);
		}
	}
}

static void	push_extrem(t_pile *h_a, t_pile *h_b)
{
	if (h_a->p_max != 2 || h_a->p_min != 0)
	{
		if (h_a->p_max != 0)
			put_on_top(h_a, h_a->p_max, 1);
		push(h_a, h_b);
		ft_putstr_fd("pb\n", STDOUT_FILENO);
		find_pos(h_a);
		if (h_a->p_min != 0)
			put_on_top(h_a, h_a->p_min, 0);
		push(h_a, h_b);
		ft_putstr_fd("pb\n", STDOUT_FILENO);
	}
	else
	{
		if (h_a->p_min != 0)
			put_on_top(h_a, h_a->p_min, 0);
		push(h_a, h_b);
		ft_putstr_fd("pb\n", STDOUT_FILENO);
		find_pos(h_a);
		if (h_a->p_max != 0)
			put_on_top(h_a, h_a->p_max, 1);
		push(h_a, h_b);
		ft_putstr_fd("pb\n", STDOUT_FILENO);
	}
}

static void	medium_sort_spe(t_pile *h_a, t_pile *h_b)
{
	if (h_a->first->n > h_b->first->n)
	{
		rotate(h_a);
		ft_putstr_fd("ra\n", STDOUT_FILENO);
		push(h_b, h_a);
		ft_putstr_fd("pa\n", STDOUT_FILENO);
	}
	else
	{
		push(h_b, h_a);
		ft_putstr_fd("pa\n", STDOUT_FILENO);
		rotate(h_a);
		ft_putstr_fd("ra\n", STDOUT_FILENO);
	}	
}

void	medium_sort(t_pile *h_a, t_pile *h_b)
{
	if (!h_a)
		return ;
	find_all(h_a);
	if (h_a->nbr == 4)
	{
		put_on_top(h_a, h_a->p_min, 0);
		push(h_a, h_b);
		ft_putstr_fd("pb\n", STDOUT_FILENO);
	}
	else
		push_extrem(h_a, h_b);
	small_sort(h_a);
	push(h_b, h_a);
	ft_putstr_fd("pa\n", STDOUT_FILENO);
	if (h_a->nbr == 5)
		medium_sort_spe(h_a, h_b);
}
