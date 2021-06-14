/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritmo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 10:09:01 by dsantama          #+#    #+#             */
/*   Updated: 2021/06/14 11:11:38 by dsantama         ###   ########.fr       */
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

void 	puntos(float x, float y, float x1, float y1, t_parse *parse)
{
	float x_step;
	float y_step;
	int   max;

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