/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 23:48:08 by rmrok             #+#    #+#             */
/*   Updated: 2025/08/22 00:00:21 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	cheapest2top(t_node **a, t_node **b)
{
	int		a_len;
	int		b_len;
	t_node	*cheapest;
	t_rdata	rot;

	a_len = get_stack_size(*a);
	b_len = get_stack_size(*b);
	cheapest = find_cheapest(*a);
	rot.ra_counter = count_rotate(cheapest->index, a_len);
	rot.rb_counter = count_rotate(cheapest->target->index, b_len);
	rot.rra_counter = count_rrotate(cheapest->index, a_len);
	rot.rrb_counter = count_rrotate(cheapest->target->index, b_len);
	menage_rotation(&rot, a, b);
}

void	cheapest2top_b(t_node **a, t_node **b)
{
	int		a_len;
	int		b_len;
	t_node	*cheapest;
	t_rdata	rot;

	a_len = get_stack_size(*a);
	b_len = get_stack_size(*b);
	cheapest = find_cheapest(*b);
	rot.ra_counter = count_rotate(cheapest->target->index, a_len);
	rot.rb_counter = count_rotate(cheapest->index, b_len);
	rot.rra_counter = count_rrotate(cheapest->target->index, a_len);
	rot.rrb_counter = count_rrotate(cheapest->index, b_len);
	menage_rotation(&rot, a, b);
}
