/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   med_02.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/24 14:46:58 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/24 19:22:25 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

void			med_flush(t_med **med)
{
	if ((*med)->left)
	{
		med_flush(&(*med)->left);
		(*med)->left = NULL;
	}
	if ((*med)->right)
	{
		med_flush(&(*med)->right);
		(*med)->right = NULL;
	}
	free(*med);
	*med = NULL;
}
