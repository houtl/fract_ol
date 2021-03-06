/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 15:09:59 by thou              #+#    #+#             */
/*   Updated: 2017/04/13 17:41:13 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void		ft_p_pixel_image(t_win *w, int y, int x, int color)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		*(unsigned int*)(w->data + (x * (w->bpp)) + (y * w->sl)) = color;
}

static void	ft_rand(t_win *w)
{
	int x;

	x = -1;
	while (++x < 1000)
		w->rand[x] = rand();
}

void		init_image(t_win *w)
{
	w->img = mlx_new_image(w->mlx, WIDTH, HEIGHT);
	w->data = mlx_get_data_addr(w->img, &w->bpp, &w->sl, &w->ed);
	if (w->data == NULL)
		ft_error("GET_DATA ERROR");
	w->bpp /= 8;
	if (w->color == -1)
		ft_rand(w);
}
