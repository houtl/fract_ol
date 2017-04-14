/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 15:19:05 by thou              #+#    #+#             */
/*   Updated: 2017/04/14 17:41:48 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	mandel3(int y, int x, t_win *w)
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
		m.a = m.m * m.m - 6 * m.m * m.n + m.n * m.n + m.x;
		m.b = 4 * m.m * m.o + 4 * m.n * m.o + m.y;
		if (m.m + m.n > 4)
			return (ft_color(w, m.i));
	}
	return (w->background);
}
