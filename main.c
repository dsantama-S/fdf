/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 10:50:04 by dsantama          #+#    #+#             */
/*   Updated: 2021/06/14 13:09:40 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void map(t_parse *parse)
{
	//enseñar mapa en la máquina
	int i;
	int j;
	
	i = 0;
	while(i < parse->height)
	{
		j = 0;
		while (j < parse->width)
		{
			printf("%3d", parse->punto[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
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
    parse->win = mlx_new_window(parse->mlx, 1920, 1080, "WireFrame");
	if (!(!argv[2]))
		parse->aumento = ft_atoi(argv[2]);
	else
		parse->aumento = 30;
    print_puntos(parse);
	map(parse);
	mlx_loop(parse->mlx);
}