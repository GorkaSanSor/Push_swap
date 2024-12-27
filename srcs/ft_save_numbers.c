/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:37:38 by gsantill          #+#    #+#             */
/*   Updated: 2024/12/27 12:44:04 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Save the numbers into the list
t_stack *ft_save_numbers(int word, char **split)
{
	t_stack	*head_a;
	int		i;
	int		num;
	
	head_a = NULL;
	i = 0;
	while (i < word)
	{
		num = ft_atoi(split[i]);
		if (i == 0)
			head_a = ft_stack_new(num);
		else
			ft_stack_add_back(&head_a, ft_stack_new(num));
		i++;
	}
	return (head_a);
}
t_stack *ft_stack_new(int number)
{
	t_stack *new;
	
	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->number = number;
	new->index = 0;
	new->cost_a = -1;
	new->cost_b = -1;
	new->pos = -1;
	new->target_pos = -1;
	new->ptr_to_next = NULL;
	return (new);
}

void	ft_stack_add_back(t_stack **head, t_stack *new)
{
	t_stack *current;
	
	current = *head;
	if(!*head)
	{
		*head = new;
		return ;
	}
	if (!new)
		return ;
	while (current->ptr_to_next != 0)
		current = current->ptr_to_next;
	current->ptr_to_next = new;
	return ;
}