/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 16:51:28 by pjacob            #+#    #+#             */
/*   Updated: 2021/06/01 12:38:37 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	small_sort_2(t_pile *h)
{
	if (h->first->n < h->first->next->next->n)
	{
		swap(h);
		ft_putstr_fd("sa\n", STDOUT_FILENO);
		return (1);
	}
	else
	{
		rotate(h);
		ft_putstr_fd("ra\n", STDOUT_FILENO);
		if (h->first->n > h->first->next->n)
		{
			swap(h);
			ft_putstr_fd("sa\n", STDOUT_FILENO);
		}
		return (1);
	}	
}

static int	small_sort_1(t_pile *h)
{
	if (h->first->next->n < h->first->next->next->n)
		return (1);
	else
	{
		reverse(h);
		ft_putstr_fd("rra\n", STDOUT_FILENO);
		if (h->first->n > h->first->next->n)
		{
			swap(h);
			ft_putstr_fd("sa\n", STDOUT_FILENO);
		}
		return (1);
	}
}	

int	small_sort(t_pile *h)
{
	int		result;
	t_digit	*tmp;

	tmp = h->first;
	result = 0;
	if (tmp->n < tmp->next->n)
		result = small_sort_1(h);
	else if ((tmp->n < tmp->next->n)
		&& (tmp->next->n < tmp->next->next->n))
		return (result);
	else
		result = small_sort_2(h);
	return (result);
}
