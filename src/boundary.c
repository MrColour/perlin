/***************************************************************************
 * FILENAME:    boundary.c
 * DESCRIPTION: Boundary line of an object
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

void	draw_boundary(t_circle_arr *array, t_pellet *from, uint8_t *pixels)
{
	size_t	ix;
	int		x, y;

	ix = 0;
	while (ix < array->total)
	{
		x = from->location.x + array->x[ix] + WIN_WIDTH;
		x %= WIN_WIDTH;

		y = from->location.y + array->y[ix] + WIN_HEIGHT;
		y %= WIN_HEIGHT;

		if (array->vals[y * WIN_WIDTH + x] < 26)
		{
			from->vel.x += array->x[ix] * -.03;
			from->vel.y += array->y[ix] * -.03;
		}

		pixels[y * WIN_WIDTH * BPP + x * BPP + 0] = 0xFF;
		pixels[y * WIN_WIDTH * BPP + x * BPP + 1] = 0x0;
		pixels[y * WIN_WIDTH * BPP + x * BPP + 2] = 0x0;

		ix++;
	}

	if (from->vel.x < -2) { from->vel.x = -2; }
	if (from->vel.y < -2) { from->vel.y = -2; }
	if (from->vel.x > 2) { from->vel.x = 2; }
	if (from->vel.y > 2) { from->vel.y = 2; }
}