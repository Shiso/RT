/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primitives.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeniset <tdeniset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 10:01:37 by mguinin           #+#    #+#             */
/*   Updated: 2014/03/27 23:39:21 by tdeniset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"
#include "../includes/geometry.h"

t_primitive			make_plan(t_obj *o)
{
	t_plan			*p;

	p = (t_plan *)malloc(sizeof(t_plan));
	p->normal = normalize(o->dir);
	p->c = -scal(o->center, p->normal);
	return ((t_primitive){&plan_intersec, &plan_normal, p, NULL});
}

t_primitive			make_sphere(t_obj *o)
{
	t_sphere		*s;

	s = (t_sphere *)malloc(sizeof(t_sphere));
	s->center = o->center;
	s->inv_radius = 1.0 / o->radius;
	s->radius2 = sq(o->radius);
	return ((t_primitive){&sphere_intersec, &sphere_normal, s, NULL});
}

t_primitive			make_cylinder(t_obj *o)
{
	t_cylinder		*c;

	c = (t_cylinder *)malloc(sizeof(t_cylinder));
	c->center = o->center;
	c->dir = normalize(o->dir);
	c->r2 = sq(o->radius);
	c->inv_r = 1.0 / o->radius;
	return ((t_primitive){&cylinder_intersec, &cylinder_normal, c, NULL});
}

t_primitive			make_cone(t_obj *o)
{
	t_cone			*c;

	c = (t_cone *)malloc(sizeof(t_cone));
	c->center = o->center;
	c->dir = normalize(o->dir);
	c->r1 = o->radius;
	c->beta = 1 + sq(c->r1);
	c->gamma = sqrt(c->beta) / c->r1;
	return ((t_primitive){&cone_intersec, &cone_normal, c, NULL});
}

t_primitive			make_primitive(t_obj *o)
{
	if (o->type == SPHERE)
		return (make_sphere(o));
	if (o->type == CONE)
		return (make_cone(o));
	if (o->type == CYLINDER)
		return (make_cylinder(o));
	if (o->type == PLANE)
		return (make_plan(o));
	else
		return ((t_primitive){NULL, NULL, NULL, NULL});
}
