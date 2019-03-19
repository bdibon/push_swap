/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   insertion_sort_02.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/17 19:18:20 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/25 13:03:32 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

static void		isort_down_op1(t_insert *in, t_stack *stack,
	t_stack_node *snode)
{
	if (stack == in->stack_a)
	{
		q_swap_maj(in->queue_a, snode);
		swap(in->stack_a);
		enqueue(in->op, ft_strdup("sa"));
		isort_down_a(in, snode->next);
	}
	else
	{
		q_swap_maj(in->queue_b, snode);
		swap(in->stack_b);
		enqueue(in->op, ft_strdup("sb"));
		isort_down_b(in, snode->next);
	}
}

static void		isort_down_op2(t_insert *in, t_stack *stack,
	t_stack_node *snode)
{
	if (stack == in->stack_a)
	{
		rotate(in->stack_a);
		enqueue(in->op, ft_strdup("ra"));
		isort_down_a(in, snode);
	}
	else
	{
		rotate(in->stack_b);
		enqueue(in->op, ft_strdup("rb"));
		isort_down_b(in, snode);
	}
}

static void		isort_down_op3(t_insert *in, t_stack *stack,
	t_stack_node *snode)
{
	if (stack == in->stack_a)
	{
		rotate_reverse(in->stack_a);
		enqueue(in->op, ft_strdup("rra"));
		isort_down_a(in, snode);
	}
	else
	{
		rotate_reverse(in->stack_b);
		enqueue(in->op, ft_strdup("rrb"));
		isort_down_b(in, snode);
	}
}

void			isort_down_a(t_insert *in, t_stack_node *snode)
{
	t_stack_node	*snext;

	snext = snode->next;
	if (snext->data == in->ndata)
	{
		isort_master_a(in, ((t_stack_node*)(in->queue_a->tail->value))->next);
		return ;
	}
	else if (snode == in->stack_a->top)
		isort_down_op1(in, in->stack_a, snode);
	else if (snode->key >= in->stack_a->size / 2)
		isort_down_op2(in, in->stack_a, snode);
	else
		isort_down_op3(in, in->stack_a, snode);
}

void			isort_down_b(t_insert *in, t_stack_node *snode)
{
	t_stack_node	*snext;

	snext = snode->next;
	if (snext->data == in->ndata)
	{
		isort_master_b(in, ((t_stack_node*)(in->queue_b->tail->value))->next);
		return ;
	}
	else if (snode == in->stack_b->top)
		isort_down_op1(in, in->stack_b, snode);
	else if (snode->key >= in->stack_b->size / 2)
		isort_down_op2(in, in->stack_b, snode);
	else
		isort_down_op3(in, in->stack_b, snode);
}
