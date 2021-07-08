/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 14:21:54 by pjacob            #+#    #+#             */
/*   Updated: 2021/06/29 15:56:26 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "./libft/libft.h"
# include <limits.h>
# include <stdio.h>

typedef struct s_digit
{
	int				n;
	struct s_digit	*next;
}				t_digit;

typedef struct s_pile
{
	t_digit	*first;
	int		max;
	int		min;
	int		p_max;
	int		p_min;
	int		f_n;
	int		l_n;
	int		nbr;
	int		range;
	int		chunk;
	int		c_min;
	int		c_max;
	float	c_pos;
}				t_pile;

// Fonction principale
void	push_swap(t_pile *h_a, t_pile *h_b, int ac, char **av);

// LISTS

// Initie la pile avec les digits
t_digit	*digit_init(int n);
// Check si les digits sont bons
int		check_digit(char **av, int index);
// Check si la limite des int n'est pas depassee
int		check_limit(char **av, int index);
// Initie les piles
void	init_piles(t_pile *h_a, t_pile *h_b, char **av, int begin);
// Initie les piles si argument recu par une variable
void	init_arg(t_pile *a, t_pile *b, char **av);
// Dispatch selon le nombre d'arguments
void	dispatch_sort(t_pile *h_a, t_pile *h_b);
// Ajoute le digit a la fin de la pile
void	add_back(t_pile *head, int n);
// Free tous les digits et les piles
int		clear_all(t_pile *h_a, t_pile *h_b);
// Compte le nombre de digit dans une pile
int		count_digit(t_pile *head);
// Parcours les digits troncon par troncon
void	parse_chunk(t_pile *h_a, t_pile *h_b);
// Petit tri avant de remettre dans la pile A
void	sort_before_push_back(t_pile *h_a, t_pile *h_b);
// Petit dernier tri selon certaines exceptions
void	final_sort(t_pile *h_a, t_pile *h_b);
// Trouve le digit le plus pres du debut ou de la fin
int		find_best_digit(t_pile *head);
// Push le digit trouve par find_best_digit
void	push_digit(t_pile *a, t_pile *b);
// Met le min au dessus de la pile
void	push_min_on_top(t_pile *a);
// Exit en cas d'erreur
void	exit_error(t_pile *a, t_pile *b);

// ACTIONS

// Echange 2 premiers int
void	swap(t_pile *head);
// Mets la tete d'une pile dans l'autre
void	push(t_pile *h_a, t_pile *h_b);
// Place le premier element a la fin
void	rotate(t_pile *head);
// Place le dernier element au debut
void	reverse(t_pile *head);

// SORT

// Tri de 3 digits
int		small_sort(t_pile *h);
// Tri de 4 et 5 digits
void	medium_sort(t_pile *h_a, t_pile *h_b);
// Tri au-dela de 5 digits
void	large_sort(t_pile *h_a, t_pile *h_b);

// FIND

// Cherche le max et min de la pile
void	find_extrem(t_pile *head);
// Cherche la position de min et max et la valeur du premier et dernier digit.
void	find_pos(t_pile *head);
// Combine les 2 fonctions ci-dessus
void	find_all(t_pile *head);
// Cherche les details du premier troncon
void	first_chunk(t_pile *head);
// Cherche le prochain troncon
int		next_chunk(t_pile *head);
// Push un digit compris entre min et max
void	push_inter(t_pile *h_a, t_pile *h_b);

#endif
