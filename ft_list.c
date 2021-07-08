/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 13:31:50 by pjacob            #+#    #+#             */
/*   Updated: 2021/06/24 11:39:44 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_digit	*digit_init(int n)
{
	t_digit	*new;

	new = ft_calloc(sizeof(t_digit), 1);
	if (!new)
		return (0);
	new->n = n;
	new->next = NULL;
	return (new);
}

t_digit	*pile_last(t_pile *head)
{
	t_digit	*last;

	last = head->first;
	while (last->next)
		last = last->next;
	return (last);
}

void	add_back(t_pile *head, int n)
{
	t_digit	*new;
	t_digit	*last;

	last = pile_last(head);
	new = digit_init(n);
	last->next = new;
}

int	count_digit(t_pile *head)
{
	t_digit	*tmp;
	int		count;

	count = 0;
	tmp = head->first;
	if (!tmp)
		return (count);
	count = 1;
	while (tmp->next)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}
