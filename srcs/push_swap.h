/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:41:22 by gsantill          #+#    #+#             */
/*   Updated: 2024/11/12 14:26:40 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* --------------------------C STANDARD LIBRARIES-----------------------------*/
// # include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"

/* --------------------------------PROTOTYPES---------------------------------*/

/*Estructura s_stack. Cada nodo tiene:

number: El valor del número almacenado en ese nodo.
index: El índice de la posición del número.
pos: La posición actual del número en la pila.
target_pos: La posición objetivo para este número después de la ordenación.
cost_a y cost_b: Costo asociado con mover un número de una pila a otra.*/

typedef struct s_stack
{
	int				number;       // Valor en el nodo.
	int				index;        // Índice o posición en la lista ordenada.
	int				pos;          // Posición actual en la pila.
	int				target_pos;   // Posición al mover los núm entre las pilas.
	int				cost_a;       // Costo para mover el número en stack_a.
	int				cost_b;       // Costo para mover el número en stack_b.
	struct s_stack	*next;        // Puntero al siguiente nodo en la pila.
}	t_stack;

typedef struct s_utils
{
	char **split;
	char *temp_array;
}	t_utils;

/*-----------------------------------LIBFT------------------------------------*/

int     ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_isspace(int c);
int		ft_check_digits(char *str);
char	**ft_split(char const *s, char c);
int		ft_split_count(char **split);
int		ft_duplicates(char **split, int word);
int		ft_maxint(char **split, int word);
int		ft_check_argv(char *temp_array, char **split, int word);
long	ft_long_atoi(const char *str);
void	ft_putstr(char *str);
char	*ft_strjoin_endspace(char *s1, char const *s2);
int		ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t destsize);

/*-----------------------------------MAIN FT----------------------------------*/

// int 	parse_to_stack(char *arg, t_stack **stack_a);
void 	print_stack(t_stack *stack, char stack_name);
char	*ft_create_temp_array(char **argv);
// int		ft_check_argv(char *temp_array, char **split, int word);
t_stack	*ft_save_numbers(int ac, char **av);
void	ft_assign_index(t_stack *head_a, int ac);
// void	ft_sort_three(t_stack **head);
// void	ft_sort_large(t_stack **head_a, t_stack **head_b);
// int		ft_min_index_pos(t_stack **head);
// void	ft_target_pos(t_stack **head_a, t_stack **head_b);
// void	ft_calc_cost(t_stack **head_a, t_stack **head_b);
// void	ft_exec_lowcost(t_stack **head_a, t_stack **head_b);
// void	ft_instruction(t_stack **a, t_stack **b, int cost_a, int cost_b);
void	ft_free_utils(t_utils *utils);
void	ft_exit_error(t_stack **head_a, t_stack **head_b);

/*---------------------------------LIST FT------------------------------------*/

t_stack	*new_stack(int number);
void	add_node_to_end(t_stack **stack, t_stack *new_node);
// t_stack	*initialize_stack_a(char **numbers);
// t_stack	*initialize_stack_b(char **numbers);
// void	ft_print_list(t_stack **head_a, t_stack **head_b);
// int		ft_lst_issorted(t_stack *head);
// t_stack	*new_stack(int ac, char **av);
// void	ft_lst_add_end(t_stack **head, t_stack *new);
// int		ft_list_size(t_stack *head);
void	ft_free_split(char **split);
void	ft_free_stack(t_stack **head);

/*--------------------------------INSTRUCTIONS--------------------------------*/

// void	ft_pa(t_stack **head_a, t_stack **head_b);
// void	ft_pb(t_stack **head_a, t_stack **head_b);
// void	ft_sa(t_stack **head_a);
// void	ft_sb(t_stack **head_b);
// void	ft_ra(t_stack **head_a);
// void	ft_rb(t_stack **head_b);
// void	ft_rr(t_stack **head_a, t_stack **head_b);
// void	ft_rrr(t_stack **head_a, t_stack **head_b);
// void	ft_rra(t_stack **head_a);
// void	ft_rrb(t_stack **head_b);


#endif