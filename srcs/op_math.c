/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeniset <tdeniset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 21:08:44 by mguinin           #+#    #+#             */
/*   Updated: 2014/03/27 23:28:12 by tdeniset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/geometry.h"

NUM			sq(NUM x)
{
	return (x * x);
}

t_vec		forward_ray(t_ray *r, NUM len)
{
	t_vec	res;

	res.x = r->pos.x + r->dir.x * len;
	res.y = r->pos.y + r->dir.y * len;
	res.z = r->pos.z + r->dir.z * len;
	return (res);
}

t_light		add_light(t_light l, t_light l2, NUM coef)
{
	t_light			res;

	res.r = l.r + coef * l2.r;
	res.g = l.g + coef * l2.g;
	res.b = l.b + coef * l2.b;
	return (res);
}

t_light		prod_light(t_light l, t_light l2)
{
	t_light		res;

	res.r = l.r * l2.r;
	res.g = l.g * l2.g;
	res.b = l.b * l2.b;
	return (res);
}

t_light		mult_light(t_light l, NUM coef)
{
	t_light		res;

	res.r = coef * l.r;
	res.g = coef * l.g;
	res.b = coef * l.b;
	return (res);
}
