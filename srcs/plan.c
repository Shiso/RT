/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeniset <tdeniset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 23:29:53 by tdeniset          #+#    #+#             */
/*   Updated: 2014/03/27 23:38:41 by tdeniset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/geometry.h"

t_vec			plan_normal(t_vec *pos, void *data)
{
	t_plan		*plan;

	(void)pos;
	plan = (t_plan *)data;
	return (plan->normal);
}

NUM				plan_intersec(t_ray *r, NUM inside, void *data)
{
	t_plan		*plan;
	NUM			sca;
	NUM			res;

	(void)inside;
	plan = (t_plan *)data;
	sca = scal(r->dir, plan->normal);
	if (sca == 0)
		return (INFINITY);
	res = -(scal(r->pos, plan->normal) + plan->c) / sca;
	if (res < 0)
		return (INFINITY);
	return (res);
}
