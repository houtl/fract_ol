/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 16:46:41 by thou              #+#    #+#             */
/*   Updated: 2017/04/12 16:12:12 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int		ft_color1(t_win *w, int i)
{
	int color;

	color = i * 255 / w->nuance;
	if (w->color == 10)
		return (RGB(0, 0, color));
	if (w->color == 11)
		return (RGB(0, color, 0));
	if (w->color == 12)
		return (RGB(255, 0, color));
	if (w->color == 13)
		return (RGB(color, 0, color));
	if (w->color == 14)
		return (RGB(color, 0, 0));
	if (w->color == 15)
		return (RGB(color, 0, 255));
	if (w->color == 16)
		return (RGB(color, color, 0));
	if (w->color == 17)
		return (RGB(color, 255, 0));
	if (w->color == 18)
		return (RGB(255, color, 0));
	return (w->rand[i]);
}

int		ft_color(t_win *w, int i)
{
	int color;

	color = i * 255 / w->nuance;
	if (w->color == 0)
		return (RGB(color, color, color));
	if (w->color == 1)
		return (RGB(255, color, color));
	if (w->color == 2)
		return (RGB(255, color, 255));
	if (w->color == 3)
		return (RGB(color, 255, 255));
	if (w->color == 4)
		return (RGB(color, 255, color));
	if (w->color == 5)
		return (RGB(color, color, 255));
	if (w->color == 6)
		return (RGB(255, 255, color));
	if (w->color == 7)
		return (RGB(0, color, color));
	if (w->color == 8)
		return (RGB(0, 255, color));
	if (w->color == 9)
		return (RGB(0, color, 255));
	return (ft_color1(w, i));
}
