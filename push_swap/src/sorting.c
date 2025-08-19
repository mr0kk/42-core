/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 17:46:55 by rmrok             #+#    #+#             */
/*   Updated: 2025/08/20 00:23:54 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three(t_node **stack)
{
	int top;
	int mid;
	int bot;

	top = (*stack)->value;
	mid = (*stack)->next->value;
	bot = (*stack)->next->next->value;
	if (top < mid && mid > bot)
		if (top < bot)
		{
			sa(stack);
			ra(stack);
		}
		else
			rra(stack);
	else if (top > mid)
		if (mid > bot)
		{
			ra(stack);
			sa(stack);
		}
		else if (top < bot)
			sa(stack);
		else
			ra(stack);
}

int find_max(t_node *stack)
{
	int max;

	max = INT_MIN;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

int find_min(t_node *stack)
{
	int min;

	min = INT_MAX;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

t_node	*find_target(t_node *a, int data, int a_max, int a_min)
{
	t_node	*target;
	int	closest_bigger;

	target = NULL;
	if (data > a_max)
	{
		while (a->value != a_min)
			a = a->next;
		target = a;
	}
	else{
		closest_bigger = INT_MAX;
		while (a)
		{
		
			if (a->value > data && a->value < closest_bigger
				&& closest_bigger > data)
			{	
				closest_bigger = a->value;
				target = a;
			}
			a = a->next;
		}
	}
	return (target);
}

void	set_targets(t_node *a, t_node *b)
{
	int	data;
	int	a_max;
	int	a_min;

	a_max = find_max(a);
	a_min = find_min(a);
	while (b)
	{
		data = b->value;
		b->target = find_target(a, data, a_max, a_min);
		b = b->next;
	}
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

void print_stacks2(t_node *a, t_node *b)
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

void	count_cost(t_node *a, t_node *b, int a_len, int b_len)
{
	while (b)
	{
		if (b->target->index <= a_len / 2)
			b->cost = b->target->index - 1;
		else
			b->cost = a_len - b->target->index + 1;
		if (b->index <= b_len / 2)
			b->cost += b->index - 1 + 1;
		else
			b->cost += b_len - b->index + 1 + 1;
		b = b->next;
	}
}

int	cheapest_index(t_node *b)
{
	int	cheapest;
	int	index;
	
	cheapest = b->cost;
	index = 1;
	b = b->next;
	while (b)
	{
		if (b->cost < cheapest)
		{
			cheapest = b->cost;
			index = b->index;
		}
		b = b->next;
	}
	return (index);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);	
}

int max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}


void	push_cheapest(t_node **a, t_node **b, int c_index, int a_len, int b_len)
{
	int	i;

	i = 1;
	printf("c_index: %d\n", c_index);
	if ((*b)->target->index <= a_len / 2 && c_index <= b_len / 2)
	{
		printf("\n\nUNO\n\n");
		while (i < min((*b)->target->index, c_index))
		{
			printf("target index: %d\n", (*b)->target->index);
			rr(a, b);
			i++;
		}
		while (i < c_index)
		{
			i++;
			rb(b);
		}
		while (i < (*b)->target->index)
		{
			i++;
			ra(a);
		}
	}
	else if ((*b)->target->index > a_len / 2 && c_index > b_len / 2)
	{
		printf("\n\nDOS\n\n");
		while (i < min(a_len - (*b)->target->index + 1, b_len - c_index + 1))
		{
			rrr(a, b);
			i++;
		}
		while (i < b_len - c_index + 1)
		{
			i++;
			rrb(b);
		}
		while (i <= a_len - (*b)->target->index + 1)
		{
			i++;
			rra(a);
		}
	}
	else{
		printf("\n\nTRES\n\n");
		if ((*b)->target->index <= a_len / 2)
			while (i < (*b)->target->index)
			{
				i++;
				ra(a);
			}
		else
			while (i <= a_len - (*b)->target->index + 1)
			{
				i++;
				rra(a);
			}
		if (c_index <= b_len / 2)
			while (i < c_index)
			{
				i++;
				rb(b);
			}
		else
			while (i <= b_len - c_index + 1)
			{
				i++;
				rrb(b);
			}
	}
}

void turk_algorithm(t_node **a, t_node **b)
{
	int	cheap_index;
	int a_len;
	int b_len;

	printf("turk start\n\n");
	while (get_stack_size(*a) > 3)
		pb(a, b);
	sort_three(a);
	while (*b)
	{
		set_targets(*a, *b);
		set_indexes(*a);
		set_indexes(*b);
		a_len = get_stack_size(*a);
		b_len = get_stack_size(*b);
		count_cost(*a, *b, a_len, b_len);
		cheap_index = cheapest_index(*b);
		print_stacks2(*a, *b);
		push_cheapest(a, b, cheap_index, a_len, b_len);
		pa(a, b);
		print_stacks2(*a, *b);
	}
}
