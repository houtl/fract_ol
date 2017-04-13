/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 17:26:28 by thou              #+#    #+#             */
/*   Updated: 2017/04/13 17:20:59 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int		repeat(int y, int x, t_win *w)
{
	t_math	m;

	m.zoom_x = w->zoom_x * WIDTH / (X2 - X1);
	m.zoom_y = w->zoom_y * HEIGHT / (Y2 - Y1);
	m.x = ((double)x - w->center_x) / m.zoom_x + X1 + w->offset_x;
	m.y = ((double)w->center_y - y) / m.zoom_y + Y1 + w->offset_y;
	m.a = 0.0;
	m.b = 0.0;
	m.i = -1;
	while (++m.i < w->nuance)
	{
		m.m = m.a * m.a;
		m.n = m.b * m.b;
		m.o = m.a * m.b;
		m.a = m.m - m.n + m.x;
		m.b = m.o + m.o + m.y;
		if (m.m + m.n > 4)
			return (ft_color(w, m.i));
	}
	return (0xFFFFFF);
}

void	mandelbrot(t_win *w)
{
	int		x;
	int		y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			ft_p_pixel_image(w, y, x, repeat(y, x, w));
	}
	mlx_put_image_to_window(w->mlx, w->win, w->img, 0, 0);
	mlx_destroy_image(w->mlx, w->img);
}