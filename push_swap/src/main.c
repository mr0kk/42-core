/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 00:05:37 by rmrok             #+#    #+#             */
/*   Updated: 2025/08/14 21:44:30 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_with_error(t_node **head_a, t_node **head_b)
{
	// free stacks

	if (head_a && *head_a)
		free_stack(head_a);
	if (head_b && *head_b)
		free_stack(head_b);
	write(2, "Error\n", 6);
	exit(1);
}

void push_swap(t_node **head_a, t_node **head_b, int stack_size)
{
	
}

int main(int argc, char *argv[])
{

	t_node	*head_a;
	t_node	*head_b;
	int		i;

	if (argc < 2)
		return (0);
	if (!valid_input(argc, argv))
		exit_with_error(NULL, NULL);
	head_a = read_input(argc, argv);
	head_b = NULL;
	print_stack(head_a); // for tests

	// push_swap(head_a, head_b, argc - 1);
	
	free_stack(&head_a);
	free_stack(&head_b);
	exit(0);
}