#include "push_swap.h"

void	set_index_median(t_stack_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

static void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*b_node;
	t_stack_node	*target_node;
	long			best_index;

	while (a)
	{
		best_index = LONG_MIN;
		b_node = b;
		while (b_node)
		{
			if (b_node->nbr < a->nbr && b_node->nbr > best_index)
			{
				best_index = b_node->nbr;
				target_node = b_node;
			}
			b_node = b_node->next;
		}
		if (best_index == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

static void	cost_calc_a(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->cost = a->index;
		if (!(a->above_median))
			a->cost = len_a - (a->index);
		if (a->target_node->above_median)
			a->cost += a->target_node->index;
		else
			a->cost += len_b - (a->target_node->index);
		a = a->next;
	}
}

void	set_cheapest(t_stack_node *stack)
{
	long			cheapest_value;
	t_stack_node	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->cost < cheapest_value)
		{
			cheapest_value = stack->cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	prep_nodes_a(t_stack_node *a, t_stack_node *b)
{
	set_index_median(a);
	set_index_median(b);
	set_target_a(a, b);
	cost_calc_a(a, b);
	set_cheapest(a);
}