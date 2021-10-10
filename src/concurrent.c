/***************************************************************************
 * FILENAME:    concurrent.c
 * DESCRIPTION: The functions that pthread calls.
 *
 * ENVIRONMENT:
 *     macOS Catalina 10.15.7
 *     Visual Studio Code 1.56.2
 * AUTHORS:
 *     Kevin Colour
 * DATES:
 *     Created: 08Oct2021
***************************************************************************/

#include "main.h"

int	shader_filter(void *ptr)
{
	t_thread_info	*thread;
	size_t			i, j;
	int				r, g, b;
	int				val;

	thread = ptr;
	i = thread->start;
	while (i < thread->stop)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			val = true_min(j, i, thread->points, thread->point_size);
			thread->vals[i * WIN_WIDTH + j] = val;
			set_color(val, &r, &g, &b);

			thread->pixels[i * WIN_WIDTH * BPP + j * BPP + 0] = r & 0xFF;
			thread->pixels[i * WIN_WIDTH * BPP + j * BPP + 1] = g & 0xFF;
			thread->pixels[i * WIN_WIDTH * BPP + j * BPP + 2] = b & 0xFF;
			thread->pixels[i * WIN_WIDTH * BPP + j * BPP + 3] = 0;
			j++;
		}
		i++;
	}
	return (0);
}