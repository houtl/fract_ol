/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 12:51:13 by thou              #+#    #+#             */
/*   Updated: 2017/04/09 18:18:28 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "libft.h"
# include "mlx.h"

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

# define UP			126
# define DOWN		125
# define LEFT		123
# define RIGHT		124
# define EXIT		53
# define ISO_Z		6
# define HELP		4
# define BG			11
# define ISO		34
# define HIGH		13
# define LOW		1
# define GRAND		69
# define PETIT		78
# define ORIGIN		15
# define ORIGIN_Z	0

# define WIDTH		1920
# define HEIGHT 	1080

typedef struct	s_window
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*name;
	char		*data;
	int			bpp;
	int			sl;
	int			ed;
	int			background;
	int			info;
	int			i;
	void		(*func[8])(struct s_window *w);
}				t_win;

/*
**				 image.c
*/

void			init_image(t_win *w);
void			ft_p_pixel_image(t_win *w, int y, int x, int color);

/*
**				info.c
*/

void			usage(void);
void			ft_error(char *str);

/*
**				key.c
*/

int				my_fonct_key(int keycode, t_win *w);

/*
**				mandelbrot.c
*/

void			mandelbrot(t_win *w);

#endif
