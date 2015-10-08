/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeniset <tdeniset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 16:48:06 by tdeniset          #+#    #+#             */
/*   Updated: 2014/03/27 22:45:47 by tdeniset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/geometry.h"

t_vec				cylinder_normal(t_vec *pos, void *data)
{
	t_cylinder		*c;
	t_vec			a;

	c = (t_cylinder *)data;
	a = vsub(*pos, c->center);
	return (scal_mult(c->inv_r, vsub(a, scal_mult(scal(a, c->dir), c->dir))));
}

NUM					cylinder_intersec(t_ray *r, NUM inside, void *data)
{
	t_cylinder			c;
	NUM					sca1;
	NUM					sca2;
	t_pol2_num			p;
	t_vec				a;

	c = *(t_cylinder *)data;
	a = vsub(c.center, r->pos);
	sca1 = scal(a, c.dir);
	sca2 = scal(r->dir, c.dir);
	p.a = sq(sca2) - n2(r->dir);
	p.b = sca1 * sca2 - scal(r->dir, a);
	p.c = c.r2 + sq(sca1) - n2(a);
	p.delta = sq(p.b) - p.a * p.c;
	if (p.delta >= 0.0)
		return ((p.b - inside * sqrt(p.delta)) / p.a);
	return (INFINITY);
}
