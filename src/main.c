/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 02:31:10 by home              #+#    #+#             */
/*   Updated: 2021/10/08 22:05:22 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(void)
{
	SDL_bool	window_exit;
	SDL_Color	bg = {40, 40, 40, 0};
	int			i;
	uint8_t		pixels[WIN_WIDTH * BPP * WIN_HEIGHT];
	int			vals[WIN_WIDTH * WIN_HEIGHT];

	SDL_Texture	*text;
	int			t = 0;
	text = SDL_CreateTexture(SDLX_GetDisplay()->renderer, SDL_PIXELFORMAT_BGR888, SDL_TEXTUREACCESS_STREAMING, WIN_WIDTH, WIN_HEIGHT);

	t_pellet	*points;
	size_t		size = 20;

	points = SDL_calloc(size, sizeof(*points));
	window_exit = SDL_FALSE;
	points[0].locationf = (SDL_FPoint){300, 200};
	points[0].location = (SDL_Point){300, 200};
	points[0].vel = (SDL_FPoint){1, 4};
	points[1].locationf = (SDL_FPoint){200, 800};
	points[1].location = (SDL_Point){200, 800};
	points[1].vel = (SDL_FPoint){-5, 20};
	points[2].locationf = (SDL_FPoint){250, 20};
	points[2].vel = (SDL_FPoint){-3, 2};
	points[3].locationf = (SDL_FPoint){500, 700};
	points[3].vel = (SDL_FPoint){-3, -1};

	points[4].locationf = (SDL_FPoint){330, 200};
	points[5].locationf = (SDL_FPoint){100, 100};
	points[6].locationf = (SDL_FPoint){300, 200};
	points[7].locationf = (SDL_FPoint){300, 200};
	points[8].locationf = (SDL_FPoint){500, 300};
	points[9].locationf = (SDL_FPoint){300, 600};
	points[10].locationf = (SDL_FPoint){410, 517};
	points[11].locationf = (SDL_FPoint){533, 739};
	points[12].locationf = (SDL_FPoint){599, 805};
	points[13].locationf = (SDL_FPoint){255, 826};
	points[14].locationf = (SDL_FPoint){473, 507};
	points[15].locationf = (SDL_FPoint){251, 568};
	points[16].locationf = (SDL_FPoint){537, 927};
	points[17].locationf = (SDL_FPoint){537, 927};
	points[18].locationf = (SDL_FPoint){537, 927};
	points[19].locationf = (SDL_FPoint){537, 927};

	t_circle		circle;
	t_circle_arr	c_array;
	t_thread_info	threadi[8];
	SDL_Thread		*(thread[8]);

	circle.pos = (SDL_Point){0, 0};
	circle.radius = 30;
	c_array.total = 0;
	c_array.capacity = 1000;
	c_array.x = SDL_calloc(c_array.capacity, sizeof(*(c_array.x)));
	c_array.y = SDL_calloc(c_array.capacity, sizeof(*(c_array.y)));

	c_array.vals = vals;

	out_circle(circle, circle_to_array, &(c_array));

	i = 0;
	while (i < 8)
	{
		threadi[i].start = i * (WIN_HEIGHT / 8);
		threadi[i].stop = threadi[i].start + (WIN_HEIGHT / 8);

		threadi[i].points = points;
		threadi[i].point_size = size;
		threadi[i].vals = vals;
		threadi[i].pixels = pixels;
		i++;
	}

	int temp;

	while (window_exit == SDL_FALSE)
	{
		window_exit = SDLX_poll();

		thread[0] = SDL_CreateThread(shader_filter, "SEC_1", &(threadi[0]));
		thread[1] = SDL_CreateThread(shader_filter, "SEC_2", &(threadi[1]));
		thread[2] = SDL_CreateThread(shader_filter, "SEC_3", &(threadi[2]));
		thread[3] = SDL_CreateThread(shader_filter, "SEC_4", &(threadi[3]));
		thread[4] = SDL_CreateThread(shader_filter, "SEC_5", &(threadi[4]));
		thread[5] = SDL_CreateThread(shader_filter, "SEC_6", &(threadi[5]));
		thread[6] = SDL_CreateThread(shader_filter, "SEC_7", &(threadi[6]));
		thread[7] = SDL_CreateThread(shader_filter, "SEC_8", &(threadi[7]));

		SDL_WaitThread(thread[0], &temp);
		SDL_WaitThread(thread[1], &temp);
		SDL_WaitThread(thread[2], &temp);
		SDL_WaitThread(thread[3], &temp);
		SDL_WaitThread(thread[4], &temp);
		SDL_WaitThread(thread[5], &temp);
		SDL_WaitThread(thread[6], &temp);
		SDL_WaitThread(thread[7], &temp);

		update_pellets(points, size);

		draw_boundary(&(c_array), &(points[0]), pixels);
		draw_boundary(&(c_array), &(points[1]), pixels);
		draw_boundary(&(c_array), &(points[2]), pixels);
		draw_boundary(&(c_array), &(points[3]), pixels);

		draw_boundary(&(c_array), &(points[4]), pixels);
		draw_boundary(&(c_array), &(points[5]), pixels);
		draw_boundary(&(c_array), &(points[6]), pixels);
		draw_boundary(&(c_array), &(points[7]), pixels);
		draw_boundary(&(c_array), &(points[8]), pixels);
		draw_boundary(&(c_array), &(points[9]), pixels);
		draw_boundary(&(c_array), &(points[10]), pixels);
		draw_boundary(&(c_array), &(points[11]), pixels);
		draw_boundary(&(c_array), &(points[12]), pixels);
		draw_boundary(&(c_array), &(points[13]), pixels);
		draw_boundary(&(c_array), &(points[14]), pixels);
		draw_boundary(&(c_array), &(points[15]), pixels);
		draw_boundary(&(c_array), &(points[16]), pixels);
		draw_boundary(&(c_array), &(points[17]), pixels);
		draw_boundary(&(c_array), &(points[18]), pixels);
		draw_boundary(&(c_array), &(points[19]), pixels);


		if (window_exit != SDL_TRUE && SDLX_discrete_frames(NULL) != EXIT_FAILURE)
		{
			SDL_UpdateTexture(text, NULL, pixels, WIN_WIDTH * BPP);
			SDL_RenderCopy(SDLX_GetDisplay()->renderer, text, NULL, NULL);

			SDLX_ScreenReset(SDLX_GetDisplay()->renderer, &(bg));
		}
		t += 5;
	}

	return (EXIT_SUCCESS);
}
