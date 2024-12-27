/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:39:12 by gsantill          #+#    #+#             */
/*   Updated: 2024/12/27 12:03:18 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

static void	ft_print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_printf("Number: %d\n", stack->number);
		stack = stack->ptr_to_next;
	}
}

int main(int argc, char **argv)
{
	int		word;
	t_stack	*head_a;
//	t_stack	*head_b;
	t_utils	utils;
	int check_result;

	word = 0;
	head_a = NULL;
//	head_b = NULL;
	if (argc < 2)
		ft_error_exit(WRONG_ARGS, NULL, &head_a);

	utils.temp_array = ft_create_temp_array(argv);
	if (!utils.temp_array)
		ft_error_exit(UNKNOWN_ERROR, NULL, &head_a);

	utils.split = ft_split(utils.temp_array, ' ');
	if (!utils.split)
		ft_error_exit(UNKNOWN_ERROR, &utils, &head_a);

	while (utils.split[word])
		word++;

	check_result = ft_check_argv(utils.temp_array, utils.split, word);
	if (check_result == 1)
		ft_error_exit(INVALID_DIGIT, &utils, &head_a);
	if (check_result == 2)
		ft_error_exit(DUPLICATES, &utils, &head_a);
	if (check_result == 3)
		ft_error_exit(OVERFLOW, &utils, &head_a);

	head_a = ft_save_numbers(word, utils.split);
	if (!head_a)
		ft_error_exit(UNKNOWN_ERROR, &utils, &head_a);

	ft_print_stack(head_a);
	ft_free_stack(&head_a);
	ft_free_utils(&utils);
	return (0);
}
