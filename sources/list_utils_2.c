/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:29:47 by cmathot           #+#    #+#             */
/*   Updated: 2024/02/21 13:56:33 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

int	list_is_not_sorted(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
	{
		if (lst->nbr > lst->next->nbr)
			return (1);
		lst = lst->next;
	}
	return (0);
}

size_t	ft_lstsize(t_list *lst)
{
	size_t	len;

	len = 0;
	if (lst)
	{
		while (lst)
		{
			lst = lst->next;
			len++;
		}
	}
	return (len);
}

t_list	*find_biggest_node(t_list *lst)
{
	int		biggest_value;
	t_list	*biggest_node;

	if (!lst)
		return (NULL);
	biggest_value = lst->nbr;
	biggest_node = lst;
	while (lst)
	{
		if (lst->nbr > biggest_value)
		{
			biggest_value = lst->nbr;
			biggest_node = lst;
		}
		lst = lst->next;
	}
	return (biggest_node);
}

t_list	*find_smallest_node(t_list *lst)
{
	int		smallest_value;
	t_list	*smallest_node;

	if (!lst)
		return (NULL);
	smallest_value = lst->nbr;
	smallest_node = lst;
	while (lst)
	{
		if (lst->nbr < smallest_value)
		{
			smallest_value = lst->nbr;
			smallest_node = lst;
		}
		lst = lst->next;
	}
	return (smallest_node);
}
