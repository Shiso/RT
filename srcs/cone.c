/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeniset <tdeniset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 17:52:48 by mguinin           #+#    #+#             */
/*   Updated: 2014/03/27 23:38:58 by tdeniset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/geometry.h"

t_vec				cone_normal(t_vec *pos, void *data)
{
	t_cone			*c;
	t_vec			a;
	t_vec			i;

	c = (t_cone *)data;
	a = vsub(*pos, c->center);
	i = vsub(c->dir,scal_mult(scal(a, c->dir) / n2(a), a));
	return (scal_mult(c->gamma, i));
}

NUM					cone_intersec(t_ray *r, NUM inside, void *data)
{
	t_cone			c;
	NUM				sca1;
	NUM				sca2;
	t_pol2_num		p;
	t_vec			a;

	c = *(t_cone *)data;
	a = vsub(c.center, r->pos);
	sca1 = scal(a, c.dir);
	sca2 = scal(r->dir, c.dir);
	p.a = c.beta * sq(sca2) - n2(r->dir);
	p.b = c.beta * sca1 * sca2 - scal(r->dir, a);
	p.c = c.beta * sq(sca1) - n2(a);
	p.delta = sq(p.b) - p.a * p.c;
	if (p.delta >= 0.0)
		return ((p.b - inside * sqrt(p.delta)) / p.a);
	return (INFINITY);
}
