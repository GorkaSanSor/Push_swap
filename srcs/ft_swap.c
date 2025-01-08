/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:19:23 by gsantill          #+#    #+#             */
/*   Updated: 2025/01/08 12:23:27 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// If there are 2 numbers, swap the first 2 elements at the top of the stack a.
void	ft_sa(t_stack **head_a)
{
	t_stack *current;
	t_stack *temp;

	current = *head_a;
	temp = current->ptr_to_next;
	if (*head_a == NULL || (*head_a)->ptr_to_next == NULL)
		return ;
	current = temp->ptr_to_next;
	(*head_a)->ptr_to_next = current;
	temp->ptr_to_next = *head_a;
	*head_a = temp;
}

// If there are 2 numbers, swap the first 2 elements at the top of the stack b.
void	ft_sb(t_stack **head_b)
{
	t_stack *current;
	t_stack *temp;

	current = *head_b;
	temp = current->ptr_to_next;
	if (*head_b == NULL || (*head_b)->ptr_to_next == NULL)
		return ;
	current = temp->ptr_to_next;
	(*head_b)->ptr_to_next = current;
	temp->ptr_to_next = *head_b;
	*head_b = temp;
}

// sa and sb at the same time.
void	ft_ss(t_stack **head_a, t_stack **head_b)
{
	ft_sa(head_a);
	ft_sb(head_b);
}
