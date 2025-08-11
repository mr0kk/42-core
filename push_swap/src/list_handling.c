#include "push_swap.h"

t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
	{
		printf("error in malloc\n");
		exit(1);
	}
	new_node->prev = NULL;
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
	new->prev = tmp;
}

void	print_stack(t_node	*head)
{
	while (head)
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