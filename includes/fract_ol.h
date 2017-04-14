/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 12:51:13 by thou              #+#    #+#             */
/*   Updated: 2017/04/14 17:35:56 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "libft.h"
# include "mlx.h"
# include "mlx_key.h"
# include <math.h>

# define WHITE		0xFFFFFF
# define BLUE		0x0901F7
# define BLUE_C		0x015BF7
# define SKY		0x01B5F7
# define LAGON		0x33AB9B
# define WGREEN		0x01F79D
# define RAZER		0x01F74B
# define LIMON		0xADF701
# define YELLOW		0xEFF701
# define ORANGE		0xF78C01
# define RED		0xFE4D01
# define BACKGROUND	0x4C1B1B

# define WIDTH		1920
# define HEIGHT 	1080
# define X1			-2.1
# define X2			0.6
# define Y1			-1
# define Y2			1
# define ZOOM		1.1
# define NUANCE		50

# define RGB(r, g, b)(256 * 256 * (int)r + 256 * (int)g + (int)b)
# define OFFSETX(x) (double)(-1 * ((double)(x) / WIDTH) * (X2 - X1))
# define OFFSETY(y) (double)(     ((double)(y) / HEIGHT) * (Y2 - Y1))

typedef struct	s_math
{
	double		x;
	double		y;
	double		a;
	double		b;
	double		m;
	double		n;
	double		o;
	double		zoom_x;
	double		zoom_y;
	int			i;
}				t_math;

typedef struct	s_window
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*name;
	char		*data;
	char		*tab[9];
	int			color;
	int			bpp;
	int			sl;
	int			ed;
	int			background;
	int			changejulia;
	int			info;
	int			i;
	int			(*func[8])(int	y, int x, struct s_window *w);
	int			rand[1000];
	int			nuance;
	double		zoom_x;
	double		zoom_y;
	double		offset_x;
	double		offset_y;
	double		center_x;
	double		center_y;
	int			mouse_x;
	int			mouse_y;
}				t_win;

/*
**				fractol.c
*/

void			reset(t_win *w);

/*
**				 image.c
*/

void			init_image(t_win *w);
void			ft_p_pixel_image(t_win *w, int y, int x, int color);

/*
**				info.c
*/

void			ft_put_info(t_win *w);
void			ft_fract_ol(t_win *w);
void			usage(void);
void			ft_error(char *str);

/*
**				key.c
*/

int				my_fonct_key(int keycode, t_win *w);

/*
**				color.c
*/

int				ft_color(t_win *w, int color);

/*
**				mouse.c
*/

int				ft_mouse(int x, int y, t_win *w);
int				my_fonct_mouse(int button, int x, int y, t_win *w);

/*
**				mandelbrot.c
*/

int				mandelbrot(int y, int x, t_win *w);

/*
**				julia.c
*/

int				julia(int y, int x, t_win *w);

/*
**				julia4.c
*/

int				julia4(int y, int x, t_win *w);

/*
**				mandel3.c
*/

int				mandel3(int y, int x, t_win *w);

/*
**				mandel5.c
*/

int				mandel5(int y, int x, t_win *w);

/*
**				multibrot.c
*/

int				multibrot(int y, int x, t_win *w);

/*
**				quinticorn.c
*/

int				quinticorn(int y, int x, t_win *w);

/*
**				tricorn.c
*/

int				tricorn(int y, int x, t_win *w);

#endif
