/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 17:46:55 by rmrok             #+#    #+#             */
/*   Updated: 2025/08/20 19:48:41 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three(t_node **stack)
{
	int top;
	int mid;
	int bot;

	if (!stack || !*stack || !(*stack)->next || !(*stack)->next->next)
        return;
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

	if (!a || !b)
		return ;
	a_max = find_max(a);
	a_min = find_min(a);
	while (b)
	{
		data = b->value;
		b->target = find_target(a, data, a_max, a_min);
		// if (!b->target)
		// 	exit_with_error(&a, &b);
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
		else if (b_len == 1 && b->index == 1)
			b->cost += 1;
		else
			b->cost += b_len - b->index + 1 + 1;
		b = b->next;
	}
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

t_node	*find_cheapest(t_node *stack)
{
	int		min_cost;
	t_node	*cheapest;

	min_cost = stack->cost;
	cheapest = stack;
	while (stack)
	{
		if (stack->cost < min_cost)
		{
			min_cost = stack->cost;
			cheapest = stack;
		}
		stack = stack->next;
	}
	return (cheapest);	
}

int	count_rotate(int index, int len)
{
	if (index <= len / 2 && index != 0)
		return (index - 1);
	return (0);
}

int count_rrotate(int index, int len)
{
	if (index > len / 2 && index != 1)
		return (len - index + 1);
	return (0);
}

typedef struct s_rdata
{
	int ra_counter;
	int rb_counter;
	int rra_counter;
	int rrb_counter;
} t_rdata;

void	menage_rotation(t_rdata *data, t_node **a, t_node **b)
{
	printf("ra: %d\trb: %d\trra: %d\trrb: %d\n\n", data->ra_counter, data->rb_counter, data->rra_counter, data->rrb_counter);
	while (data->ra_counter != 0 && data->rb_counter != 0)
	{
		rr(a, b);
		data->ra_counter--;
		data->rb_counter--;
	}
	while (data->ra_counter != 0)
	{
		ra(a);
		data->ra_counter--;
	}
	while (data->rb_counter != 0)
	{
		rb(b);
		data->rb_counter--;
	}
	while (data->rra_counter != 0 && data->rrb_counter != 0)
	{
		rrr(a, b);
		data->rra_counter--;
		data->rrb_counter--;
	}
	while (data->rra_counter != 0)
	{
		rra(a);
		data->rra_counter--;
	}
	while (data->rrb_counter != 0)
	{
		rrb(a);
		data->rrb_counter--;
	}
}

void	push_cheapest(t_node **a, t_node **b, int a_len, int b_len)
{
	t_node	*cheapest;
	t_rdata rot;

	cheapest = find_cheapest(*b);
	rot.ra_counter = count_rotate(cheapest->target->index, a_len);
	rot.rb_counter = count_rotate(cheapest->index, b_len);
	rot.rra_counter = count_rrotate(cheapest->target->index, a_len);
	rot.rrb_counter = count_rrotate(cheapest->index, b_len);
	printf("cheapest: %d\tc_index: %d\ttarget: %d\tt_index: %d\n", cheapest->value, cheapest->index, cheapest->target->value, cheapest->target->index);
	menage_rotation(&rot, a, b);
	rot.ra_counter = 0;
	rot.rb_counter = 0;
	rot.rra_counter = 0;
	rot.rrb_counter = 0;
	printf("here\n");
	pa(a, b); // here seg fould 
	printf("here2\n");
}

int	get_min_index(t_node *s)
{
	int	min_index;
	int	min_val;

	min_index = s->index;
	min_val = s->value;
	while (s)
	{
		if (s->value < min_val)
		{
			min_val = s->value;
			min_index - s->index;
		}
		s = s->next;
	}
	return (min_index);
}

void turk_algorithm(t_node **a, t_node **b)
{
	int	min_index;
	int a_len;
	int b_len;

	while (get_stack_size(*a) > 3)
		pb(a, b);
	sort_three(a);
	while (*b)
	{
		printf("|--------\nbefore everything\n B: %d\n\n", (*b)->value);
		a_len = get_stack_size(*a);
		b_len = get_stack_size(*b);
		set_indexes(*a);
		set_indexes(*b);
		set_targets(*a, *b);
		count_cost(*a, *b, a_len, b_len);
		printf("\nafter setting indexes, targets and costs:\n\n");
		print_stacks2(*a, *b);
		push_cheapest(a, b, a_len, b_len);
		printf("\n after push cheapeest:\n\n");
		print_stacks2(*a, *b);
		printf("\nend of loop\n-------|\n\n");
	}
	set_indexes(*a);
	a_len = get_stack_size(*a);
	min_index = get_min_index(*a);
	if (min_index <= a_len / 2)
	{
		while (!is_sorted(*a))
			ra(a);
	}
	else
	{
		while (!is_sorted(*a))
			rra(a);
	}
}
