/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeniset <tdeniset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 17:52:33 by mguinin           #+#    #+#             */
/*   Updated: 2014/03/27 23:39:42 by tdeniset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/geometry.h"

t_vec				sphere_normal(t_vec *pos, void *data)
{
	t_sphere		*s;

	s = (t_sphere *)data;
	return (scal_mult(s->inv_radius, vsub(*pos, s->center)));
}

NUM					sphere_intersec(t_ray *r, NUM inside, void *data)
{
	t_sphere		s;
	NUM				sca;
	t_vec			a;
	NUM				delta;
	NUM				dir2;

	s = *(t_sphere *)data;
	a = vsub(s.center, r->pos);
	dir2 = n2(r->dir);
	sca = scal(a, r->dir);
	delta = sq(sca) - dir2 * (n2(a) - s.radius2);
	if (delta >= 0.0)
		return ((sca + inside * sqrt(delta)) / dir2);
	return (INFINITY);
}
