/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritmo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 10:09:01 by dsantama          #+#    #+#             */
/*   Updated: 2021/06/17 10:43:40 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static float 	Mmax(float a, float b)
{
	if (a > b)
		return(a);
	else
		return(b);
}

static float 	mod(float i)
{
	if (i < 0)
		return(-i);
	else
		return(i);
}

void 	unir_puntos(float x, float y, float x1, float y1, t_parse *parse)
{
	float x_step;
	float y_step;
	int   max;
	
	x *= parse->aumento;
	y *= parse->aumento;
	x1 *= parse->aumento;
	y1 *= parse->aumento;

	x += parse->x_mov;
	y += parse->y_mov;
	x1 += parse->x_mov;
	y1 += parse->y_mov;
	x_step = x1 - x;
	y_step = y1 - y;
	max = Mmax(mod(x_step), mod(y_step));
	x_step /= max;
	y_step /= max;
	while((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(parse->mlx, parse->win, x, y, 0xffffff);
		x += x_step;
		y += y_step;
	}
}

void	print_puntos(t_parse *parse)
{
	int x;
	int y;

	y = 0;
	while(y < parse->height)
	{
		x = 0;
		while (x < parse->width)
		{
			if(x < parse->width - 1)
				unir_puntos(x, y, x + 1, y, parse);
			if(y < parse->height - 1)
				unir_puntos(x, y, x, y + 1, parse);
			x++;
		}
		y++;
	}
}