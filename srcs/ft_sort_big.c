/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:41:41 by gsantill          #+#    #+#             */
/*   Updated: 2025/01/21 14:11:03 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Sorts stack_a with more than 3 elements using stack_b for intermediate steps
void	ft_sort_more_than_3_in_b(t_stack **stack_a, t_stack **stack_b)
{
	int cost;
	t_stack *temp_a;
	
	while (ft_stack_size(*stack_a) > 3 && !ft_stack_is_sorted(*stack_a))
	{
		temp_a = *stack_a;
		cost = ft_rot_min_cost_to_b(*stack_a, *stack_b);
		while (cost >= 0 && temp_a)
		{
			if (cost == ft_cost_rr_b(*stack_a, *stack_b, temp_a->nbr))
				ft_do_rarb(stack_a, stack_b, temp_a->nbr, "stack_a");
			else if (cost == ft_cost_rarrb_b(*stack_a, *stack_b, temp_a->nbr))
				ft_do_rarrb(stack_a, stack_b, temp_a->nbr, "stack_a");
			else if (cost == ft_cost_rrr_b(*stack_a, *stack_b, temp_a->nbr))
				ft_do_rrarrb(stack_a, stack_b, temp_a->nbr, "stack_a");
			else if (cost == ft_cost_rrarb_b(*stack_a, *stack_b, temp_a->nbr))
				ft_do_rrarb(stack_a, stack_b, temp_a->nbr, "stack_a");
			temp_a = temp_a->next;
			cost = ft_rot_min_cost_to_b(*stack_a, *stack_b);
		}
	}
}

t_stack	*ft_sort_b(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	while (ft_stack_size(*stack_a) > 3 && !ft_stack_is_sorted(*stack_a))
		ft_sort_more_than_3_in_b(stack_a, &stack_b);
	if (!ft_stack_is_sorted(*stack_a))
		ft_sort_three(stack_a);
	return (stack_b);
	
}

t_stack	*ft_sort_a(t_stack **stack_a, t_stack **stack_b)
{
	int	cost;
	t_stack *temp_b;
	
	temp_b = *stack_b;
	cost = ft_rot_min_cost_to_a(*stack_a, *stack_b);
	while (*stack_b)
	{
		if (cost == ft_cost_rr_a(*stack_a, *stack_b, temp_b->nbr))
				ft_do_rarb(stack_a, stack_b, temp_b->nbr, "stack_b");
			else if (cost == ft_cost_rarrb_a(*stack_a, *stack_b, temp_b->nbr))
				ft_do_rarrb(stack_a, stack_b, temp_b->nbr, "stack_b");
			else if (cost == ft_cost_rrr_a(*stack_a, *stack_b, temp_b->nbr))
				ft_do_rrarrb(stack_a, stack_b, temp_b->nbr, "stack_b");
			else if (cost == ft_cost_rrarb_a(*stack_a, *stack_b, temp_b->nbr))
				ft_do_rrarb(stack_a, stack_b, temp_b->nbr, "stack_b");
			temp_b = temp_b->next;
			cost = ft_rot_min_cost_to_a(*stack_a, *stack_b);
	}
	return (*stack_a);
	
}

void	ft_sort(t_stack **stack_a)
{
	t_stack *stack_b;
	int		index;
	
	stack_b = NULL;
	if ((ft_stack_size(*stack_a) == 2) && (ft_stack_is_sorted(*stack_a) == 0))
		ft_sa(stack_a);
	else
	{
		stack_b = ft_sort_b(stack_a);
		ft_sort_a(stack_a, &stack_b);
		index = ft_find_index_a(*stack_a, ft_min_num(*stack_a));
		if (index < (ft_stack_size(*stack_a) - index))
		{
			while ((*stack_a)->nbr != ft_min_num(*stack_a))
				ft_ra(stack_a);
		}
		else
		{
			while ((*stack_a)->nbr != ft_min_num(*stack_a))
				ft_rra(stack_a);
		}
	}
}
