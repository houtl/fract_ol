/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 13:56:17 by thou              #+#    #+#             */
/*   Updated: 2017/04/14 17:37:26 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	ft_put_info(t_win *w)
{
	char	*line;
	int		fd;
	int		i;

	i = 25;
	mlx_string_put(w->mlx, w->win, 20, 5, YELLOW, w->tab[w->i]);
	line = "press H for more information";
	mlx_string_put(w->mlx, w->win, 20, 25, YELLOW, line);
	fd = open(".info", O_RDONLY);
	while (w->info == 1 && (get_next_line(fd, &line)) > 0)
	{
		mlx_string_put(w->mlx, w->win, 20, (i += 20), RAZER, line);
		free(line);
	}
	close(fd);
}

void	ft_error(char *str)
{
	ft_printf("\033[31;1m%s\n", str);
	exit(1);
}

void	usage(void)
{
	ft_printf("\033[31;1mUsage: ./fract_ol\t[fractal] [fractal] [fractal]\n");
	ft_printf("\033[32;1m\t\t\t[julia]\n");
	ft_printf("\033[32;1m\t\t\t[julia4]\n");
	ft_printf("\033[32;1m\t\t\t[mandel3]\n");
	ft_printf("\033[32;1m\t\t\t[mandel5]\n");
	ft_printf("\033[32;1m\t\t\t[mandelbrot]\n");
	ft_printf("\033[32;1m\t\t\t[quinticorn]\n");
	ft_printf("\033[32;1m\t\t\t[multibrot]\n");
	ft_printf("\t\t\t[tricorn]\n\033[0m");
	exit(1);
}

void	ft_fract_ol(t_win *w)
{
	int		x;
	int		y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			ft_p_pixel_image(w, y, x, w->func[w->i](y, x, w));
	}
	mlx_put_image_to_window(w->mlx, w->win, w->img, 0, 0);
	ft_put_info(w);
	mlx_destroy_image(w->mlx, w->img);
}
