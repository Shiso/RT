/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeniset <tdeniset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 21:56:43 by tdeniset          #+#    #+#             */
/*   Updated: 2014/03/27 23:35:00 by tdeniset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"
#include "../includes/geometry.h"

t_vec		reflexion(t_vec v, t_vec normal)
{
	return (vsub(v, scal_mult(2 * scal(v, normal), normal)));
}

t_vec		vprod(t_vec a, t_vec b)
{
	NUM		x;
	NUM		y;
	NUM		z;

	x = a.y * b.z - b.y * a.z;
	y = a.z * b.x - b.z * a.x;
	z = a.x * b.y - b.x * a.y;
	return ((t_vec){x, y, z});
}
