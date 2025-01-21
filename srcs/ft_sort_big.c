/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:41:41 by gsantill          #+#    #+#             */
/*   Updated: 2025/01/21 10:33:25 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_big(t_stack **stack_a, t_stack **stack_b)
{
	int cost;
	t_stack *temp_a;
	
	while (ft_stack_size(*stack_a) > 3 && !ft_stack_is_sorted(*stack_a))
	{
		temp_a = *stack_a;
		cost = ft_rot_min_cost_to_b(*stack_a, *stack_b);
		while (cost >= 0)
		{
			if (cost == ft_cost_rr_b(*stack_a, *stack_b, temp_a->nbr))
				ft_do_rarb(stack_a, stack_b, temp_a->nbr, "stack_a");
			else if (cost == ft_cost_rarrb_b(*stack_a, *stack_b, temp_a->nbr))
				ft_do_rarrb(stack_a, stack_b, temp_a->nbr, "stack_a");
			else if (cost == ft_cost_rrr_b(*stack_a, *stack_b, temp_a->nbr))
				ft_do_rrarrb(stack_a, stack_b, temp_a->nbr, "stack_a");
			else if (cost == ft_cost_rrarb_b(*stack_a, *stack_b, temp_a->nbr))
				ft_do_rrarb(stack_a, stack_b, temp_a->nbr, "stack_a");
			else
				temp_a = temp_a->next;
		}
	}
}
