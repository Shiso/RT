/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeniset <tdeniset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 16:10:59 by mguinin           #+#    #+#             */
/*   Updated: 2014/03/27 21:57:26 by tdeniset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRY_H
# define GEOMETRY_H

# include "rt.h"

typedef struct s_plan t_plan;
typedef struct s_sphere t_sphere;
typedef struct s_cone t_cone;
typedef struct s_cylinder t_cylinder;
typedef struct s_pol2_num t_pol2_num;

#define EPSILON 0.001;

struct					s_plan
{
	NUM					c;
	t_vec				normal;
};

struct					s_sphere
{
	t_vec				center;
	NUM					inv_radius;
	NUM					radius2;
};

struct					s_cone
{
	t_vec				center;
	t_vec				dir;
	NUM					r1;
	NUM					beta;
	NUM					gamma;
};

struct					s_cylinder
{
	t_vec				center;
	t_vec				dir;
	NUM					r2;
	NUM					inv_r;
};

struct					s_pol2_num
{
	NUM					a;
	NUM					b;
	NUM					c;
	NUM					delta;
};

NUM			scal(t_vec a, t_vec b);
NUM			n2(t_vec a);
t_vec		vsub(t_vec a, t_vec b);
t_vec		scal_mult(NUM k, t_vec a);
t_vec		normalize(t_vec v);
t_vec		vprod(t_vec a, t_vec b);
t_vec		scal_mut(NUM k, t_vec a);
t_vec		forward_ray(t_ray *r, NUM len);
t_light		add_light(t_light l, t_light l2, NUM coef);

/*
 *	Math forms
 */
t_vec		sphere_normal(t_vec *pos, void *data);
NUM			sphere_intersec(t_ray *r, NUM inside, void *data);
t_vec		cone_normal(t_vec *pos, void *data);
NUM			cone_intersec(t_ray *r, NUM inside, void *data);
t_vec		cylinder_normal(t_vec *pos, void *data);
NUM			cylinder_intersec(t_ray *r, NUM inside, void *data);
t_vec		plan_normal(t_vec *pos, void *data);
NUM			plan_intersec(t_ray *r, NUM inside, void *data);


t_vec		reflexion(t_vec v, t_vec normal);
t_light		prod_light(t_light l, t_light l2);
t_light		mult_light(t_light l, NUM coef);
NUM			sq(NUM x);

#endif /* GEOMETRY_H */
