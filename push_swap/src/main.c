/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 00:05:37 by rmrok             #+#    #+#             */
/*   Updated: 2025/08/19 22:48:54 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_with_error(t_node **head_a, t_node **head_b)
{
	if (head_a && *head_a)
		free_stack(head_a);
	if (head_b && *head_b)
		free_stack(head_b);
	write(2, "Error\n", 6);
	exit(1);
}

void push_swap(t_node **head_a, t_node **head_b, int stack_size)
{
	if (stack_size == 2)
	{
		if ((*head_a)->value > (*head_a)->next->value)
			sa(head_a);
	}
	else if (stack_size == 3)
		sort_three(head_a);
	else
		turk_algorithm(head_a, head_b);
}

int main(int argc, char *argv[])
{

	t_node	*head_a;
	t_node	*head_b;
	int		stack_size;

	head_a = NULL;
	head_b = NULL;
	if (argc < 2)
		return (0);
	if (!valid_input(argc, argv))
		exit_with_error(NULL, NULL);
	if (argc == 2)
		head_a = read_input(argc, ft_split(argv[1], ' '));
	else
		head_a = read_input(argc, argv);
	stack_size = get_stack_size(head_a);

	// print_stacks(head_a, head_b); // delete later
	if (!is_sorted(head_a))
		push_swap(&head_a, &head_b, stack_size);

	print_stacks(head_a, head_b);

	free_stack(&head_a);
	free_stack(&head_b);
	exit(0);
}
