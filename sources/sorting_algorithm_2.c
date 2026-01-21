/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:46:03 by cmathot           #+#    #+#             */
/*   Updated: 2024/02/13 16:42:31 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

void	initialize_nodes(t_list *a, t_list *b)
{
	set_positions(a, b);
	set_median(a, b);
	set_target(a, b);
	set_cost(a, b);
	set_cheapest(b);
}

void	set_positions(t_list *a, t_list *b)
{
	int	i;

	i = 0;
	while (a || b)
	{
		if (a)
		{
			a->pos = i;
			a = a->next;
		}
		if (b)
		{
			b->pos = i;
			b = b->next;
		}
		i++;
	}
}

void	set_median(t_list *a, t_list *b)
{
	size_t	size_a;
	size_t	size_b;

	size_a = ft_lstsize(a);
	size_b = ft_lstsize(b);
	while (a || b)
	{
		if (a)
		{
			if (a->pos <= size_a / 2)
				a->up_mid = 0;
			else
				a->up_mid = 1;
			a = a->next;
		}
		if (b)
		{
			if (b->pos <= size_b / 2)
				b->up_mid = 0;
			else
				b->up_mid = 1;
			b = b->next;
		}
	}
}

void	set_target(t_list *a, t_list *b)
{
	int		smallest_biggest;
	t_list	*tmp;

	while (b)
	{
		tmp = a;
		smallest_biggest = INT_MAX;
		b->target = NULL;
		while (tmp)
		{
			if (tmp->nbr > b->nbr && tmp->nbr < smallest_biggest)
			{
				smallest_biggest = tmp->nbr;
				b->target = tmp;
			}
			tmp = tmp->next;
		}
		if (b->target == NULL)
			b->target = find_smallest_node(a);
		b = b->next;
	}
}

void	set_cost(t_list *a, t_list *b)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(a);
	size_b = ft_lstsize(b);
	while (b)
	{
		b->cost = b->pos;
		if (b->up_mid)
			b->cost = size_b - (b->pos);
		if (!(b->target->up_mid))
			b->cost += b->target->pos;
		else
			b->cost += size_a - (b->target->pos);
		b = b->next;
	}
}
