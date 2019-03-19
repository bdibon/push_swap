/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   split_stack_03.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/25 14:00:24 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/25 14:01:43 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

size_t		check_split_path_ra_3(t_nstack *stack)
{
	t_stack_node	*snode;

	snode = stack->top;
	while (snode->data <= stack->med)
		snode = snode->next;
	return (stack->top->key - snode->key);
}

size_t		check_split_path_rra_3(t_nstack *stack)
{
	t_stack_node	*snode;

	snode = stack->bot;
	while (snode->data <= stack->med)
		snode = snode->next;
	return (snode->key + 1);
}

void		split_stack_3_a(t_split *split, t_med *med, t_nstack *stack)
{
	t_stack_node *snode;

	snode = stack->top;
	if (snode->data > stack->med && enqueue(split->op, ft_strdup("pb")))
	{
		push((t_stack*)stack, (t_stack*)split->stack_b);
		stack->nb_supmed--;
		balance_stack_b(stack, split->stack_b, med, split->op);
		split_stack_3(split, med, stack);
	}
	else if (snode->data <= stack->med)
	{
		if (check_split_path_ra_3(stack) < check_split_path_rra_3(stack))
		{
			rotate((t_stack*)stack);
			enqueue(split->op, ft_strdup("ra"));
			split_stack_3(split, med, stack);
		}
		else
		{
			rotate_reverse((t_stack*)stack);
			enqueue(split->op, ft_strdup("rra"));
			split_stack_3(split, med, stack);
		}
	}
}

void		split_stack_3(t_split *split, t_med *med, t_nstack *stack)
{
	if (stack->nb_infmed == 0 || stack->nb_supmed == 0)
		return ;
	if (stack == split->stack_a)
		split_stack_3_a(split, med, stack);
}
