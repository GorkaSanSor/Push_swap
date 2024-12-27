/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:20:10 by gsantill          #+#    #+#             */
/*   Updated: 2024/12/27 12:42:47 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Crea un temp_array concatenando todos los argumentos separados por espacios
char *ft_create_temp_array(char **argv)
{
	char	*temp;
	char	*joined;
	int		i;

	temp = ft_strdup("");
	if (!temp)
		return (NULL);

	i = 1;
	while (argv[i])
	{
		joined = ft_strjoin_addspace(temp, argv[i]);
		free(temp);
		if (!joined)
			return (NULL);
		temp = joined;
		i++;
	}

	return (temp);
}
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
