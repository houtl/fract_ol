/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 17:53:20 by thou              #+#    #+#             */
/*   Updated: 2017/04/13 18:23:43 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static int	repeat(int y, int x, t_win *w)
{
	t_math	m;

	m.zoom_x = w->zoom_x * WIDTH / (X2 - X1);
	m.zoom_y = w->zoom_y * HEIGHT / (Y2 - Y1);
	m.x = ((double)x - w->center_x) / m.zoom_x + X1 + w->offset_x;
	m.y = ((double)w->center_y - y) / m.zoom_y + Y1 + w->offset_y;
	m.a = w->mouse_x / 1000 - 1;
	m.b = w->mouse_y / 400 - 1;
	m.i = -1;
	while (++m.i < w->nuance)
	{
		m.m = m.x * m.x;
		m.n = m.y * m.y;
		m.o = m.x * m.y;
		m.a = m.m - m.n + m.a;
		m.b = m.o + m.o + m.b;
		if (m.m + m.n > 4)
			return (ft_color(w, m.i));
	}
	return (0xFFFFFF);
}

void	julia(t_win *w)
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
