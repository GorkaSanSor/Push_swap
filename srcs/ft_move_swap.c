/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:19:23 by gsantill          #+#    #+#             */
/*   Updated: 2025/01/10 13:12:56 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_stack **head)
{
	t_stack *current;
	t_stack *temp;

	current = *head;
	temp = current->next;
	if (*head == NULL || (*head)->next == NULL)
		return ;
	current = temp->next;
	(*head)->next = current;
	temp->next = *head;
	*head = temp;
}

// If there are 2 numbers, swap the first 2 elements at the top of the stack a.
void	ft_sa(t_stack **head_a)
{
	ft_swap(head_a);
	ft_printf("sa\n");
}

// If there are 2 numbers, swap the first 2 elements at the top of the stack b.
void	ft_sb(t_stack **head_b)
{
	ft_swap(head_b);
	ft_printf("sb\n");
}

// sa and sb at the same time.
void	ft_ss(t_stack **head_a, t_stack **head_b)
{
	ft_sa(head_a);
	ft_sb(head_b);
	ft_printf("ss\n");
}
