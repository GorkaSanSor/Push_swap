/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:34:10 by gsantill          #+#    #+#             */
/*   Updated: 2024/12/27 11:46:08 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Verifica si un string representa un número válido
int	ft_check_digits(char *str)
{
	int i;

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

// Verifica si hay duplicados en el array de strings `split`
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

// Verifica si los números están en los límites de int
int	ft_maxint(char **split, int word)
{
	int i = 0;
	long nbr;

	while (i < word)
	{
		nbr = ft_long_atoi(split[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

// Realiza las tres verificaciones en una función
int	ft_check_argv(char *temp_array, char **split, int word)
{

	// perform 3 checks: digits, duplicates, maxint or < minint.
	if (ft_check_digits(temp_array) != 0)
		return (1);
	if (ft_duplicates(split, word) != 0)
		return (2);
	if (ft_maxint(split, word) != 0)
		return (3);
	return (0);
}

// Cuenta la cantidad de palabras en `split`
int	ft_split_count(char **split)
{
	int count = 0;

	while (split[count] != NULL)
		count++;
	return (count);
}


