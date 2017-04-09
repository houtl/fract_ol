/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 13:56:17 by thou              #+#    #+#             */
/*   Updated: 2017/04/09 18:17:39 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	ft_error(char *str)
{
	ft_printf("\033[31;1m%s\n", str);
	exit(1);
}

void	usage(void)
{
	ft_printf("\033[31;1mUsage: ./fract_ol\t[fractal] [fractal]\n");
	ft_printf("\033[32;1m\t\t\t[julia]\n");
	ft_printf("\033[32;1m\t\t\t[julia4]\n");
	ft_printf("\033[32;1m\t\t\t[mandel3]\n");
	ft_printf("\033[32;1m\t\t\t[mandel5]\n");
	ft_printf("\033[32;1m\t\t\t[mandelbrot]\n");
	ft_printf("\033[32;1m\t\t\t[quinticorn]\n");
	ft_printf("\033[32;1m\t\t\t[ship]\n");
	ft_printf("\t\t\t[tricorn]\n\033[0m");
	exit(1);
}
