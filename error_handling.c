#include "push_swap.h"

int	error_syntax(char *str)
{
	int	i;

	i = 0;
	if (!(str[i] == '+' || str[i] == '-' || ft_isdigit(str[i])))
		return (1);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!(ft_isdigit(str[i])))
			return (1);
		i++;
	}
	return (0);
}

int	error_duplicate(t_stack_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*head_node;

	if (!stack)
		return ;
	head_node = *stack;
	while (head_node)
	{
		tmp = head_node->next;
		free(head_node);
		head_node = tmp;
	}
	*stack = NULL;
}

void	free_errors(t_stack_node **stack)
{
	free_stack(stack);
	ft_printf("Error\n");
	exit(1);
}
