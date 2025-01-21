/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:58:08 by gsantill          #+#    #+#             */
/*   Updated: 2025/01/20 14:18:08 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Finds the index of a specific nbr in the stack.
int	ft_find_index(t_stack *stack, int nbr)
{
	int	index;

	index = 0;
	while (stack->nbr != nbr)
	{
		index++;
		stack = stack->next;
	}
	return (index);
}

// Finds the correct index in stack_a for the nbr to_push.
int	ft_find_index_a(t_stack *stack_a, int to_push)
{
	int     index;
	t_stack *tmp_nbr;

	index = 1;
	// If to_push is between the first and last nbrs in stack_a.
	if (to_push > stack_a->nbr && to_push < ft_last_num(stack_a)->nbr)
		index = 0;
	// If to_push is outside the min and max of stack_a.
	else if (to_push > ft_max_num(stack_a) || to_push < ft_min_num(stack_a))
		index = ft_find_index(stack_a, ft_min_num(stack_a));
	else
	{
		// Traverse stack_a to find the appropriate index.
		tmp_nbr = stack_a->next;
		while (stack_a->nbr < to_push || tmp_nbr->nbr > to_push)
		{
			stack_a = stack_a->next;
			tmp_nbr = stack_a->next;
			index++;
		}
	}
	return (index);
}

// Finds the correct index in stack_b for the nbr to_push.
int ft_find_index_b(t_stack *stack_b, int to_push)
{
	int     index;
	t_stack *tmp_nbr;

	index = 1;
	if (to_push > stack_b->nbr && to_push < ft_last_num(stack_b)->nbr)
		index = 0;
	else if (to_push > ft_max_num(stack_b) || to_push < ft_min_num(stack_b))
		index = ft_find_index(stack_b, ft_min_num(stack_b));
	else
	{
		tmp_nbr = stack_b->next;
		while (stack_b->nbr < to_push || tmp_nbr->nbr > to_push)
		{
			stack_b = stack_b->next;
			tmp_nbr = stack_b->next;
			index++;
		}
	}
	return (index);
}