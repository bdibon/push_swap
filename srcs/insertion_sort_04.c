/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   insertion_sort_04.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/17 19:49:27 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/25 12:59:47 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

void			isort_master_a(t_insert *in, t_stack_node *snode)
{
	int path;

	if (in->stack_a->size < 2 || in->stack_a->size == in->queue_a->size)
		return ;
	if (in->queue_a->size == 0)
	{
		enqueue(in->queue_a, snode);
		isort_master_a(in, snode->next);
		return ;
	}
	if ((path = find_path_to_qnode(in, in->stack_a, snode)) > 0)
	{
		enqueue(in->queue_a, snode);
		isort_up_a(in, in->queue_a->tail);
	}
	else if (path < 0)
	{
		queue_insert_sort(in->queue_a, snode);
		isort_down_a(in, snode);
	}
	else
	{
		queue_insert_sort(in->queue_a, snode);
		isort_master_a(in, snode->next);
	}
}

void			isort_master_b(t_insert *in, t_stack_node *snode)
{
	int path;

	if (in->stack_b->size < 2 || in->stack_b->size == in->queue_b->size)
		return ;
	if (in->queue_b->size == 0)
	{
		enqueue(in->queue_b, snode);
		isort_master_b(in, snode->next);
		return ;
	}
	if ((path = find_path_to_qnode(in, in->stack_b, snode)) > 0)
	{
		enqueue(in->queue_b, snode);
		isort_up_b(in, in->queue_b->tail);
	}
	else if (path < 0)
	{
		queue_insert_sort_rev(in->queue_b, snode);
		isort_down_b(in, snode);
	}
	else
	{
		queue_insert_sort_rev(in->queue_b, snode);
		isort_master_b(in, snode->next);
	}
}

void			isort_master(t_insert *in, t_stack *stack, t_stack_node *snode)
{
	if (stack == in->stack_a)
		isort_master_a(in, snode);
	else
		isort_master_b(in, snode);
}
