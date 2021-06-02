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
	if (argc == 2)
		read_file(argv[1]);
	else
	{
		printf("*** Introduce correctamente el archivo ***\n");
		return (-1);
	}
}