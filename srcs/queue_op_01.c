/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   queue_op_01.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/15 16:47:05 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/25 13:07:20 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

void	q_swap_nodes(t_queue_node *node_1, t_queue_node *node_2)
{
	void	*tmp;

	tmp = node_1->value;
	node_1->value = node_2->value;
	node_2->value = tmp;
}

int		q_cmp_snodes(t_queue_node *node_1, t_queue_node *node_2)
{
	return (((t_stack_node*)(node_1->value))->data
			- ((t_stack_node*)(node_2->value))->data);
}

void	queue_insert_sort(t_queue *q, void *value)
{
	t_queue_node *qnode;

	enqueue(q, value);
	qnode = q->tail;
	while (qnode != q->head)
	{
		if (q_cmp_snodes(qnode, qnode->prev) < 0)
			q_swap_nodes(qnode, qnode->prev);
		qnode = qnode->prev;
	}
}

void	queue_insert_sort_rev(t_queue *q, void *value)
{
	t_queue_node *qnode;

	enqueue(q, value);
	qnode = q->tail;
	while (qnode != q->head)
	{
		if (q_cmp_snodes(qnode, qnode->prev) > 0)
			q_swap_nodes(qnode, qnode->prev);
		qnode = qnode->prev;
	}
}
