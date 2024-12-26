/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:39:12 by gsantill          #+#    #+#             */
/*   Updated: 2024/12/26 15:16:10 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

static void	print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_printf("Number: %d\n", stack->number);
		stack = stack->ptr_to_next;
	}
}


int main(int argc, char **argv)
{
	int word;
	t_stack *head_a;
//	t_stack *head_b;
	t_utils utils;

	word = 0;
	if (argc < 2)
		return (0);
	utils.temp_array = ft_create_temp_array(argv);
	if (!utils.temp_array)
	{
		ft_printf("Error creating temp_array\n");
		ft_exit_error(NULL, NULL);
		return (1);
	}
	utils.split = ft_split(utils.temp_array, ' ');
	if (!utils.split)
	{
		ft_printf("Error splitting arguments\n");
		ft_free_utils(&utils);
		ft_exit_error(NULL, NULL);
		return (1);
	}
	while (utils.split[word])
		word++;
	if (ft_check_argv(utils.temp_array, utils.split, word) == 1)
	{
		ft_printf("Error in arguments\n");
		ft_free_utils(&utils);
		ft_exit_error(NULL, NULL);
		return (1);
	}
	head_a = ft_save_numbers(word, utils.split);
	print_stack(head_a);
//	head_b = NULL;
	ft_free_stack(&head_a);
	ft_free_utils(&utils);
	return (0);
}