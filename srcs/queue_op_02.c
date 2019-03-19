/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   queue_op_02.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/21 17:36:52 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/21 17:37:18 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

void	q_rot(t_queue *queue)
{
	void	*qvalue;

	qvalue = dequeue(queue);
	enqueue(queue, qvalue);
}

void	q_rot_rev(t_queue *queue)
{
	void	*qvalue;

	qvalue = dequeue_rev(queue);
	enqueue_rev(queue, qvalue);
}
