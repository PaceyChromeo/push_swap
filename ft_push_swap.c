/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 14:43:27 by pjacob            #+#    #+#             */
/*   Updated: 2021/06/29 15:57:57 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	exit_error(t_pile *a, t_pile *b)
{
	ft_putendl_fd("Error", STDOUT_FILENO);
	free(a);
	free(b);
	exit (EXIT_FAILURE);
}

static int	check_if_sorted(t_pile *head)
{
	t_digit	*n1;
	t_digit	*n2;

	n1 = head->first;
	while (n1->next)
	{
		n2 = n1->next;
		if (n1->n > n2->n)
			return (0);
		n1 = n1->next;
	}
	return (1);
}

void	push_swap(t_pile *h_a, t_pile *h_b, int ac, char **av)
{
	if (ac == 2)
		init_arg(h_a, h_b, av);
	else
	{
		if (check_digit(av, 1))
			exit_error(h_a, h_b);
		init_piles(h_a, h_b, av, 1);
	}
	if (check_if_sorted(h_a))
	{
		clear_all(h_a, h_b);
		exit(EXIT_SUCCESS);
	}
	else
		dispatch_sort(h_a, h_b);
}

int	main(int ac, char **av)
{
	t_pile	*h_a;
	t_pile	*h_b;

	h_a = ft_calloc(sizeof(t_pile), 1);
	h_b = ft_calloc(sizeof(t_pile), 1);
	if (ac < 2)
		exit (EXIT_FAILURE);
	else
		push_swap(h_a, h_b, ac, av);
	clear_all(h_a, h_b);
	return (0);
}
