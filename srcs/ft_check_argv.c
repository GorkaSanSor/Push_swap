/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:34:10 by gsantill          #+#    #+#             */
/*   Updated: 2025/01/31 15:56:53 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Checks if the string represents a valid number.
int	ft_check_digits(char *str)
{
	int	i;

	i = 0;
	if (ft_isalpha(str[i]))
		return (1);
	if (str[i] == '+' || str[i] == '-')
	{
		if (!ft_isdigit(str[i + 1]))
			return (1);
		i++;
	}
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
		{
			if (!(ft_isdigit(str[i + 1]) == 1 && ft_isspace(str[i - 1]) == 1))
				return (1);
		}
		if (ft_isdigit(str[i]) == 0 && ft_isspace(str[i]) == 0 \
		&& !(str[i] == '-' || str[i] == '+'))
			return (1);
		i++;
	}
	return (0);
}

// Checks for duplicates in the split string array.
int	ft_duplicates(char **split, int word)
{
	int		i;
	int		j;
	long	a;
	long	b;

	i = 0;
	while (i < word)
	{
		j = i + 1;
		while (j < word)
		{
			a = ft_long_atoi(split[i]);
			b = ft_long_atoi(split[j]);
			if (a == b)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

// Checks if the numbers in the split array are within the int limits.
int	ft_maxint(char **split, int word)
{
	int		i;
	long	nbr;

	i = 0;
	while (i < word)
	{
		nbr = ft_long_atoi(split[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

// Performs all three checks (digits, duplicates, max int) on the arguments.
int	ft_check_argv(char *temp_array, char **split, int word)
{
	if (ft_check_digits(temp_array) != 0)
		return (1);
	if (ft_duplicates(split, word) != 0)
		return (2);
	if (ft_maxint(split, word) != 0)
		return (3);
	return (0);
}

// Counts the number of words in the split string array.
void	ft_split_count(t_utils *utils)
{
	int	count;

	count = 0;
	while (utils->split[count] != NULL)
		count++;
	utils->split_count = count;
}
