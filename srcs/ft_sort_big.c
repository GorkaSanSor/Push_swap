/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:41:41 by gsantill          #+#    #+#             */
/*   Updated: 2025/01/24 13:38:09 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Finds the optimal cost to move elements from stack_a to stack_b 
// and sorts stack_a with >3 elements
void	ft_sort_more_than_3_in_b(t_stack **stack_a, t_stack **stack_b)
{
	int cost;
	t_stack *temp_a;
	
	while (ft_stack_size(*stack_a) > 0)
	{
		temp_a = *stack_a;
		cost = ft_rot_min_cost_to_b(*stack_a, *stack_b);
		
		// Checkeo:
		ft_printf("Coste min para pasar a b:\n");
		ft_printf("%d\n", cost);
		ft_printf("stack_a:\n");
		ft_print_stack(*stack_a);
		ft_printf("stack_b:\n");
		ft_print_stack(*stack_b);
		
		while (cost >= 0)
		{
			if (cost == ft_cost_rr_b(*stack_a, *stack_b, temp_a->nbr))
				ft_downdown(stack_a, stack_b, temp_a->nbr, "stack_a");
			else if (cost == ft_cost_rarrb_b(*stack_a, *stack_b, temp_a->nbr))
				ft_downup(stack_a, stack_b, temp_a->nbr, "stack_a");
			else if (cost == ft_cost_rrr_b(*stack_a, *stack_b, temp_a->nbr))
				ft_upup(stack_a, stack_b, temp_a->nbr, "stack_a");
			else if (cost == ft_cost_rrarb_b(*stack_a, *stack_b, temp_a->nbr))
				ft_updown(stack_a, stack_b, temp_a->nbr, "stack_a");
			temp_a = temp_a->next;
			cost = ft_rot_min_cost_to_b(temp_a, *stack_b);
			// Checkeo:
			ft_printf("Coste min para pasar a b:\n");
			ft_printf("%d\n", cost);
		}
	}
}

// Moves elements from stack_a to stack_b while sorting stack_a if needed
t_stack	*ft_sort_b(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (ft_stack_size(*stack_a) > 0 && !ft_stack_is_sorted(*stack_a))
	{
		ft_pb(stack_a, &stack_b);
		ft_pb(stack_a, &stack_b);
	}
	// Checkeo:
	ft_printf("stack_a:\n");
	ft_print_stack(*stack_a);
	ft_printf("stack_b:\n");
	ft_print_stack(stack_b);
	
	if (ft_stack_is_sorted(stack_b) == 0)
		ft_sb(&stack_b);
	// Checkeo:
	ft_printf("stack_a:\n");
	ft_print_stack(*stack_a);
	ft_printf("stack_b:\n");
	ft_print_stack(stack_b);
	
	if (ft_stack_size(*stack_a) > 0)
		ft_sort_more_than_3_in_b(stack_a, &stack_b);
	return (stack_b);
}

// Moves elements from stack_b back to stack_a in sorted order
t_stack	*ft_sort_a(t_stack **stack_a, t_stack **stack_b)
{
	int	cost;
	t_stack *temp_b;
	
	temp_b = *stack_b;
	cost = ft_rot_min_cost_to_a(*stack_a, *stack_b);
	while (*stack_b)
	{
		if (temp_b)
		{
			if (cost == ft_cost_rr_a(*stack_a, *stack_b, temp_b->nbr))
					ft_downdown(stack_a, stack_b, temp_b->nbr, "stack_b");
				else if (cost == ft_cost_rarrb_a(*stack_a, *stack_b, temp_b->nbr))
					ft_downup(stack_a, stack_b, temp_b->nbr, "stack_b");
				else if (cost == ft_cost_rrr_a(*stack_a, *stack_b, temp_b->nbr))
					ft_upup(stack_a, stack_b, temp_b->nbr, "stack_b");
				else if (cost == ft_cost_rrarb_a(*stack_a, *stack_b, temp_b->nbr))
					ft_updown(stack_a, stack_b, temp_b->nbr, "stack_b");
				temp_b = temp_b->next;
		}
		else
			break ;
		cost = ft_rot_min_cost_to_a(*stack_a, *stack_b);
	}
	return (*stack_a);
}

// Sorts stack_a completely, using stack_b as an auxiliary stack
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
	// Checkeo:
	ft_printf("stack_a:\n");
	ft_print_stack(*stack_a);
	ft_printf("stack_b:\n");
	ft_print_stack(stack_b);
}
