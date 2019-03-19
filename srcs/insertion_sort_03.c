/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   insertion_sort_03.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/17 19:26:30 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/25 13:03:18 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

void					q_swap_maj(t_queue *queue, t_stack_node *snode)
{
	t_queue_node *qnode;
	t_queue_node *qsnode;
	t_queue_node *qsnext;

	qnode = queue->head;
	qsnode = NULL;
	qsnext = NULL;
	while (qnode)
	{
		if (qnode->value == snode)
			qsnode = qnode;
		if (qnode->value == snode->next)
			qsnext = qnode;
		qnode = qnode->next;
	}
	if (qsnode && qsnext)
		q_swap_nodes(qsnode, qsnext);
	if (qsnode)
		qsnode->value = snode->next;
}

static t_queue_node		*find_qnode(t_insert *in, t_stack *stack,
	t_stack_node *snode)
{
	t_queue_node	*qnode;

	qnode = (stack == in->stack_a) ? in->queue_a->head : in->queue_b->head;
	while (qnode)
	{
		if (stack == in->stack_a
				&& ((t_stack_node*)(qnode->value))->data > snode->data)
			break ;
		else if (stack == in->stack_b
				&& ((t_stack_node*)(qnode->value))->data < snode->data)
			break ;
		qnode = qnode->next;
	}
	return (qnode);
}

static int				compute_pth_up(t_stack *stack, size_t key,
	t_stack_node *snode)
{
	int pth_up;

	if (key > snode->key)
		pth_up = stack->top->key - 1 - snode->key
			+ 2 * (key - snode->key) - 1;
	else
	{
		if (snode != stack->top)
			pth_up = stack->top->key - 1 - snode->key
				+ 2 * (stack->top->key - snode->key + key) - 1;
		else
			pth_up = 2 * key;
	}
	return (pth_up);
}

static int				compute_pth_down(t_stack *stack, size_t key,
	t_stack_node *snode)
{
	int pth_down;

	if (key > snode->key)
		pth_down = (snode->key + 1)
			+ 2 * (snode->key + stack->top->key - key) - 1;
	else
		pth_down = stack->top->key - snode->key
			+ 2 * (snode->key - 1 - key) - 1;
	return (pth_down);
}

int						find_path_to_qnode(t_insert *in, t_stack *stack,
	t_stack_node *snode)
{
	t_queue_node	*qnode;
	size_t			key;
	int				pth_down;
	int				pth_up;

	qnode = find_qnode(in, stack, snode);
	if (qnode == NULL)
	{
		in->ndata = snode->data;
		return (0);
	}
	in->ndata = ((t_stack_node*)(qnode->value))->data;
	key = ((t_stack_node*)(qnode->value))->key;
	pth_up = compute_pth_up(stack, key, snode);
	pth_down = compute_pth_down(stack, key, snode);
	if ((pth_up == 1 || pth_down == 1) && snode->next->data == in->ndata)
		return (0);
	return ((pth_up >= pth_down) ? -1 : 1);
}
