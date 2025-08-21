/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:48:47 by rmrok             #+#    #+#             */
/*   Updated: 2025/08/21 15:38:54 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_min_index(t_node *s)
{
	int min_index;
	int min_val;

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

int count_rotate(int index, int len)
{
	if (index <= (len / 2) + 1 && index != 1)
		return (index - 1);
	return (0);
}

int count_rrotate(int index, int len)
{
	if (index > (len / 2) + 1 && index != 1)
		return (len - index + 1);
	return (0);
}

void do_operation(int counter, t_node **s, void (*operation)(t_node **stack))
{
	while (counter != 0)
	{
		operation(s);
		counter--;
	}
}

void menage_rotation(t_rdata *data, t_node **a, t_node **b)
{
	while (data->ra_counter != 0 && data->rb_counter != 0)
	{
		rr(a, b);
		data->ra_counter--;
		data->rb_counter--;
	}
	do_operation(data->ra_counter, a, ra);
	do_operation(data->rb_counter, b, rb);
	while (data->rra_counter != 0 && data->rrb_counter != 0)
	{
		rrr(a, b);
		data->rra_counter--;
		data->rrb_counter--;
	}
	do_operation(data->rra_counter, a, rra);
	do_operation(data->rrb_counter, b, rrb);
}