/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:58:08 by gsantill          #+#    #+#             */
/*   Updated: 2025/01/22 11:43:21 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Finds the index of a specific nbr in the stack.
int	ft_find_index(t_stack *stack, int to_push)
{
	int	index;
	t_stack	*tmp_nbr;

	if (!stack)
		return (-1);
	index = 1;
	if (to_push > stack->nbr && to_push < ft_last_num(stack)->nbr)
		index = 0;
	else if (to_push > ft_max_num(stack) || to_push < ft_min_num(stack))
		index = ft_find_index(stack, ft_min_num(stack));
	else
	{
		tmp_nbr = stack->next;
		while (stack && tmp_nbr)
		{
			if (stack->nbr < to_push && tmp_nbr->nbr > to_push)
				break;
			stack = stack->next;
			tmp_nbr = stack ? stack->next : NULL;
			index++;
		}
	}
	return (index);
}

// Finds the correct index in stack_a for the nbr to_push.
int	ft_find_index_a(t_stack *stack_a, int to_push)
{
	return (ft_find_index(stack_a, to_push));
}

// Finds the correct index in stack_b for the nbr to_push.
int ft_find_index_b(t_stack *stack_b, int to_push)
{
	return (ft_find_index(stack_b, to_push));
}
