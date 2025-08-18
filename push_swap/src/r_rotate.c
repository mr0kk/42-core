/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 13:51:13 by rmrok             #+#    #+#             */
/*   Updated: 2025/08/18 13:51:16 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotate(t_node **stack)
{
	t_node	*old_head;
	t_node	*new_head;

	if (!(*stack))
		return ;
	new_head = *stack;
	old_head = *stack;
	while (new_head->next)
		new_head = new_head->next;
	new_head->next = old_head;
	new_head->prev->next = NULL;
	new_head->prev = NULL;
	old_head->prev = new_head;
	*stack = new_head;	
}

void	r_ra(t_node **stack)
{
	r_rotate(stack);
	ft_putstr("rra\n");
}

void	r_rb(t_node **stack)
{
	r_rotate(stack);
	ft_putstr("rrb\n");
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	r_rotate(stack_a);
	r_rotate(stack_b);
	ft_putstr("rrr\n");
}