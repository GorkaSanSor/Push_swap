/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:39:33 by gsantill          #+#    #+#             */
/*   Updated: 2024/11/11 11:53:22 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

t_stack	*new_stack(int number)
{
	t_stack *node_a;
	
	node_a = (t_stack *)malloc(sizeof(t_stack));
	if (!node_a)
		return (NULL);
	node_a->number = number;
	node_a->index = -1;
	node_a->pos = -1;
	node_a->target_pos = -1;
	node_a->cost_a = 0;
	node_a->cost_b = 0;
	node_a->next = NULL;
	return (node_a);
}

void	add_node_to_end(t_stack **stack, t_stack *new_node)
{
	t_stack *temp;
	
	if (!*stack)
		*stack = new_node;
	else
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
	}
}
