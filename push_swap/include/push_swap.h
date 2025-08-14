/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 00:05:48 by rmrok             #+#    #+#             */
/*   Updated: 2025/08/14 22:07:33 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_node
{
	struct s_node	*prev;
	int	value;
	int	index;
	struct s_node	*next;
}		t_node;

void	exit_with_error(t_node **head_a, t_node **head_b);
int		valid_input(int argc, char *argv[]);

t_node	*read_input(int argc, char *argv[]);

void	push_swap(t_node **head_a, t_node **head_b, int stack_size);

t_node	*create_node(int value);
void	add_node(t_node	**head, int value);
void	print_stack(t_node	*head);
void	free_stack(t_node **head);

/* operations */
void	swap(t_node *stack);
void	sa(t_node *stack_a);
void	sb(t_node *stack_b);
void	ss(t_node *stack_a, t_node *stack_b);

# endif
