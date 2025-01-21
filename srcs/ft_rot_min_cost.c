/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot_min_cost.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:17:00 by gsantill          #+#    #+#             */
/*   Updated: 2025/01/21 10:25:17 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rot_min_cost_to_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *tmp_b;
	int cost;
	
	tmp_b = stack_b;
	cost = ft_cost_rr_a(stack_a, stack_b, stack_b->nbr);
	while (tmp_b->next != NULL)
	{
		if (cost > ft_cost_rrr_a(stack_a, stack_b, tmp_b->nbr))
			cost = ft_cost_rrr_a(stack_a, stack_b, tmp_b->nbr);
		if (cost > ft_cost_rrarb_a(stack_a, stack_b, tmp_b->nbr))
			cost = ft_cost_rrarb_a(stack_a, stack_b, tmp_b->nbr);
		if (cost > ft_cost_rarrb_a(stack_a, stack_b, tmp_b->nbr))
			cost = ft_cost_rarrb_a(stack_a, stack_b, tmp_b->nbr);
		tmp_b = tmp_b->next;
	}
	return (cost);
}

int	ft_rot_min_cost_to_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *tmp_a;
	int cost;
	
	tmp_a = stack_b;
	cost = ft_cost_rr_b(stack_a, stack_b, stack_b->nbr);
	while (tmp_a->next != NULL)
	{
		if (cost > ft_cost_rrr_b(stack_a, stack_b, tmp_a->nbr))
			cost = ft_cost_rrr_b(stack_a, stack_b, tmp_a->nbr);
		if (cost > ft_cost_rrarb_b(stack_a, stack_b, tmp_a->nbr))
			cost = ft_cost_rrarb_b(stack_a, stack_b, tmp_a->nbr);
		if (cost > ft_cost_rarrb_b(stack_a, stack_b, tmp_a->nbr))
			cost = ft_cost_rarrb_b(stack_a, stack_b, tmp_a->nbr);
		tmp_a = tmp_a->next;
	}
	return (cost);
}