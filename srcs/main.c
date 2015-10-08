/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeniset <tdeniset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 11:34:15 by tdeniset          #+#    #+#             */
/*   Updated: 2014/03/27 23:22:18 by tdeniset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

int		ft_check_line_type(t_glob *gl, char *s)
{
	int		i;

	i = 0;
	while (gl->forms[i] != NULL && ft_strcmp(s, gl->forms[i]))
		i++;
	if (gl->forms[i])
		return (i);
	return (-1);
}

int		ft_parse(t_glob *gl)
{
	char	*line;
	int		res;

	while (get_next_line(gl->fd, &line) > 0)
	{
		res = ft_check_line_type(gl, line);
		if (res >= 0)
			ft_add_object(gl, res);
		ft_strdel(&line);
	}
	return (0);
}

int		ft_init(t_glob *gl)
{
	gl->forms = (char **)malloc(sizeof(*gl->forms) * (PLANE + 2));
	gl->forms[CAM] = ft_strdup("cam");
	gl->forms[LGHT] = ft_strdup("light");
	gl->forms[SPHERE] = ft_strdup("sphere");
	gl->forms[CONE] = ft_strdup("cone");
	gl->forms[CYLINDER] = ft_strdup("cylinder");
	gl->forms[PLANE] = ft_strdup("plane");
	gl->forms[PLANE + 1] = NULL;
	gl->ctrl = (t_obj_fill *)malloc(sizeof(*gl->ctrl) * (REFLECT + 1));
	gl->ctrl[CENTER].name = ft_strdup("center");
	gl->ctrl[CENTER].f = ctrl_pos_fill;
	gl->ctrl[DIR].name = ft_strdup("dir");
	gl->ctrl[DIR].f = ctrl_rot_fill;
	gl->ctrl[RADIUS].name = ft_strdup("radius");
	gl->ctrl[RADIUS].f = ctrl_rad_fill;
	gl->ctrl[COLOR].name = ft_strdup("color");
	gl->ctrl[COLOR].f = ctrl_col_fill;
	gl->ctrl[LIGHT].name = ft_strdup("light");
	gl->ctrl[LIGHT].f = ctrl_light_fill;
	gl->ctrl[REFRACT].name = ft_strdup("refract");
	gl->ctrl[REFRACT].f = ctrl_refract_fill;
	gl->ctrl[REFLECT].name = ft_strdup("reflect");
	gl->ctrl[REFLECT].f = ctrl_reflect_fill;
	gl->objl = NULL;
	return (0);
}

int		ft_exit(int fd, char *s)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
	exit(0);
}

int		main(int ac, char **av)
{
	t_glob	gl;
	char	*name;

	if (ac != 2)
		ft_exit(2, "\033[31musage = ./RT <file>\033[0m");
	ft_init(&gl);
	gl.fd = open(av[1], O_RDONLY);
	ft_parse(&gl);
	ft_data_convert(&gl);
	name = ft_strjoin("Raytacing - ", av[1]);
	gl.e.mlx = mlx_init();
	gl.e.win = mlx_new_window(gl.e.mlx, WIDTH, HEIGHT, name);
	gl.e.img = mlx_new_image(gl.e.mlx, WIDTH, HEIGHT);
	gl.i.data = mlx_get_data_addr(gl.e.img, &gl.i.bpp, &gl.i.size_l, &gl.i.endian);
	mlx_expose_hook(gl.e.win, expose_hook, &gl);
	mlx_key_hook(gl.e.win, key_hook, &gl.e);
	mlx_loop(gl.e.mlx);
	return (0);
}
