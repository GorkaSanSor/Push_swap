/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_to_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:37:38 by gsantill          #+#    #+#             */
/*   Updated: 2025/01/14 12:32:33 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Save the numbers into the list
t_stack *ft_parse_to_stack(int word, char **split)
{
	t_stack	*stack_a;
	int		i;
	int		num;
	
	stack_a = NULL;
	i = 0;
	while (i < word)
	{
		num = ft_atoi(split[i]);
		if (i == 0)
			stack_a = ft_stack_new(num);
		else
			ft_stack_add_back(&stack_a, ft_stack_new(num));
		i++;
	}
	return (stack_a);
}
t_stack *ft_stack_new(int number)
{
	t_stack *new;
	
	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->number = number;
	new->index = 0;
	new->next = NULL;
	return (new);
}

void	ft_stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack *current;
	
	current = *stack;
	if(!*stack)
	{
		*stack = new;
		return ;
	}
	if (!new)
		return ;
	while (current->next != 0)
		current = current->next;
	current->next = new;
	return ;
}