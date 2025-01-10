/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:11:51 by gsantill          #+#    #+#             */
/*   Updated: 2025/01/10 15:43:53 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Sort a stack of 3 numbers only.
void	ft_sort_three(t_stack **head_a)
{
	if (ft_stack_is_sorted(*head_a) == 1)
		return ;
	if (ft_min_num(*head_a) == (*head_a)->number)
	{
		ft_rra(head_a);
		ft_sa(head_a);
	}
	else if (ft_max_num(*head_a) == (*head_a)->number)
	{
		ft_ra(head_a);
		if (!ft_stack_is_sorted(*head_a))
			ft_sa(head_a);
	}
	else
	{
		if (ft_find_index(*head_a, ft_max_num(*head_a)) == 1)
			ft_rra(head_a);
		else
			ft_sa(head_a);
	}
}

void	ft_sort_four(t_stack **head_a, t_stack **head_b)
{
	if (ft_min_num(*head_a) == (*head_a)->number)
		ft_pb(head_a, head_b);
	else if(ft_min_num(*head_a) == (*head_a)->next->number)
	{
		ft_sa(head_a);
		ft_pb(head_a, head_b);
	}
	else if (ft_min_num(*head_a) == (*head_a)->next->next->number)
	{
		ft_rra(head_a);
		ft_rra(head_a);
		ft_pb(head_a, head_b);
	}
	else
	{
		ft_rra(head_a);
		ft_pb(head_a, head_b);
	}
	ft_sort_three(head_a);
	ft_pa(head_a, head_a);
}
