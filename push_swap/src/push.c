/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 22:14:54 by rmrok             #+#    #+#             */
/*   Updated: 2025/08/14 22:17:02 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	push(t_node **src, t_node **dest)
{
	t_node	*tmp;

	if (!(*src))
		return ;

	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
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