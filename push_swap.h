#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./Libft/libft.h"
# include <stdbool.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

//Error handeling functions
void			free_errors(t_stack_node **stack);
int	            error_syntax(char *str);
void            free_stack(t_stack_node **stack);
int      		error_duplicate(t_stack_node *a, int n);

//Stack creation functions
void	        init_a_stack(t_stack_node **a, char **arr);
t_stack_node	*find_last(t_stack_node *stack);
bool			stack_sorted(t_stack_node *stack);
int				stack_len(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);

//Swap
void	sa(t_stack_node	**a, bool print);
void	sb(t_stack_node **b, bool print);
void	ss(t_stack_node **a, t_stack_node **b, bool print);

//push
void	pa(t_stack_node **a, t_stack_node **b, bool print);
void	pb(t_stack_node **b, t_stack_node **a, bool print);

//rotate
void	ra(t_stack_node **a, bool print);
void	rb(t_stack_node **b, bool print);
void	rr(t_stack_node **a, t_stack_node **b, bool print);

//reverse rotate
void	rra(t_stack_node **a, bool print);
void	rrb(t_stack_node **b, bool print);
void	rrr(t_stack_node **a, t_stack_node **b, bool print);

//sort functions
void	sort_three(t_stack_node **a);
void	sort_stacks(t_stack_node **a, t_stack_node **b);
void	set_index_median(t_stack_node *stack);
void	set_cheapest(t_stack_node *stack);
t_stack_node	*get_cheapest(t_stack_node *stack);
void	prep_nodes_a(t_stack_node *a, t_stack_node *b);
void	prep_nodes_b(t_stack_node *a, t_stack_node *b);
void	prep_for_push(t_stack_node **stack, t_stack_node *top_node, char stack_name);

#endif