/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:46:03 by cmathot           #+#    #+#             */
/*   Updated: 2024/02/13 16:51:43 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sorting_algorithm(t_list **a, t_list **b)
{
	if (list_is_not_sorted(*a))
	{
		if (ft_lstsize(*a) <= 3)
			minisort(a);
		else
			bigsort(a, b);
	}
}

void	minisort(t_list **lst)
{
	t_list	*biggest;

	biggest = find_biggest_node(*lst);
	if (*lst == biggest)
		ra(lst);
	else if ((*lst)->next == biggest)
		rra(lst);
	if ((*lst)->nbr > (*lst)->next->nbr)
		sa(lst);
}

void	bigsort(t_list **a, t_list **b)
{
	t_list	*smallest;
	int		len_a;

	len_a = ft_lstsize(*a);
	while (len_a-- > 3)
	{
		pb(b, a);
	}
	minisort(a);
	while (*b)
	{
		initialize_nodes(*a, *b);
		rotate_lists(a, b);
		finish_rotation(a, b);
	}
	set_positions(*a, NULL);
	set_median(*a, NULL);
	smallest = find_smallest_node(*a);
	if (smallest->up_mid)
		while (*a != smallest)
			rra(a);
	else
		while (*a != smallest)
			ra(a);
}

void	rotate_lists(t_list **a, t_list **b)
{
	t_list	*cheapest;

	cheapest = find_cheapest(*b);
	while (*a != cheapest->target && *b != cheapest)
	{
		if (cheapest->up_mid == 0 && cheapest->target->up_mid == 0)
			rr(a, b);
		else if (cheapest->up_mid && cheapest->target->up_mid)
			rrr(a, b);
		else
		{
			if (cheapest->up_mid)
			{
				rrb(b);
				ra(a);
			}
			else
			{
				rb(b);
				rra(a);
			}
		}
		set_positions(*a, *b);
		set_median(*a, *b);
	}
}

void	finish_rotation(t_list **a, t_list **b)
{
	t_list	*cheapest;
	t_list	*target;

	cheapest = find_cheapest(*b);
	target = cheapest->target;
	while (*a != target)
	{
		if (target->up_mid)
			rra(a);
		else
			ra(a);
	}
	while (*b != cheapest)
	{
		if (cheapest->up_mid)
			rrb(b);
		else
			rb(b);
	}
	set_positions(*a, *b);
	set_median(*a, *b);
	pa(a, b);
}
