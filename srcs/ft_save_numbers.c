/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:57:01 by gsantill          #+#    #+#             */
/*   Updated: 2024/11/12 14:21:20 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

// save the numbers into the stack
t_stack	*ft_save_numbers(int word, char **split)
{
	t_stack	*head_a;
	int		i;
	int		num;
	
	head_a = NULL;
	num = 0;
	i = 0;
	while(i < word)
	{
		num = ft_atoi(split[i]);

		if (i == 0)
			head_a = new_stack(num);
		else
			add_node_to_end(&head_a, new_stack(num));
		i++;
	}
	return (head_a);
}
// assign an index according to the order of the number
void	ft_assign_index(t_stack *head_a, int size)
{
	t_stack	*current;
	t_stack	*highest_node;
	long	temp;
	
	current = head_a;
	while (size > 0)
	{
		current = head_a;
		temp = -2147483648;
		while (current)
		{
			if (current->number > temp && !(current->index))
			{
				temp = current->number;
				highest_node = current;
			}
			current = current->next;
		}
		size--;
		highest_node->index = size;
	}
}