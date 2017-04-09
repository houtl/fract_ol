/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 17:26:28 by thou              #+#    #+#             */
/*   Updated: 2017/04/09 18:10:52 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int		repeat(int y, int x)
{
	double	x1;
	double	y1;
	double	a;
	double	b;
	int		color;
	double	m;
	double	n;
	double	o;

	y1 = (double)(y - 700) / 400;
	x1 = (double)(x - 500) / 400;
	a = 0.0;
	b = 0.0;
	color = -1;
	while (++color < 256)
	{
		m = a * a;
		n = b * b;
		o = a * b;
		a = m - n + y1;
		b = o + o + x1;
		if (m + n > 4)
			return (color * 1000000 + color * 1000 + color);
	}
	return (0xFFFFFF);
}

void	mandelbrot(t_win *w)
{
	int		x;
	int		y;

	y = -1;
	while (++y < 1000)
	{
		x = -1;
		while (++x < 1000)
			ft_p_pixel_image(w, y, x, repeat(y, x));
	}
	mlx_put_image_to_window(w->mlx, w->win, w->img, 0, 0);
	mlx_destroy_image(w->mlx, w->img);
}
