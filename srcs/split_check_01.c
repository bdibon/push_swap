/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   split_check_01.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/25 13:29:00 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/25 13:29:02 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

size_t		check_split_path_ra(t_nstack *stack)
{
	t_stack_node	*snode;

	if (stack->nb_infmed == 0)
		return (0);
	snode = stack->top;
	while (snode->data > stack->med)
		snode = snode->next;
	return (stack->top->key - snode->key);
}

size_t		check_split_path_rra(t_nstack *stack)
{
	t_stack_node	*snode;

	if (stack->nb_infmed == 0)
		return (0);
	snode = stack->bot;
	while (snode->data > stack->med)
		snode = snode->prev;
	return (snode->key + 1);
}

size_t		check_split_path_rb(t_nstack *stack)
{
	t_stack_node	*snode;

	if (stack->nb_supmed == 0)
		return (0);
	snode = stack->top;
	while (snode->data <= stack->med)
		snode = snode->next;
	return (stack->top->key - snode->key);
}

size_t		check_split_path_rrb(t_nstack *stack)
{
	t_stack_node	*snode;

	if (stack->nb_supmed == 0)
		return (0);
	snode = stack->bot;
	while (snode->data <= stack->med)
		snode = snode->prev;
	return (snode->key + 1);
}
