/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_geom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeniset <tdeniset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 21:08:21 by mguinin           #+#    #+#             */
/*   Updated: 2014/03/27 23:26:27 by tdeniset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/geometry.h"

NUM			scal(t_vec a, t_vec b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

NUM			n2(t_vec a)
{
	return (a.x * a.x + a.y * a.y + a.z * a.z);
}

t_vec		vsub(t_vec a, t_vec b)
{
	return ((t_vec){a.x - b.x, a.y - b.y, a.z - b.z});
}

t_vec		scal_mult(NUM k, t_vec a)
{
	return ((t_vec){k * a.x, k * a.y, k * a.z});
}

t_vec		normalize(t_vec v)
{
	return (scal_mult(1 / sqrt(n2(v)), v));
}
