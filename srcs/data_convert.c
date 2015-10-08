/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_convert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeniset <tdeniset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 18:16:36 by tdeniset          #+#    #+#             */
/*   Updated: 2014/03/27 23:21:14 by tdeniset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"
#include "../includes/geometry.h"

static int		ft_make_new_data_object(t_glob *gl, t_obj *o)
{
	t_object	*last;
	t_object	*new_elem;

	new_elem = (t_object *)malloc(sizeof(*new_elem));
	new_elem->primitives = (t_primitive *)malloc(sizeof(t_primitive));
	*new_elem->primitives = make_primitive(o);
	new_elem->l = o->light;
	printf("%s\n", gl->forms[o->type]);
	new_elem->next = NULL;
	last = gl->scene.in_obj;
	if (new_elem->primitives->data == NULL)
		return (-1);
	if (!last)
	{
		gl->scene.in_obj = new_elem;
		return (0);
	}
	while (last->next)
		last = last->next;
	last->next = new_elem;
	return (0);
}

static t_screen	ft_make_screen(t_obj *o)
{
	return ((t_screen){o->center, o->dir, WIDTH, HEIGHT, 1.1, 0.0});
}

static int		ft_add_light(t_glob *gl, t_obj *o)
{
	t_light_src	*tmp;
	t_light_src	*new_light;

	new_light = (t_light_src *)malloc(sizeof(*new_light));
	new_light->l = o->light;
	new_light->v = normalize(o->center);
	new_light->next = NULL;
	tmp = gl->scene.in_lights;
	if (!tmp)
	{
		gl->scene.in_lights = new_light;
		return (0);
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_light;
	return (0);
}

int				ft_data_convert(t_glob *gl)
{
	t_objl	*tmp;
	int		ret;

	tmp = gl->objl;
	if (!tmp)
		ft_exit(2, "fichier non valide");
	while (tmp)
	{
		if ((ret = ft_make_new_data_object(gl, tmp->obj)) < 0)
		{
			if (tmp->obj->type == CAM)
				gl->screen = ft_make_screen(tmp->obj);
			if (tmp->obj->type == LGHT)
				ft_add_light(gl, tmp->obj);
		}
		tmp = tmp->next;
	}
	return (0);
}
