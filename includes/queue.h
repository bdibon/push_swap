/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   queue.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/12 17:16:51 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/25 14:41:14 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#	ifndef QUEUE_H
#	define QUEUE_H

#include "../libft/libft.h"

typedef struct				s_queue
{
	struct s_queue_node		*head;
	struct s_queue_node		*tail;
	size_t					size;
}							t_queue;

typedef struct				s_queue_node
{
	void					*value;
	size_t					key;
	struct s_queue_node		*next;
	struct s_queue_node		*prev;
}							t_queue_node;

t_queue						*queue_create(void);
t_queue_node				*enqueue(t_queue *queue, void *value);
void						*dequeue(t_queue *queue);
void						queue_clear_destroy(t_queue *queue);
void						queue_destroy(t_queue *queue);
int							queue_size(t_queue *queue);
void						*queue_peek(t_queue *queue);
void						queue_print(t_queue *queue);
void						print_op(t_queue *queue);

t_queue_node				*enqueue_rev(t_queue *queue, void *value);
void						*dequeue_rev(t_queue *queue);

void						q_swap_nodes(t_queue_node *node_1,
		t_queue_node *node_2);
int							q_cmp_snodes(t_queue_node *node_1,
		t_queue_node *node_2);
void						queue_insert_sort(t_queue *q, void *value);
void						queue_insert_sort_rev(t_queue *q, void *value);
void						q_rot(t_queue *queue);
void						q_rot_rev(t_queue *queue);
void						q_swap(t_queue *queue);

#	endif
