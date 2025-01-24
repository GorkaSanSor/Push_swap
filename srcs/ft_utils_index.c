/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:58:08 by gsantill          #+#    #+#             */
/*   Updated: 2025/01/24 11:16:18 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "push_swap.h"

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
}*/

#include "push_swap.h"

// Encuentra el índice del número menor en el stack
static int	ft_find_min_index(t_stack *stack)
{
	int		index;
	int		min_index;
	int		min_value;
	t_stack	*current;

	current = stack;
	min_value = stack->nbr;
	min_index = 0;
	index = 0;
	while (current)
	{
		if (current->nbr < min_value)
		{
			min_value = current->nbr;
			min_index = index;
		}
		current = current->next;
		index++;
	}
	return (min_index);
}

// Encuentra el índice correcto para to_push en el stack
int	ft_find_index(t_stack *stack, int to_push)
{
	int		index;
	t_stack	*current;

	if (!stack)
		return (-1);
	// Caso 1: Número fuera de rango
	if (to_push > ft_max_num(stack) || to_push < ft_min_num(stack))
		return (ft_find_min_index(stack));
	// Caso 2: Buscar el intervalo correcto
	current = stack;
	index = 0;
	while (current->next)
	{
		if (current->nbr < to_push && current->next->nbr > to_push)
			break;
		current = current->next;
		index++;
	}
	return (index + 1);
}

// Encuentra el índice en stack_a
int	ft_find_index_a(t_stack *stack_a, int to_push)
{
	return (ft_find_index(stack_a, to_push));
}

// Encuentra el índice en stack_b
int	ft_find_index_b(t_stack *stack_b, int to_push)
{
	return (ft_find_index(stack_b, to_push));
}

