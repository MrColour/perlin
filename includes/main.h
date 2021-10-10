/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 02:38:32 by home              #+#    #+#             */
/*   Updated: 2021/05/21 00:54:05 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef main_H
# define main_H

# include <SDL2/SDL_image.h>

# include "SDLX.h"

# define ASSETS "assets/"

#define BPP (4)

typedef struct	s_pellet
{
	SDL_FPoint	locationf;
	SDL_Point	location;
	SDL_FPoint	vel;
}				t_pellet;

typedef struct	circle
{
	SDL_Point	pos;
	double		radius;
}				t_circle;

typedef struct	s_circle_arr
{
	size_t		capacity;
	size_t		total;
	int			*x;
	int			*y;

	int			*vals;
}				t_circle_arr;

typedef struct	s_thread_info
{
	size_t		start;
	size_t		stop;

	t_pellet	*points;
	size_t		point_size;
	int			*vals;
	u_int8_t	*pixels;
}				t_thread_info;

int		clerp(int color1, int color2, int t, int tmax);
void	ctoRGB(int color, int *r, int *g, int *b);
void	set_color(int val, int *r, int *g, int *b);

int		true_min(const int x, const int y, const t_pellet *points, const size_t amount);
void	update_pellets(t_pellet *pellets, size_t size);

void	out_circle(t_circle circle, void (*f)(void *, int, int), void *meta_data);
void	circle_to_array(void *c_array, int x, int y);

void	draw_boundary(t_circle_arr *array, t_pellet *from, uint8_t *pixels);

int	shader_filter(void *ptr);

#endif
