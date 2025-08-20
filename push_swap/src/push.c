/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 22:14:54 by rmrok             #+#    #+#             */
/*   Updated: 2025/08/20 18:01:26 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **src, t_node **dest)
{
	t_node	*new_dest_head;

	if (!(*src))
		return ;
	new_dest_head = *src;
	if (get_stack_size(*src) > 1)
		*src = (*src)->next;
	else
		*src = NULL;
	new_dest_head->next = *dest;
	if (*dest)
		(*dest)->prev = new_dest_head;
	*dest = new_dest_head;
	(*dest)->prev = NULL;
}

void	pa(t_node **stack_a, t_node	**stack_b)
{
	push(stack_b, stack_a);
	ft_putstr("pa\n");
}

void	pb(t_node **stack_a, t_node	**stack_b)
{
	push(stack_a, stack_b);
	ft_putstr("pb\n");
}