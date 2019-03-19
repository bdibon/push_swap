/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   split_check_02.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/25 13:29:31 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/25 13:29:34 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

size_t		check_split_path_ra_2(t_nstack *stack)
{
	t_stack_node	*snode;

	snode = stack->top;
	while (snode->data < stack->med)
		snode = snode->next;
	return (stack->top->key - snode->key);
}

size_t		check_split_path_rra_2(t_nstack *stack)
{
	t_stack_node	*snode;

	snode = stack->bot;
	while (snode->data < stack->med)
		snode = snode->next;
	return (snode->key + 1);
}
