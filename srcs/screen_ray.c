/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeniset <tdeniset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 20:57:56 by mguinin           #+#    #+#             */
/*   Updated: 2014/03/27 23:36:28 by tdeniset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"
#include "../includes/geometry.h"

t_ray_iter			screen_ray(t_screen s)
{
	t_ray_iter		iter;
	t_vec			horiz;
	t_vec			verti;
	NUM				si;
	NUM				co;

	s.mir = normalize(s.mir);
	horiz = normalize((t_vec){-s.mir.y, s.mir.x, 0.0});
	verti = vprod(s.mir, horiz);
	si = sin(s.angle_mir);
	co = cos(s.angle_mir);
	iter.dx = vsub(scal_mult(co, horiz), scal_mult(-si, verti));
	iter.dy = vsub(scal_mult(si, horiz), scal_mult(co, verti));
	si = 2 * sin(s.anglex / 2) / (NUM)s.w;
	iter.dx = scal_mult(si, iter.dx);
	iter.dy = scal_mult(si, iter.dy);
	iter.ray.pos = s.pos;
	iter.ray.dir = vsub(s.mir, scal_mult(s.w * 0.5, iter.dx));
	iter.ray.dir = vsub(iter.ray.dir, scal_mult(s.h * 0.5, iter.dy));
	return (iter);
}

t_ray				get_ray(t_ray_iter iter, int x, int y)
{
	t_vec			v;

	v = vsub(iter.ray.dir, scal_mult(-(NUM)x, iter.dx));
	v = vsub(v, scal_mult(-(NUM)y, iter.dy));
	return ((t_ray){iter.ray.pos, normalize(v)});
}
