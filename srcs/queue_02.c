/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   queue_02.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/12 17:23:33 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/25 13:06:26 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

t_queue_node	*enqueue_rev(t_queue *queue, void *value)
{
	t_queue_node *new;

	new = ft_memalloc(sizeof(t_queue_node));
	new->value = value;
	new->next = queue->head;
	new->prev = NULL;
	new->key = 0;
	if (queue->head)
		queue->head->prev = new;
	queue->head = new;
	if (queue->size == 0)
		queue->tail = new;
	queue->size++;
	return (new);
}

void			*dequeue_rev(t_queue *queue)
{
	void			*value;
	t_queue_node	*tmp;

	if (queue->size == 0)
		return (NULL);
	value = queue->tail->value;
	tmp = queue->tail->prev;
	free(queue->tail);
	queue->size--;
	queue->tail = tmp;
	queue->tail->next = NULL;
	return (value);
}

void			*queue_peek(t_queue *queue)
{
	return (queue->head->value);
}

void			queue_print(t_queue *queue)
{
	t_queue_node	*cur;

	cur = queue->head;
	while (cur)
	{
		ft_printf("[%d]", ((t_stack_node*)(cur->value))->data);
		if (cur != queue->tail)
			ft_printf(" ");
		cur = cur->next;
	}
	ft_printf("\n");
}

void			print_op(t_queue *queue)
{
	t_queue_node	*op;

	op = queue->head;
	while (op)
	{
		ft_printf("%s\n", op->value);
		op = op->next;
	}
}
