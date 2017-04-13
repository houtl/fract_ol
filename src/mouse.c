/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 14:59:41 by thou              #+#    #+#             */
/*   Updated: 2017/04/13 18:12:56 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	reset_center(t_win *w, int x, int y)
{
	w->offset_x += OFFSETX((w->center_x - x) / w->zoom_x);
	w->offset_y += OFFSETY((w->center_y - y) / w->zoom_y);
	w->center_x = x;
	w->center_y = y;
}	

int		ft_mouse(int x, int y, t_win *w)
{
	if (w->color == -1 && x == -1 && y == -1)
		return (1);
	if (w->i == 1)
	{
		w->mouse_x = x;
		w->mouse_y = y;
	}
	init_image(w);
	w->func[w->i](w);
	return (0);
}

int		my_fonct_mouse(int button, int x, int y, t_win *w)
{
	if (button == 4)
	{
		reset_center(w, x, y);
		w->zoom_x *= ZOOM;
		w->zoom_y *= ZOOM;
	}
	if (button == 5)
	{
		reset_center(w, x, y);
		w->zoom_x /= ZOOM;
		w->zoom_y /= ZOOM;
	}
	init_image(w);
	w->func[w->i](w);
	reset_center(w, WIDTH / 2, HEIGHT / 2);
	return (0);
}
