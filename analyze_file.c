/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 10:49:57 by dsantama          #+#    #+#             */
/*   Updated: 2021/06/02 14:06:08 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		coordenadas(t_parse *parse)
{
}

static void		define_map(int fd, t_parse *parse)
{
	char	*map;
	char	*aux;
	char	*aux2;
	char	*aux3;
	char	*line;

	map = ft_strdup("");
	while (get_next_line(fd, &line) != 0)
	{
		aux = ft_strjoin(map, line);
		free(map);
		map = aux;
		aux2 = ft_strjoin(map, "\n");
		free(map);
		map = aux2;
	}
	aux3 = ft_strjoin(map, line);
	free(map);
	map = aux3;
	close(fd);
	parse->map = map;
}

int 			read_file(char *path)
{
	int			fd;
	t_parse		*parse;
	
	parse = ((t_parse *)malloc(sizeof(t_parse)));
	if (!parse)
		return (0);
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		printf("*** Introduce correctamente el archivo ***\n");
		return (-1);
	}
	define_map(fd, parse);
	coordenadas(parse);
	free(parse);
	return (0);
}