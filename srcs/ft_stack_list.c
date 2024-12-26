/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:09:58 by gsantill          #+#    #+#             */
/*   Updated: 2024/12/26 15:13:41 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *ft_stack_new(int number)
{
	t_stack *new;
	
	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->number = number;
	new->index = 0;
	new->cost_a = -1;
	new->cost_b = -1;
	new->pos = -1;
	new->target_pos = -1;
	new->ptr_to_next = NULL;
	return (new);
}

void	ft_stack_add_back(t_stack **head, t_stack *new)
{
	t_stack *current;
	
	current = *head;
	if(!*head)
	{
		*head = new;
		return ;
	}
	if (!new)
		return ;
	while (current->ptr_to_next != 0)
		current = current->ptr_to_next;
	current->ptr_to_next = new;
	return ;
}
