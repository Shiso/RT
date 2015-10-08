/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeniset <tdeniset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 20:40:48 by tdeniset          #+#    #+#             */
/*   Updated: 2014/03/27 23:37:39 by tdeniset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_vec	vect_new_vec(NUM x, NUM y, NUM z)
{
	t_vec	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_light	vect_new_light(NUM r, NUM g, NUM b)
{
	t_light	l;

	l.r = r;
	l.g = g;
	l.b = b;
	return (l);
}
