/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:41:22 by gsantill          #+#    #+#             */
/*   Updated: 2025/01/30 18:17:45 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* --------------------------C STANDARD LIBRARIES-----------------------------*/
// # include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"

/* ----------------------------------ERRORS-----------------------------------*/

# define WRONG_ARGS 1
# define INVALID_DIGIT 2
# define DUPLICATES 3
# define OVERFLOW 4
# define UNKNOWN_ERROR 5

/* --------------------------------PROTOTYPES---------------------------------*/

/*Estructura s_stack. Cada nodo tiene:

nbr: El valor del número almacenado en ese nodo.
index: El índice de la posición del número.
*prev: Puntero al siguiente nodo en el stack.
*next: Puntero al siguiente nodo en el stack.
cost: Menor costo para pasar a b.
target: Index objetivo en b*/

typedef struct s_stack
{
	long			nbr;
	long			index;
	int				cost;
	int				target;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct s_utils
{
	char	**split;
	char	*temp_array;
}	t_utils;

/*-----------------------------------MAIN FT----------------------------------*/

char	*ft_create_temp_array(char **argv);
int		ft_check_argv(char *temp_array, char **split, int word);
t_stack	*ft_parse_to_stack(int word, char **split);
void	ft_sort_three(t_stack **a);
void	ft_sort_four(t_stack **a, t_stack **b);

/*---------------------------------MAIN SUB_FT--------------------------------*/

int		ft_check_digits(char *str);
int		ft_duplicates(char **split, int word);
int		ft_maxint(char **split, int word);
int		ft_split_count(char **split);

/*------------------------------------UTILS-----------------------------------*/

void	ft_print_stack(t_stack *stack);
t_stack	*ft_stack_new(int nbr);
void	ft_stack_add_back(t_stack **stack, t_stack *new);
void	ft_free_split(char **split);
void	ft_free_utils(t_utils *utils);
void	ft_free_stack(t_stack **stack);
void	ft_free_all(t_stack **a, t_stack **b, t_utils *utils);
void	ft_check_errors(int argc, char **argv, t_utils *utils, t_stack **a);
void	ft_error_exit(int err_type, t_utils *utils, t_stack **stack);
int		ft_stack_is_sorted(t_stack *stack);
t_stack	*ft_min_num(t_stack *stack);
t_stack	*ft_max_num(t_stack *stack);
void	ft_max_to_top(t_stack **b);
void	ft_set_index(t_stack *stack);
int		ft_stack_size(t_stack *stack);
t_stack	*ft_last_num(t_stack *stack);
void	ft_set_cost(t_stack *a, int size_a, int size_b);
void	ft_set_target(t_stack *a, t_stack *b);
t_stack	*ft_find_min_cost(t_stack *stack);
void	ft_cheap_to_top(t_stack **a, t_stack **b);
void	ft_up(t_stack **a, t_stack **b, t_stack *cost);
void	ft_down(t_stack **a, t_stack **b, t_stack *cost);
void	ft_up_down(t_stack **a, t_stack **b, t_stack *cost);
void	ft_down_up(t_stack **a, t_stack **b, t_stack *cost);
void	ft_sort_big(t_stack **a, t_stack **b);

/*--------------------------------INSTRUCTIONS--------------------------------*/

// swap the first 2 elements at the top of stack a
void	ft_sa(t_stack **a);
// swap the first 2 elements at the top of stack b
void	ft_sb(t_stack **b);
// sa and sb at the same time
void	ft_ss(t_stack **a, t_stack **b);
// take the first element at the top of b and put it at the top of a
void	ft_pa(t_stack **a, t_stack **b);
// take the first element at the top of a and put it at the top of b
void	ft_pb(t_stack **a, t_stack **b);
// The first element of a becomes the last one
void	ft_ra(t_stack **a);
// The first element of b becomes the last one
void	ft_rb(t_stack **b);
// ra and rb at the same time
void	ft_rr(t_stack **a, t_stack **b);
// The last element of a becomes the first one
void	ft_rra(t_stack **a);
// The last element of b becomes the first one
void	ft_rrb(t_stack **b);
// rra and rrb at the same time
void	ft_rrr(t_stack **a, t_stack **b);

#endif