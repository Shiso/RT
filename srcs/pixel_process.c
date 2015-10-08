/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeniset <tdeniset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 19:48:53 by tdeniset          #+#    #+#             */
/*   Updated: 2014/03/27 23:29:16 by tdeniset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"
#include "../includes/geometry.h"

t_object	*ft_get_nearest_obj(t_glob *gl, t_ray *ray)
{
	t_object	*t;
	t_object	*res;
	t_sphere	*data;
	NUM			ret;
	NUM			distance;

	t = gl->scene.in_obj;
	res = NULL;
	if (!t)
		return (res);
	distance = INFINITY;
	while (t)
	{
		data = (t_sphere *)t->primitives->data;
		ret = t->primitives->intersec(ray, -1.0, t->primitives->data);
		res = (ret < distance) ? t : res;
		distance = (ret < distance) ? ret : distance;
		t = t->next;
	}
	ray->pos = forward_ray(ray, distance);
	return (res);
}

int			ft_get_pixel(t_glob *gl, int x, int y)
{
	t_object	*o;
	t_ray		ray;
	int			xypos;
	t_light		c;
	t_light		b;
	t_light_src	*l;
	t_vec		normal;

	ray = get_ray(gl->iter, x, y);
	o = ft_get_nearest_obj(gl, &ray);
	if (!o)
		return (-1);
	l = gl->scene.in_lights;
	xypos = (HEIGHT - y) * gl->i.size_l + x * (gl->i.bpp / 8);
	b = o->l;
	normal = o->primitives->normal(&ray.pos, o->primitives->data);
	c = mult_light(prod_light(l->l, b), 0.5 + 0.5 * scal(normal, l->v));
	c = add_light(c, l->l, pow(0.5 + 0.5 * scal(l->v, reflexion(ray.dir, normal)), 10));
    gl->i.data[xypos] = ft_color_comp(c, gl->i.endian, 0);
	gl->i.data[xypos + 1] = ft_color_comp(c, gl->i.endian, 1);
	gl->i.data[xypos + 2] = ft_color_comp(c, gl->i.endian, 2);
	gl->i.data[xypos + 3] = ft_color_comp(c, gl->i.endian, 3);
	return (0);
}
