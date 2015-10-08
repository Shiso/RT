/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeniset <tdeniset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 21:21:18 by tdeniset          #+#    #+#             */
/*   Updated: 2014/03/27 23:20:05 by tdeniset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	ctrl_pos_fill(t_obj *obj, t_vec d)
{
	obj->center = d;
}

void	ctrl_rot_fill(t_obj *obj, t_vec d)
{
	obj->dir = d;
}

void	ctrl_col_fill(t_obj *obj, t_vec d)
{
	obj->color = d;
}

void	ctrl_rad_fill(t_obj *obj, t_vec d)
{
	obj->radius = d.x;
}

void	ctrl_light_fill(t_obj *obj, t_vec d)
{
	obj->light.r = d.x;
	obj->light.g = d.y;
	obj->light.b = d.z;
}
