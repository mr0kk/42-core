/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 00:05:37 by rmrok             #+#    #+#             */
/*   Updated: 2025/07/26 00:05:38 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*node;
	t_node	*head;
	t_node	*head_b;

	int		i;

	if (argc < 2)
	{
		ft_printf("wrong amount of arguments\n");
		exit(1);
	}
	head = create_node(ft_atoi(argv[1]));
	i = 2;
	while (i < argc)
	{
		add_node(&head, ft_atoi(argv[i]));
		i++;
	}
	ft_printf("stack a:\n");
	print_stack(head);

	head_b = create_node(99);
	add_node(&head_b, 83);
	ft_printf("stack b:\n");
	print_stack(head_b);


	ft_printf("---------\n");
	head = pa(head, head_b);
	ft_printf("stack a:\n");

	print_stack(head);
	ft_printf("stack b:\n");
	print_stack(head_b);

	free_stack(head);
	free_stack(head_b);
}