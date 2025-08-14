/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 00:05:37 by rmrok             #+#    #+#             */
/*   Updated: 2025/08/14 20:19:06 by rmrok            ###   ########.fr       */
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

int	main(int argc, char *argv[])
{

	t_node	*head_a;
	t_node	*head_b;
	int		i;

	if (argc < 2)
		return (0);
	if (!valid_input(argc, argv))
		exit_with_error(NULL, NULL);
	ft_printf("input git\n");

	head_a = read_input(argc, argv);
	head_b = NULL;

	print_stack(head_a);
	exit_with_error(&head_a, NULL);
	free_stack(&head_a);
	exit(0);
}