/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 00:05:37 by rmrok             #+#    #+#             */
/*   Updated: 2025/07/26 00:05:38 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

typedef struct s_node
{
	int	value;
	struct s_node	*next;
}		t_node;

t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
	{
		printf("error in malloc\n");
		exit(1);
	}
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);

}

void	add_node(t_node	**head, int value)
{
	t_node	*new;
	t_node	*tmp;

	new = create_node(value);
	if(!(*head))
	{
		*head = new;
		return ;
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;

}

void	print_stack(t_node	*head)
{
	while (head->next)
	{
		ft_printf("%d\n", head->value);
		head = head->next; 
	}
}

void	free_stack(t_node *head)
{
	t_node	*tmp;

	while(head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

int main(int argc, char *argv[])
{
	t_node	*node;
	t_node	*head;
	int		i;

	if (argc < 2)
	{
		ft_printf("wrong amount of arguments\n");
		exit(1);
	}
	head = create_node(ft_atoi(argv[1]));
		i = 2;
	while (argv[i])
	{
		add_node(&head, ft_atoi(argv[i]));
		i++;
	}

	print_stack(head);
	free_stack(head);
}