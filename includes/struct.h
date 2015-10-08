/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeniset <tdeniset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 20:23:25 by mguinin           #+#    #+#             */
/*   Updated: 2014/03/27 16:07:49 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "rt.h"

# define SIGN(a) ((a) - !(a))

typedef struct s_object		t_object;
typedef struct s_ray		t_ray;
typedef struct s_ray_iter	t_ray_iter;
typedef struct s_screen		t_screen;
typedef struct s_material	t_material;
typedef struct s_primitive	t_primitive;
typedef struct s_effect		t_effect;
typedef struct s_diopter	t_diopter;


struct				s_ray
{
	t_vec			pos;
	t_vec			dir;
};

struct				s_screen
{
	t_vec			pos;
	t_vec			mir;
	int				w;
	int				h;
	NUM				anglex;
	NUM				angle_mir;
};

struct				s_ray_iter
{
	t_ray			ray;
	t_vec			dx;
	t_vec			dy;
};

struct				s_effect
{
	NUM				coef;
	t_light			(*effect)(t_glob *, t_ray *, t_vec, t_diopter);
	t_effect		*next;
};

struct				s_material
{
	t_light			(*absorption)(t_light, NUM, void *);
	void			*data;
	t_effect		*effects;
	t_diopter		diop;
};

struct				s_primitive
{
	NUM				(*intersec)(t_ray *, NUM, void *);
	t_vec			(*normal)(t_vec *, void *);
	void			*data;
	t_primitive		*next;
};

struct				s_object
{
	t_primitive		*primitives;
	t_material		inter_m;
	t_material		exter_m;
	t_objects		*in_obj;
	t_light_src		*in_lights;
	t_object		*next;
};

struct				s_ray_hit
{
	t_object		*obj;
	t_primitive		*front_face;
	t_material		*mat;
	t_vec			normal;
	t_vec			reflect;
	NUM				ray_len;
};

struct				s_ray_context
{
	t_ray			*ray;
	t_object		*in;
};

struct				s_light_src
{
	t_light			l;
	int				is_faraway;
	t_vec			v;
	t_light_src		next;
};

t_ray_iter			screen_ray(t_screen s);
t_ray				get_ray(t_ray_iter iter, int x, int y);
NUM					sphere_intersec(t_ray *r, NUM inside, void *data);

#endif /* STRUCT_H */
