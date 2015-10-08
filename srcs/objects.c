/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeniset <tdeniset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 13:30:53 by tdeniset          #+#    #+#             */
/*   Updated: 2014/03/27 23:25:13 by tdeniset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static t_objl	*objl_new_elem(t_obj *obj)
{
	t_objl	*elem;

	elem = (t_objl *)malloc(sizeof(*elem));
	elem->obj = obj;
	elem->next = NULL;
	return (elem);
}

static t_obj	*ft_new_obj(t_glob *gl, enum e_forms type)
{
	char	*line;
	char	*ctrl;
	t_obj	*obj;
	t_vec	tmp;
	int		i;

	obj = (t_obj *)malloc(sizeof(*obj));
	ctrl = ft_strnew(20);
	while (get_next_line(gl->fd, &line) > 0 && *line != '}')
	{
		tmp = vect_new_vec(0, 0, 0);
		sscanf(line, "\t%20s : %lf %lf %lf\n", ctrl, &tmp.x, &tmp.y, &tmp.z);
		i = 0;
		while (i <= REFLECT && ft_strcmp(gl->ctrl[i].name, ctrl))
			i++;
		if (i <= REFLECT)
			gl->ctrl[i].f(obj, tmp);
		ft_strdel(&line);
	}
	obj->type = type;
	return (obj);
}

int				ft_add_object(t_glob *gl, enum e_forms type)
{
	t_obj	*obj;
	t_objl	*tmp;

	obj = ft_new_obj(gl, type);
	tmp = gl->objl;
	if (!tmp)
	{
		gl->objl = objl_new_elem(obj);
		return (0);
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = objl_new_elem(obj);
	return (0);
}
