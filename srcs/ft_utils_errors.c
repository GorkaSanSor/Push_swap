/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:20:10 by gsantill          #+#    #+#             */
/*   Updated: 2025/02/10 10:13:50 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Creates a temp_array by concatenating all arguments separated by spaces.
char	*ft_create_temp_array(char **argv)
{
	char	*temp;
	char	*joined;
	int		i;

	temp = ft_strdup(argv[1]);
	if (!temp)
		return (NULL);
	i = 2;
	while (argv[i])
	{
		joined = ft_strjoin_addspace(temp, argv[i]);
		if (!joined)
		{
			free(temp);
			return (NULL);
		}
		free(temp);
		temp = joined;
		i++;
	}
	return (temp);
}

// Checks for errors in input arguments and initializes the stack.
void	ft_check_errors(int argc, char **argv, t_utils *utils, t_stack **a)
{
	int	split_count;
	int	argv_error;

	split_count = 0;
	if (argc < 2)
		ft_error_exit(WRONG_ARGS, NULL, a);
	utils->temp_array = ft_create_temp_array(argv);
	if (!utils->temp_array)
		ft_error_exit(UNKNOWN_ERROR, NULL, a);
	utils->split = ft_split(utils->temp_array, ' ');
	if (!utils->split)
		ft_error_exit(UNKNOWN_ERROR, utils, a);
	while (utils->split[split_count])
		split_count++;
	argv_error = ft_check_argv(utils->temp_array, utils->split, split_count);
	if (argv_error == 1)
		ft_error_exit(INVALID_DIGIT, utils, a);
	if (argv_error == 2)
		ft_error_exit(DUPLICATES, utils, a);
	if (argv_error == 3)
		ft_error_exit(OVERFLOW, utils, a);
	*a = ft_parse_to_stack(split_count, utils->split);
	if (!*a)
		ft_error_exit(UNKNOWN_ERROR, utils, a);
}

// Handles errors, frees allocated memory, and exits the program.
void	ft_error_exit(int err_type, t_utils *utils, t_stack **stack)
{
	if (utils)
		ft_free_utils(utils);
	if (stack && *stack)
		ft_free_stack(stack);
	if (err_type == WRONG_ARGS)
		ft_printf("Error. Invalid number of arguments.\n");
	else if (err_type == INVALID_DIGIT)
		ft_printf("Error. One or more arguments are not valid numbers.\n");
	else if (err_type == DUPLICATES)
		ft_printf("Error. There are duplicate numbers.\n");
	else if (err_type == OVERFLOW)
		ft_printf("Error. A number is out of the valid range for an int.\n");
	else
		ft_printf("Error. An unknown error occurred.\n");
	exit(1);
}
