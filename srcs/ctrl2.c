/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeniset <tdeniset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 21:22:09 by tdeniset          #+#    #+#             */
/*   Updated: 2014/03/27 16:47:18 by tdeniset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	ctrl_refract_fill(t_obj *obj, t_vec d)
{
	obj->refract = d;
}

void	ctrl_reflect_fill(t_obj *obj, t_vec d)
{
	obj->reflect = d;
}
