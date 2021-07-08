/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 11:49:31 by pjacob            #+#    #+#             */
/*   Updated: 2021/06/02 11:34:28 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	find_extrem(t_pile *head)
{
	t_digit	*num;

	num = head->first;
	head->max = num->n;
	head->min = num->n;
	while (num->next)
	{
		if (head->max < num->next->n)
			head->max = num->next->n;
		if (head->min > num->next->n)
			head->min = num->next->n;
		num = num->next;
	}
}

void	find_pos(t_pile *head)
{
	t_digit	*num;
	int		i;

	i = 0;
	num = head->first;
	head->f_n = num->n;
	while (num->next)
	{
		if (head->max == num->n)
			head->p_max = i;
		else if (head->min == num->n)
			head->p_min = i;
		num = num->next;
		i++;
	}
	if (head->max == num->n)
		head->p_max = i;
	else if (head->min == num->n)
		head->p_min = i;
	head->l_n = num->n;
}

void	first_chunk(t_pile *head)
{
	head->range = head->max - head->min;
	if (head->nbr > 5 && head->nbr < 100)
		head->chunk = head->range / 2;
	else if (head->nbr >= 100 && head->nbr < 500)
		head->chunk = head->range / 6;
	else
		head->chunk = head->range / 11;
	head->c_min = head->min;
	head->c_max = head->c_min + head->chunk - 1;
}

int	next_chunk(t_pile *head)
{
	head->c_min = head->c_max + 1;
	head->c_max = head->c_min + head->chunk - 1;
	if (head->c_max > head->max)
	{
		head->c_max = head->max;
		return (0);
	}
	return (1);
}

void	find_all(t_pile *head)
{
	if (!head->first)
	{
		head->nbr = 0;
		return ;
	}
	find_extrem(head);
	find_pos(head);
	head->nbr = count_digit(head);
}
