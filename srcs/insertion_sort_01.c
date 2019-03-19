/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   insertion_sort.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/15 12:37:52 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/25 12:58:22 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

static void		isort_up_op1(t_insert *in, t_stack *stack, t_queue_node *qnode)
{
	if (stack == in->stack_a)
	{
		swap(in->stack_a);
		enqueue(in->op, ft_strdup("sa"));
		isort_up_a(in, qnode->prev);
	}
	else
	{
		swap(in->stack_b);
		enqueue(in->op, ft_strdup("sb"));
		isort_up_b(in, qnode->prev);
	}
}

static void		isort_up_op2(t_insert *in, t_stack *stack, t_queue_node *qnode)
{
	if (stack == in->stack_a)
	{
		rotate(in->stack_a);
		enqueue(in->op, strdup("ra"));
		isort_up_a(in, qnode);
	}
	else
	{
		rotate(in->stack_b);
		enqueue(in->op, strdup("rb"));
		isort_up_b(in, qnode);
	}
}

static void		isort_up_op3(t_insert *in, t_stack *stack, t_queue_node *qnode)
{
	if (stack == in->stack_a)
	{
		rotate_reverse(in->stack_a);
		enqueue(in->op, strdup("rra"));
		isort_up_a(in, qnode);
	}
	else
	{
		rotate_reverse(in->stack_b);
		enqueue(in->op, strdup("rrb"));
		isort_up_b(in, qnode);
	}
}

void			isort_up_a(t_insert *in, t_queue_node *qnode)
{
	t_queue_node	*qprev;

	qprev = qnode->prev;
	if (in->queue_a->size < 2)
		return ;
	if (qprev == NULL || ((t_stack_node*)(qprev->value))->data <=
			((t_stack_node*)(qnode->value))->data)
		isort_master_a(in, ((t_stack_node*)(in->queue_a->tail->value))->next);
	else if ((t_stack_node*)(qprev->value) == in->stack_a->top)
		isort_up_op1(in, in->stack_a, qnode);
	else if (((t_stack_node*)(qprev->value))->key >= in->stack_a->size / 2)
		isort_up_op2(in, in->stack_a, qnode);
	else
		isort_up_op3(in, in->stack_a, qnode);
}

void			isort_up_b(t_insert *in, t_queue_node *qnode)
{
	t_queue_node	*qprev;

	qprev = qnode->prev;
	if (in->queue_b->size < 2)
		return ;
	if (qprev == NULL || ((t_stack_node*)(qprev->value))->data >=
			((t_stack_node*)(qnode->value))->data)
		isort_master_b(in, ((t_stack_node*)(in->queue_b->tail->value))->next);
	else if ((t_stack_node*)(qprev->value) == in->stack_b->top)
		isort_up_op1(in, in->stack_b, qnode);
	else if (((t_stack_node*)(qprev->value))->key >= in->stack_b->size / 2)
		isort_up_op2(in, in->stack_b, qnode);
	else
		isort_up_op3(in, in->stack_b, qnode);
}
