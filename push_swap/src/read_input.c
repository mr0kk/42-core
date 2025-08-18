/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:38:54 by rmrok             #+#    #+#             */
/*   Updated: 2025/08/14 21:50:24 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_stack(t_node **head)
{
	t_node *tmp;

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

void print_stack(t_node *head)
{
	while (head)
	{
		ft_printf("%d\n", head->value);
		head = head->next;
	}
}

void add_node(t_node **head, int value)
{
	t_node *new;
	t_node *tmp;

	new = create_node(value);
	if (!(*head))
	{
		*head = new;
		return;
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

t_node *create_node(int value)
{
	t_node *new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		exit_with_error(NULL, NULL);
	new_node->prev = NULL;
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

t_node	*read_input(int argc, char *argv[])
{
	int		i;
	t_node	*head;

	if (argc == 2)
		i = 0;
	else
		i = 1;
	head = create_node(ft_atoi(argv[i]));
	i++;
	while (argv[i])
	{
		add_node(&head, ft_atoi(argv[i]));
		i++;
	}
	return (head);
}