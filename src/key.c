/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 15:36:46 by thou              #+#    #+#             */
/*   Updated: 2017/04/14 16:12:31 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static void	my_fonct_key1(int keycode, t_win *w)
{
	if (keycode == KEY_UP)
		w->center_y += 20;
	else if (keycode == KEY_DOWN)
		w->center_y -= 20;
	else if (keycode == KEY_TAB)
		w->i = (w->i == 7) ? 0 : (w->i + 1);
	else if (keycode == KEY_B)
		w->background = ((w->background == 0xFFFFFF) ? 0x000000 : 0xFFFFFF);
	else if (keycode == KEY_SHIFT_LEFT || keycode == KEY_SHIFT_RIGHT)
		w->changejulia = (w->changejulia == 0) ? 1 : 0;
	else if (keycode == KEY_H)
		w->info = (w->info == 0) ? 1 : 0;
}

int			my_fonct_key(int keycode, t_win *w)
{
	if (keycode == KEY_ESC)
		ft_error("EXIT fractol");
	else if (keycode == KEY_C)
		w->color = (w->color >= 6) ? 0 : w->color + 1;
	else if (keycode == KEY_V)
		w->color = (w->color < 7 || w->color >= 18) ? 7 : w->color + 1;
	else if (keycode == KEY_X)
		w->color = -1;
	else if (keycode == KEY_N)
		w->nuance = (w->nuance < 999) ? (w->nuance + 1) : 1;
	else if (keycode == KEY_M)
		w->nuance = (w->nuance > 1) ? (w->nuance - 1) : 999;
	else if (keycode == KEY_LEFT)
		w->center_x -= 50;
	else if (keycode == KEY_RIGHT)
		w->center_x += 50;
	else if (keycode == KEY_R)
		reset(w);
	else
		my_fonct_key1(keycode, w);
	init_image(w);
	ft_fract_ol(w);
	return (0);
}
