/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 17:53:50 by rmrok             #+#    #+#             */
/*   Updated: 2025/08/20 17:19:46 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stacks(t_node *a, t_node *b) //delete later
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

void print_stack(t_node *head) //delete later
{
	while (head)
	{
		ft_printf("%d\tnext: %p\tcurrent: %p\t prev: %p\n", head->value, head->next, head, head->prev);
		head = head->next;
	}
}

int get_stack_size(t_node *stack)
{
	int res;

	res = 1;
	while (stack->next)
	{
		res++;
		stack = stack->next;
	}
	return (res);
}

int is_sorted(t_node *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	set_indexes(t_node *stack)
{
	int	i;

	i = 1;
	while (stack)
	{
		stack->index = i;
		stack = stack->next;
		i++;
	}
}

void free_stack(t_node **head)
{
	t_node *tmp;

	if (!(*head) || !head)
		return;
	while (*head)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
	*head = NULL;
}

void print_stacks2(t_node *a, t_node *b) // to delete later
{
	printf("\n\n");
	while (a || b)
	{
		if (a && b)
		{
			printf("%d: %d\t%d: %d\t target: %d\t cost: %d\n",a->index, a->value,b->index, b->value, b->target->value, b->cost);
			a = a->next;
			b = b->next;
		}
		else if (a && !b)
		{
			printf("%d: %d\n",a->index, a->value);
			a = a->next;
		}
		else if (!a && b)
		{
			printf(" \t%d: %d\t target: %d\t cost: %d\n", b->index, b->value, b->target->value, b->cost);
			b = b->next;
		}
	}
	printf("----------\n");
	printf(" a\tb\n\n");
}