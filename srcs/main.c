/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:39:12 by gsantill          #+#    #+#             */
/*   Updated: 2025/01/10 16:37:04 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

// Necesaria solo para testeo
static void	ft_print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_printf("Number: %d\n", stack->number);
		stack = stack->next;
	}
}

// Comprueba si la lista está ya ordenada
int	ft_stack_is_sorted(t_stack *head)
{
	while (head->next != NULL)
	{
		if (head->number > head->next->number)
			return (0);
		head = head->next;
	}
	return (1);
}

// Checkea la cantidad de numeros y llama al algoritmo correspondiente.
static void	ft_push_swap(t_stack **head_a, t_stack **head_b, int word_count)
{
	if (word_count < 2)
		return;
	else if (word_count == 2 && ft_stack_is_sorted(*head_a) == 0)
		ft_sa(head_a);
	else if (word_count == 3 && ft_stack_is_sorted(*head_a) == 0)
		ft_sort_three(head_a);
	else if (word_count == 4 && ft_stack_is_sorted(*head_a) == 0)
		ft_sort_four(head_a, head_b);
	else if (word_count == 5 && ft_stack_is_sorted(*head_a) == 0)
		ft_sort_five(head_a, head_b);
	else
		ft_printf("Trabajando para ordenar más de 5 numeros\n");
}

int main(int argc, char **argv)
{
	int		word_count;
	t_stack	*head_a;
	t_stack	*head_b;
	t_utils	utils;
	int argv_error;

	word_count = 0;
	head_a = NULL;
	head_b = NULL;
	if (argc < 2)
		ft_error_exit(WRONG_ARGS, NULL, &head_a);

	utils.temp_array = ft_create_temp_array(argv);
	if (!utils.temp_array)
		ft_error_exit(UNKNOWN_ERROR, NULL, &head_a);

	utils.split = ft_split(utils.temp_array, ' ');
	if (!utils.split)
		ft_error_exit(UNKNOWN_ERROR, &utils, &head_a);

	while (utils.split[word_count])
		word_count++;

	argv_error = ft_check_argv(utils.temp_array, utils.split, word_count);
	if (argv_error == 1)
		ft_error_exit(INVALID_DIGIT, &utils, &head_a);
	if (argv_error == 2)
		ft_error_exit(DUPLICATES, &utils, &head_a);
	if (argv_error == 3)
		ft_error_exit(OVERFLOW, &utils, &head_a);

	head_a = ft_parse_to_stack(word_count, utils.split);
	if (!head_a)
		ft_error_exit(UNKNOWN_ERROR, &utils, &head_a);
	ft_push_swap(&head_a, &head_b, word_count);

	ft_print_stack(head_a);
	ft_free_stack(&head_a);
	ft_free_stack(&head_b);
	ft_free_utils(&utils);
	return (0);
}
