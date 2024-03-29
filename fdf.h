/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 10:50:01 by dsantama          #+#    #+#             */
/*   Updated: 2021/06/17 10:26:14 by dsantama         ###   ########.fr       */
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

# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 1080
# endif

# ifndef WIN_WIDTH
#  define WIN_WIDTH 1920
# endif

typedef struct  s_parse {

    int         width;
    int         height;
	int 		**punto;
    int			aumento;
	int			x_mov;
	int			y_mov;
    void        *mlx;
    void        *win;
}               t_parse;

typedef struct  s_imgs {
	void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_imgs;

int 				read_file(char *path, t_parse *parse);
int					get_next_line(int fd, char **line);
void 				unir_puntos(float x, float y, float x1, float y1, t_parse *parse);
void				print_puntos(t_parse *parse);
int					movement(int keycode, t_parse *parse);

#endif