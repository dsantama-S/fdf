/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 10:50:04 by dsantama          #+#    #+#             */
/*   Updated: 2021/06/17 10:46:44 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	movement(int keycode, t_parse *parse)
{
	if (keycode == 13)
		parse->aumento += 1;
	if (keycode == 1)
		parse->aumento -= 1;
	
	if (keycode == 126)
		parse->y_mov += 10;
	if (keycode == 123)
		parse->x_mov += 10;
	if (keycode == 124)
		parse->x_mov -= 10;
	if (keycode == 125)
		parse->y_mov -= 10;
	printf("%i\n", keycode);
	mlx_clear_window(parse->mlx, parse->win);
	print_puntos(parse);
	return (0);
}

int main(int argc, char **argv)
{
	t_parse		*parse;
	parse = ((t_parse *)malloc(sizeof(t_parse)));
	if (!parse)
		return (0);
	if (argc == 2 || argc == 3)
		read_file(argv[1], parse);
	else
	{
		printf("*** Introduce correctamente el archivo ***\n");
		return (-1);
	}
    parse->mlx = mlx_init();
    parse->win = mlx_new_window(parse->mlx, WIN_WIDTH, WIN_HEIGHT, "WireFrame");
	if (!(!argv[2]))
		parse->aumento = ft_atoi(argv[2]);
	else
		parse->aumento = 30;
	print_puntos(parse);
	mlx_key_hook(parse->win, movement, parse);
	mlx_loop(parse->mlx);
}