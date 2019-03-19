/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   split_flush.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/25 13:51:45 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/25 13:51:46 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

void	split_flush(t_split *split)
{
	stack_destroy((t_stack*)split->stack_a);
	stack_destroy((t_stack*)split->stack_b);
	free(split->ps);
	free(split);
}
