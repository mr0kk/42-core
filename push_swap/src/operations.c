#include "push_swap.h"


void	swap(t_node *head)
{
	int	tmp;

	tmp = head->value;
	head->value = head->next->value;
	head->next->value = tmp;
}

void	ss(t_node *head_a, t_node *head_b)
{
	swap(head_a);
	swap(head_b);
}

t_node	*pa(t_node *head_a, t_node *head_b)
{
	int	tmp;
	t_node *new;

	new = create_node(head_b->value);
	new->next = head_a;
	new->prev = NULL;
	head_a->prev = new;

	head_b->next = head_b;
	head_b-

	return (new);
}

