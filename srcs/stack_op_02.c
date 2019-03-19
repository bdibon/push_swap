/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   stack_op_02.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/25 14:03:02 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/25 18:43:01 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "stack.h"

void	rotate_reverse(t_stack *stack_a)
{
	t_stack_node	*node;
	size_t			i;

	if (stack_a == NULL || stack_a->size <= 1)
		return ;
	stack_a->top = stack_a->bot;
	stack_a->bot = stack_a->top->prev;
	node = stack_a->bot;
	i = 0;
	while (node != stack_a->top)
	{
		node->key = i;
		i++;
		node = node->prev;
	}
	node->key = stack_a->size - 1;
}

void	rotate_reverse_double(t_stack *stack_a, t_stack *stack_b)
{
	rotate_reverse(stack_a);
	rotate_reverse(stack_b);
}
