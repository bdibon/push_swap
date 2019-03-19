/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   queue_03.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/15 19:40:09 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/24 20:03:29 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

void				queue_destroy(t_queue *queue)
{
	t_queue_node	*cur;
	t_queue_node	*tmp;

	cur = queue->head;
	while (cur)
	{
		tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	free(queue);
}
