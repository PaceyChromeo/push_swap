/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_large_sort_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 14:00:48 by pjacob            #+#    #+#             */
/*   Updated: 2021/06/02 14:08:32 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	search_digit(t_digit *dig, t_pile *head)
{
	int	i;

	i = 0;
	while (dig)
	{
		if (dig->n >= head->c_min && dig->n <= head->c_max)
		{
			if (i < head->c_pos)
				head->c_pos = i;
			if (head->nbr - i - 1 < head->c_pos)
				head->c_pos = i;
		}
		i++;
		dig = dig->next;
	}	
}

int	find_best_digit(t_pile *head)
{
	t_digit	*tmp;
	int		i;

	i = 0;
	tmp = head->first;
	if (head->nbr % 2)
		head->c_pos = head->nbr / 2;
	else
		head->c_pos = head->nbr / 2 + 0.5;
	search_digit(tmp, head);
	if ((head->nbr % 2 && head->c_pos != head->nbr / 2)
		|| (head->nbr % 2 == 0 && head->c_pos != head->nbr / 2 + 0.5))
		return (1);
	else
		return (0);
}
