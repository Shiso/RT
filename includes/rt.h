/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeniset <tdeniset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 11:35:31 by tdeniset          #+#    #+#             */
/*   Updated: 2014/03/27 22:56:02 by tdeniset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include "../libft/includes/libft.h"
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>

# define NUM double
# define WIDTH 1000
# define HEIGHT 800

# define SIGN(a) ((a) - !(a))

enum e_forms
{
	CAM,
	LGHT,
	SPHERE,
	CONE,
	CYLINDER,
	PLANE
};

enum e_ctrl
{
	CENTER,
	DIR,
	RADIUS,
	COLOR,
	LIGHT,
	REFRACT,
	REFLECT
};

typedef struct s_light		t_light;
typedef struct s_ray		t_ray;
typedef struct s_ray_iter	t_ray_iter;
typedef struct s_vec		t_vec;
typedef struct s_effect		t_effect;
typedef struct s_diopter	t_diopter;
typedef struct s_material	t_material;

typedef struct s_primitive	t_primitive;
typedef struct s_object		t_object;

typedef struct s_obj		t_obj;
typedef struct s_objl		t_objl;
typedef struct s_obj_fill	t_obj_fill;
typedef struct s_obj_type	t_obj_type;

typedef struct s_light_src	t_light_src;
typedef struct s_screen		t_screen;
typedef struct s_env		t_env;
typedef struct s_img		t_img;
typedef struct s_glob		t_glob;


//typedef struct s_objl		t_objl;
/*
 *	Rays, Lights, verctors
 */

struct				s_vec
{
	NUM			x;
	NUM			y;
	NUM			z;
};

struct				s_light
{
	NUM				r;
	NUM				g;
	NUM				b;
};

struct				s_ray
{
	t_vec			pos;
	t_vec			dir;
};

struct				s_ray_iter
{
	t_ray			ray;
	t_vec			dx;
	t_vec			dy;
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

struct				s_diopter
{
	NUM				n1n2;
	NUM				n2n1;
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

/*
 *	Parsing
 */

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
	t_light			l;
	t_object		*in_obj;
	t_light_src		*in_lights;
	t_object		*next;
};


struct				s_obj
{
	enum e_forms	type;
	t_vec			center;
	t_vec			dir;
	t_vec			color;
	t_vec			refract;
	t_vec			reflect;
	NUM				radius;
	NUM				inv_radius;
	NUM				r1;
	NUM				r2;
	NUM				beta;
	NUM				gamma;
	NUM				c;
	t_light			light;
};


struct		s_obj_fill
{
	char	*name;
	void	(*f)(t_obj *, t_vec);
};

struct s_objl
{
	t_obj		*obj;
	t_objl		*next;
};

/*
 *	Datas
 */
struct				s_light_src
{
	t_light			l;
	int				is_faraway;
	t_vec			v;
	t_light_src		*next;
};

struct			s_screen
{
	t_vec		pos;
	t_vec		mir;
	int			w;
	int			h;
	NUM			anglex;
	NUM			angle_mir;
};

struct			s_env
{
	void		*mlx;
	void		*win;
	void		*img;
};

struct 			s_img
{
	char		*data;
	int			bpp;
	int			endian;
	int			size_l;
};

struct 				s_glob
{
	int				fd;
	t_env			e;
	t_img			i;
	t_ray_iter		iter;
	t_screen		screen;
	char			**forms;
	t_obj_fill		*ctrl;
	t_objl			*objl;
	t_object		scene;
};

int				ft_exit(int fd, char *s);
int				ft_define_obj(t_glob *gl);
t_vec			vect_new_vec(NUM x, NUM y, NUM z);
t_light			vect_new_light(NUM r, NUM g, NUM b);

/*
 *	mlx
 */
int				expose_hook(t_glob *gl);
int				key_hook(int keycode, t_env *e);
int				ft_trace(t_glob *gl);

char			ft_color_comp(t_light c, int indian, int byte);
int				ft_get_pixel(t_glob *gl, int x, int y);

/*
 *	colecting data
 */
void			ctrl_pos_fill(t_obj *obj, t_vec d);
void			ctrl_rot_fill(t_obj *obj, t_vec d);
void			ctrl_col_fill(t_obj *obj, t_vec d);
void			ctrl_rad_fill(t_obj *obj, t_vec d);
void			ctrl_light_fill(t_obj *obj, t_vec d);
void			ctrl_refract_fill(t_obj *obj, t_vec d);
void			ctrl_reflect_fill(t_obj *obj, t_vec d);

int				ft_add_object(t_glob *gl, enum e_forms type);
int				ft_data_convert(t_glob *gl);
t_primitive		make_primitive(t_obj *o);

/*
 * Rays
 */
t_ray_iter		screen_ray(t_screen s);
t_ray			get_ray(t_ray_iter iter, int x, int y);
NUM				sphere_intersec(t_ray *r, NUM inside, void *data);


#endif /* RT_H */
