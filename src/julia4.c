/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 17:53:20 by thou              #+#    #+#             */
/*   Updated: 2017/04/14 16:06:21 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	julia4(int y, int x, t_win *w)
{
	t_math	m;

	m.zoom_x = w->zoom_x * WIDTH / (X2 - X1);
	m.zoom_y = w->zoom_y * HEIGHT / (Y2 - Y1);
	m.a = ((double)x - w->center_x) / m.zoom_x + X1 + w->offset_x;
	m.b = ((double)w->center_y - y) / m.zoom_y + Y1 + w->offset_y;
	m.x = (double)w->mouse_x / WIDTH - 1;
	m.y = (double)w->mouse_y / HEIGHT;
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
