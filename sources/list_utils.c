/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:44:40 by cmathot           #+#    #+#             */
/*   Updated: 2024/02/21 15:17:09 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	ft_no_duplicates(t_list **lst)
{
	t_list	*lst_cp;
	t_list	*tmp;

	lst_cp = *lst;
	while (lst_cp->next) 
	{
		tmp = lst_cp->next;
		while (tmp)
		{
			if (tmp->nbr == lst_cp->nbr)
			{
				write(2, "Error\n", 6);
				ft_lstclear(lst);
				exit (1);
			}
			tmp = tmp->next;
		}
		lst_cp = lst_cp->next;
	}
}

void	ft_lst_add_back(t_list **head, t_list *new_node)
{
	t_list	*last;

	if (!head || !new_node)
		return ;
	if (*head == NULL)
		*head = new_node;
	else
	{
		last = ft_lst_last(*head);
		last->next = new_node;
	}
}

void	ft_lstclear(t_list **head)
{
	t_list	*tmp;

	if (!head)
		return ;
	while (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
	*head = NULL;
}

t_list	*ft_lst_new(t_list *lst, char *buffer)
{
	t_list	*new;
	long	convert_number;

	if (!buffer)
		return (NULL);
	convert_number = ft_atoi(buffer);
	if (convert_number > 2147483647 || convert_number < -2147483648)
		return (NULL);
	new = malloc (sizeof(t_list));
	if (!new)
		return (NULL);
	if (!lst)
		new->prev = NULL;
	else 
		new->prev = ft_lst_last(lst);
	new->next = NULL;
	new->nbr = convert_number;
	return (new);
}

t_list	*ft_lst_last(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
