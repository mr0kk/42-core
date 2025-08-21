/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 17:53:50 by rmrok             #+#    #+#             */
/*   Updated: 2025/08/21 23:56:20 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack_size(t_node *stack)
{
	int	res;

	res = 1;
	while (stack->next)
	{
		res++;
		stack = stack->next;
	}
	return (res);
}

int	is_sorted(t_node *stack)
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

void	free_stack(t_node **head)
{
	t_node	*tmp;

	if (!(*head) || !head)
		return ;
	while (*head)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
	*head = NULL;
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
			min_index = s->index;
		}
		s = s->next;
	}
	return (min_index);
}
