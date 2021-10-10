/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 21:39:01 by home              #+#    #+#             */
/*   Updated: 2021/10/08 17:59:53 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		square_distance(int x, int y, int to_x, int to_y)
{
	int	result;
	int	d_x;
	int	d_y;

	d_x = (to_x - x);
	d_y = (to_y - y);
	result = d_x * d_x + d_y * d_y;
	return (result);
}

static void	mirror_valid_cir_point(t_circle circle, void *meta_data, int x_at, int y_at, void (*f)(void *, int, int))
{
	f(meta_data, circle.pos.x + x_at, circle.pos.y + y_at);
	f(meta_data, circle.pos.x + x_at, circle.pos.y - y_at);
	f(meta_data, circle.pos.x - x_at, circle.pos.y + y_at);
	f(meta_data, circle.pos.x - x_at, circle.pos.y - y_at);
}

/**
** @brief This function shall send to function f the points to create a circle.
** @param circle The data of the circle, the position, and radius.
** @param f The function which will be called, it will be passed meta_data if necessary,
** and two `int`s that are on the circle's circumference.
** @param meta_data a void pointer that will be passed to function f for external information.
** If not necessary NULL can be passed into meta_data.
**/
void	out_circle(t_circle circle, void (*f)(void *, int, int), void *meta_data)
{
	int	x_at;
	int	y_at;
	int	sq_radius;

	x_at = 0;
	y_at = -(circle.radius);
	sq_radius = circle.radius;
	sq_radius = sq_radius * sq_radius;
	while (x_at <= circle.radius)
	{
		if (square_distance(x_at, y_at, 0, 0) > sq_radius)
			y_at++;
		else
			x_at++;
		mirror_valid_cir_point(circle, meta_data, x_at, y_at, f);
	}
}

void	circle_to_array(void *meta, int x, int y)
{
	t_circle_arr	*log;

	log = meta;
	SDL_assert(log->total < log->capacity);
	log->x[log->total] = x;
	log->y[log->total] = y;
	log->total++;
}