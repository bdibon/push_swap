/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   split_stack_01.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/25 14:00:09 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/25 14:02:27 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

void		split_stack_1_a(t_split *split, t_med *med, t_nstack *stack)
{
	t_stack_node *snode;

	snode = stack->top;
	if (snode->data <= stack->med && enqueue(split->op, ft_strdup("pb")))
	{
		push((t_stack*)stack, (t_stack*)split->stack_b);
		stack->nb_infmed--;
		balance_stack_b(stack, split->stack_b, med, split->op);
		split_stack_1(split, med, stack);
	}
	else if (snode->data > stack->med)
	{
		if (check_split_path_ra(stack) < check_split_path_rra(stack))
		{
			rotate((t_stack*)stack);
			enqueue(split->op, ft_strdup("ra"));
			split_stack_1(split, med, stack);
		}
		else
		{
			rotate_reverse((t_stack*)stack);
			enqueue(split->op, ft_strdup("rra"));
			split_stack_1(split, med, stack);
		}
	}
}

void		split_stack_1_b(t_split *split, t_med *med, t_nstack *stack)
{
	t_stack_node *snode;

	snode = stack->top;
	if (snode->data > stack->med)
	{
		push((t_stack*)stack, (t_stack*)split->stack_a);
		stack->nb_supmed--;
		enqueue(split->op, ft_strdup("pa"));
		split_stack_1(split, med, stack);
	}
	else if (snode->data <= stack->med)
	{
		if (check_split_path_rb(stack) < check_split_path_rrb(stack))
		{
			rotate((t_stack*)stack);
			enqueue(split->op, ft_strdup("rb"));
			split_stack_1(split, med, stack);
		}
		else
		{
			rotate_reverse((t_stack*)stack);
			enqueue(split->op, ft_strdup("rrb"));
			split_stack_1(split, med, stack);
		}
	}
}

void		split_stack_1(t_split *split, t_med *med, t_nstack *stack)
{
	if (stack->nb_supmed == 0 || stack->nb_infmed == 0)
		return ;
	if (stack == split->stack_a)
		split_stack_1_a(split, med, stack);
	else
		split_stack_1_b(split, med, stack);
}
