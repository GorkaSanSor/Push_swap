/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:19:11 by gsantill          #+#    #+#             */
/*   Updated: 2025/01/14 12:28:26 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push(t_stack **src, t_stack **dst)
{
	t_stack *current;

	if (*src == NULL)
		return ;
	current = (*src)->next;
	(*src)->next = *dst;
	*dst = *src;
	*src = current;
}

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_b, stack_a);
	ft_printf("pa\n");
}
void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_a, stack_b);
	ft_printf("pb\n");
}