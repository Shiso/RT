/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeniset <tdeniset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 10:03:39 by tdeniset          #+#    #+#             */
/*   Updated: 2014/03/27 23:23:02 by tdeniset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"
#include "../includes/geometry.h"

char	ft_color_comp(t_light c, int indian, int byte)
{
	c.r = (c.r > 255) ? 255 : c.r;
	c.g = (c.g > 255) ? 255 : c.g;
	c.b = (c.b > 255) ? 255 : c.b;
	if (indian)
	{
		if (byte == 1)
			return ((char)((int)c.r));
		if (byte == 2)
			return ((char)((int)c.g));
		if (byte == 3)
			return ((char)((int)c.b));
		else
			return (0);
	}
	else
	{
		if (byte == 0)
			return ((char)((int)c.b));
		if (byte == 1)
			return ((char)((int)c.g));
		if (byte == 2)
			return ((char)((int)c.r));
		else
			return (0);
	}
}

int		ft_trace(t_glob *gl)
{
	int		x;
	int		y;

	y = 0;
	gl->iter = screen_ray(gl->screen);
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ft_get_pixel(gl, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(gl->e.mlx, gl->e.win, gl->e.img, 0, 0);
	return (0);
}
