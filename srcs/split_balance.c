/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   split_balance.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/25 13:52:30 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/25 13:52:57 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

void	balance_stack_b_01(t_nstack *stack_a, t_nstack *stack_b, t_queue *op)
{
	if (stack_a->top->data > stack_a->top->next->data)
	{
		swap_double((t_stack*)stack_a, (t_stack*)stack_b);
		enqueue(op, ft_strdup("ss"));
	}
	else
	{
		swap((t_stack*)stack_b);
		enqueue(op, ft_strdup("sb"));
	}
}

void	balance_stack_b_02(t_nstack *stack_a, t_nstack *stack_b, t_queue *op)
{
	if (stack_a->top->data > stack_a->med
			&& check_split_path_ra(stack_a) < check_split_path_rra(stack_a))
	{
		rotate_double((t_stack*)stack_a, (t_stack*)stack_b);
		enqueue(op, ft_strdup("rr"));
	}
	else
	{
		rotate((t_stack*)stack_b);
		enqueue(op, ft_strdup("rb"));
	}
}

void	balance_stack_b(t_nstack *stack_a, t_nstack *stack_b, t_med *med,
		t_queue *op)
{
	t_stack_node	*snode_b;
	t_stack_node	*snext_b;
	t_stack_node	*snode_a;
	t_stack_node	*snext_a;

	snode_b = stack_b->top;
	snext_b = snode_b->next;
	snode_a = stack_a->top;
	snext_a = snode_a->next;
	if (stack_b->size < 2)
		return ;
	if (snode_b->data <= med->median && snext_b->data <= med->median
			&& snode_b->data < snext_b->data)
		balance_stack_b_01(stack_a, stack_b, op);
	if (snode_b->data <= med->median && snext_b->data > med->median)
		balance_stack_b_02(stack_a, stack_b, op);
}
