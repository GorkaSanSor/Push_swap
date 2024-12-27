#include "push_swap.h"

void	ft_error_exit(int err_type, t_utils *utils, t_stack **stack)
{
	if (utils)
		ft_free_utils(utils);
	if (stack && *stack)
		ft_free_stack(stack);
	if (err_type == WRONG_ARGS)
		ft_printf("Error\nInvalid number of arguments.\n");
	else if (err_type == INVALID_DIGIT)
		ft_printf("Error\nOne or more arguments are not valid numbers.\n");
	else if (err_type == DUPLICATES)
		ft_printf("Error\nThere are duplicate numbers.\n");
	else if (err_type == OVERFLOW)
		ft_printf("Error\nA number is out of the valid range for an int.\n");
	else
		ft_printf("Error\nAn unknown error occurred.\n");
	exit(1);
}


