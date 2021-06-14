/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 10:49:57 by dsantama          #+#    #+#             */
/*   Updated: 2021/06/14 10:09:09 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		define_height(char *path)
{
	char 	*line;
	int		fd;
	int		lines;

	lines = 0;
	fd = open(path, O_RDONLY, 0);
	if (fd == -1)
	{
		printf("*** Introduce correctamente el archivo ***\n");
		return (-1);
	}
	while(get_next_line(fd, &line))
	{
		lines++;
		free(line);
	}
	close(fd);
	return(lines);
}

static int		define_width(char *path)
{
	char 	*line;
	int		fd;
	int		x;

	x = 0;
	fd = open(path, O_RDONLY, 0);
	if (fd == -1)
		return(-1);
	get_next_line(fd, &line);
	x = ft_counter(line, ' ');
	close(fd);
	return(x);
}
static void		get_map(int	*z, char *line)
{
	char **nums;
	int		i;

	i = 0;
	nums = ft_strsplit(line, ' ');
	while(nums[i])
	{
		z[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

int 			read_file(char *path, t_parse *parse)
{
	int			fd;
	char		*line;
	int			i;
	
	i = 0;
	parse->height = define_height(path);
	parse->width = define_width(path);
	parse->punto = (int **)malloc(sizeof(int*) * (parse->height + 1));
	while(i <= parse->height)
		parse->punto[i++] = (int *)malloc(sizeof(int) * (parse->width + 1));
	i = 0;
	fd = open(path, O_RDONLY, 0);
	if (fd == -1)
		return(-1);
	while(get_next_line(fd, &line))
	{
		get_map(parse->punto[i], line);
		free(line);
		i++;
	}
	parse->punto[i] = NULL;
	close(fd);
	return (0);
}