/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 12:40:35 by thou              #+#    #+#             */
/*   Updated: 2017/04/09 18:17:53 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static int	checkname(t_win *w)
{
	if (!(ft_strcmp(w->name, "mandelbrot")))
		return (0);
	return (-1);
}

static void	init_t_win(t_win *w)
{
	w->func[0] = mandelbrot;
}

static void	windows(t_win *w)
{
	init_t_win(w);
	if ((w->i = checkname(w)) < 0)
		usage();
	if (!(w->win = mlx_new_window(w->mlx, WIDTH, HEIGHT, "fractol")))
		ft_error("mlx_new_window error");
	w->background = 1;
	w->info = -1;
	init_image(w);
	w->func[w->i](w);
	mlx_hook(w->win, 2, (1L << 01), my_fonct_key, w);
}

int			main(int ac, char **av)
{
	t_win	w[2];

	if (ac != 3 && ac != 2)
		usage();
	if (!(w[0].mlx = mlx_init()))
		ft_error("mlx_init error");
	if (ac == 3)
	{
		w[1].mlx = w[0].mlx;
		w[1].name = av[2];
		windows(&w[1]);
	}
	w[0].name = av[1];
	windows(&w[0]);
	mlx_loop(w[0].mlx);
	return (0);
}
