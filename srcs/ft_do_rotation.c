/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_rotation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:45:20 by gsantill          #+#    #+#             */
/*   Updated: 2025/01/30 18:20:20 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_up(t_stack **a, t_stack **b, t_stack *cost)
{
	while ((*a)->index != cost->index || (*b)->index != cost->target)
	{
		if ((*a)->index != cost->index && (*b)->index != cost->target)
			ft_rr(a, b);
		else if ((*a)->index != cost->index)
			ft_ra(a);
		else if ((*b)->index != cost->target)
			ft_rb(b);
	}
}

void	ft_down(t_stack **a, t_stack **b, t_stack *cost)
{
	while ((*a)->index != cost->index || (*b)->index != cost->target)
	{
		if ((*a)->index != cost->index && (*b)->index != cost->target)
			ft_rrr(a, b);
		else if ((*a)->index != cost->index)
			ft_rra(a);
		else if ((*b)->index != cost->target)
			ft_rrb(b);
	}
}

void	ft_up_down(t_stack **a, t_stack **b, t_stack *cost)
{
	while ((*a)->index != cost->index || (*b)->index != cost->target)
	{
		if ((*a)->index != cost->index)
			ft_ra(a);
		if ((*b)->index != cost->target)
			ft_rrb(b);
	}
}

void	ft_down_up(t_stack **a, t_stack **b, t_stack *cost)
{
	while ((*a)->index != cost->index || (*b)->index != cost->target)
	{
		if ((*a)->index != cost->index)
			ft_rra(a);
		if ((*b)->index != cost->target)
			ft_rb(b);
	}
}
