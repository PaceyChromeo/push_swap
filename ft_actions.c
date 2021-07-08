/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 13:59:20 by pjacob            #+#    #+#             */
/*   Updated: 2021/06/07 12:54:25 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	swap(t_pile *head)
{
	t_digit	*t1;
	t_digit	*t2;

	if (!head->first || !head->first->next)
		return ;
	t1 = head->first;
	t2 = head->first->next;
	t1->next = t2->next;
	t2->next = t1;
	head->first = t2;
}

void	push(t_pile *h_a, t_pile *h_b)
{
	t_digit	*tmp_a;
	t_digit	*tmp_b;

	if (!h_a->first)
		return ;
	tmp_a = h_a->first;
	if (!h_b->first)
	{
		tmp_b = h_a->first;
		h_a->first = tmp_a->next;
		h_b->first = tmp_b;
		h_b->first->next = NULL;
	}
	else
	{
		tmp_b = h_b->first;
		h_a->first = tmp_a->next;
		tmp_a->next = tmp_b;
		h_b->first = tmp_a;
	}
}

void	reverse(t_pile *head)
{
	t_digit	*tmp;
	t_digit	*first;

	if (!head->first || !head->first->next)
		return ;
	tmp = head->first;
	while (tmp->next->next)
		tmp = tmp->next;
	first = tmp->next;
	tmp->next = NULL;
	first->next = head->first;
	head->first = first;
}

void	rotate(t_pile *head)
{
	t_digit	*tmp;
	t_digit	*last;

	if (!head->first || !head->first->next)
		return ;
	last = head->first;
	tmp = last;
	head->first = head->first->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = last;
	last->next = NULL;
}

int	clear_all(t_pile *h_a, t_pile *h_b)
{
	t_digit	*clr;

	clr = NULL;
	while (h_a->first)
	{
		clr = h_a->first;
		h_a->first = h_a->first->next;
		clr->n = 0;
		clr->next = NULL;
		free(clr);
	}
	free(h_a);
	free(h_b);
	return (0);
}
