/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 10:50:01 by dsantama          #+#    #+#             */
/*   Updated: 2021/06/02 13:37:41 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include "mlx/mlx.h"
# include "libft/libft.h"

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <math.h>

typedef struct  s_vars {
    void        *mlx;
    void        *win;
}               t_vars;

typedef struct  s_parse {
	char		*map;
	char		**punto;
}               t_parse;

int 				read_file(char *path);
int					get_next_line(int fd, char **line);

#endif