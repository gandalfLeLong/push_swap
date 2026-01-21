/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:45:17 by cmathot           #+#    #+#             */
/*   Updated: 2024/02/13 16:39:06 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

void	set_cheapest(t_list *b)
{
	t_list	*cheapest;

	cheapest = b;
	cheapest ->cheapest = 1;
	while (b)
	{
		if (b->cost < cheapest->cost)
		{
			cheapest ->cheapest = 0;
			cheapest = b;
			cheapest ->cheapest = 1;
		}
		b = b->next;
	}
}

t_list	*find_cheapest(t_list *b)
{
	while (b)
	{
		if (b->cheapest)
			return (b);
		b = b->next;
	}
	return (NULL);
}
