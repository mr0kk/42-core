/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 00:01:28 by rmrok             #+#    #+#             */
/*   Updated: 2025/08/22 00:01:56 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_node *a, t_node *b)
{
	printf("\n\n");
	while (a || b)
	{
		if (a && b)
		{
			printf(" %d\t%d\n", a->value, b->value);
			a = a->next;
			b = b->next;
		}
		else if (a && !b)
		{
			printf(" %d\n", a->value);
			a = a->next;
		}
		else if (!a && b)
		{
			printf(" \t%d\n", b->value);
			b = b->next;
		}
	}
	printf("----------\n");
	printf(" a\tb\n");
}

void	print_stack(t_node *head)
{
	while (head)
	{
		ft_printf("%d\tnext: %p\tcurrent: %p\t prev: %p\n", head->value, head->next, head, head->prev);
		head = head->next;
	}
}

void	print_stacks2(t_node *a, t_node *b) // to delete later
{
	printf("\n\nprintt stacks 2:\n");
	while (a || b)
	{
		if (a && b)
		{
			printf("A: %d. %d\t target: %d\t cost: %d\tB: %d. %d\n", a->index, a->value, a->target->value, a->cost, b->index, b->value);
			a = a->next;
			b = b->next;
		}
		else if (a && !b)
		{
			printf("A: %d. %d\t target: %d\t cost: %d\n", a->index, a->value, a->target->value, a->cost);
			a = a->next;
		}
		else if (!a && b)
		{
			printf("\t\t\t\t\t\tB: %d. %d\n", b->index, b->value);
			b = b->next;
		}
	}
	printf("----------\n");
	printf(" a\tb\n\n");
}

void	print_stacks3(t_node *a, t_node *b) // to delete later
{
	printf("\n\nprintt stacks 3:\n");
	while (a || b)
	{
		if (a && b)
		{
			printf("A: %d. %d\t\t\tB: %d. %d\t target: %d\t cost: %d\n", a->index, a->value, b->index, b->value, b->target->value, b->cost);
			a = a->next;
			b = b->next;
		}
		else if (a && !b)
		{
			printf("A: %d. %d\n", a->index, a->value);
			a = a->next;
		}
		else if (!a && b)
		{
			printf("\t\t\t\t\t\t\tB: %d. %d\t target: %d\t cost: %d\n", b->index, b->value, b->target->value, b->cost);
			b = b->next;
		}
	}
	printf("----------\n");
	printf(" a\tb\n\n");
}