/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 12:40:35 by thou              #+#    #+#             */
/*   Updated: 2017/04/13 18:18:30 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void		reset(t_win *w)
{
	w->nuance = 50;
	w->info = -1;
	w->color = 0;
	w->zoom_x = 1;
	w->zoom_y = 1;
	w->offset_x = OFFSETX(-WIDTH / 2);
	w->offset_y = OFFSETY(HEIGHT / 2);
	w->center_x = WIDTH / 2;
	w->center_y = HEIGHT / 2;
}
static int	checkname(t_win *w)
{
	if (!(ft_strcmp(w->name, "mandelbrot")))
		return (0);
	if (!(ft_strcmp(w->name, "julia")))
		return (1);
	return (-1);
}

static void	init_t_win(t_win *w)
{
	w->func[0] = mandelbrot;
	w->func[1] = julia;
}

static void	windows(t_win *w)
{
	init_t_win(w);
	if ((w->i = checkname(w)) < 0)
		usage();
	if (!(w->win = mlx_new_window(w->mlx, WIDTH, HEIGHT, "fractol")))
		ft_error("mlx_new_window error");
	reset(w);
	init_image(w);
	w->func[w->i](w);
	mlx_mouse_hook(w->win, my_fonct_mouse, w);
	mlx_hook(w->win, 2, (1L << 0), my_fonct_key, w);
	mlx_hook(w->win, 6, (1L << 6), ft_mouse, w);
}

int			main(int ac, char **av)
{
	t_win	w[3];

	srand(time(NULL));
	if (ac != 3 && ac != 2 && ac != 4)
		usage();
	if (!(w[0].mlx = mlx_init()))
		ft_error("mlx_init error");
	if (ac == 3)
	{
		w[1].mlx = w[0].mlx;
		w[1].name = av[2];
		windows(&w[1]);
	}
	if (ac == 4)
	{
		w[2].mlx = w[0].mlx;
		w[2].name = av[3];
		windows(&w[2]);
	}
	w[0].name = av[1];
	windows(&w[0]);
	mlx_loop(w[0].mlx);
	return (0);
}
