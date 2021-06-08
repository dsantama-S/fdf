/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 10:50:04 by dsantama          #+#    #+#             */
/*   Updated: 2021/06/02 11:18:19 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
	parse		*parse;

	parse = ((parse *)malloc(sizeof(parse)));
	if (!parse)
		return (0);
	if (argc == 2)
		read_file(argv[1], parse);
	else
	{
		printf("*** Introduce correctamente el archivo ***\n");
		return (-1);
	}
	
	int i;
	int j;

	i = 0;
	while(i < parse->height)
	{
		j = 0;
		while (j < parse->width)
		{
			printf("%d", parse->punto[i][j])
			j++;
		}
		printf("\n");
		i++;
	}
}