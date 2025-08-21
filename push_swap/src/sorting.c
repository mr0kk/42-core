/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:30:59 by rmrok             #+#    #+#             */
/*   Updated: 2025/08/21 23:50:28 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node **stack)
{
	int	biggest;

	if (!stack || !*stack || !(*stack)->next || !(*stack)->next->next)
		return ;
	biggest = max(max((*stack)->value, (*stack)->next->value),
			(*stack)->next->next->value);
	if ((*stack)->value == biggest)
		ra(stack);
	else if ((*stack)->next->value == biggest)
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}

void	set_targets(t_node *src, t_node *dest)
{
	int	data;
	int	dest_max;
	int	dest_min;

	if (!src || !dest)
		return ;
	dest_max = find_max(dest);
	dest_min = find_min(dest);
	while (src)
	{
		data = src->value;
		src->target = find_target(dest, data, dest_max, dest_min);
		src = src->next;
	}
}

void	count_cost(t_node *src, int src_len, int dest_len)
{
	while (src)
	{
		if (src->target->index <= dest_len / 2)
			src->cost = src->target->index - 1;
		else
			src->cost = dest_len - src->target->index + 1;
		if (src->index <= src_len / 2)
			src->cost += src->index - 1 + 1;
		else if (src_len == 1 && src->index == 1)
			src->cost += 1;
		else
			src->cost += src_len - src->index + 1 + 1;
		src = src->next;
	}
}

void	targeting(t_node **src, t_node **dest)
{
	int	src_len;
	int	dest_len;

	src_len = get_stack_size(*src);
	dest_len = get_stack_size(*dest);
	set_indexes(*src);
	set_indexes(*dest);
	set_targets(*src, *dest);
	count_cost(*src, src_len, dest_len);
}

void	turk_algorithm(t_node **a, t_node **b)
{
	pb(a, b);
	if (get_stack_size(*a) > 3)
		pb(a, b);
	while (get_stack_size(*a) > 3)
	{
		targeting(a, b);
		cheapest2top(a, b);
		pb(a, b);
	}
	sort_three(a);
	while (*b)
	{
		targeting(b, a);
		cheapest2top_b(a, b);
		pa(a, b);
	}
	set_indexes(*a);
	if (get_min_index(*a) <= get_stack_size(*a) / 2)
		while (!is_sorted(*a))
			ra(a);
	else
		while (!is_sorted(*a))
			rra(a);
}
