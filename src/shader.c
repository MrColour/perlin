/***************************************************************************
 * FILENAME:    shader.c
 * DESCRIPTION: Functions that are done for every pixel.
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

int	true_min(const int x, const int y, const t_pellet *points, const size_t amount)
{
	size_t	ix;
	int		dx, dy;

	int		dx1, dx2, dy1, dy2;
	long long	min;

	ix = 0;
	min = SDL_MAX_SINT64;
	if (amount == 0) { return (0); }
	while (ix < amount)
	{
		dx = x - points[ix].location.x;
		dx1 = dx - WIN_WIDTH;
		dx1 *= dx1;
		dx2 = dx + WIN_WIDTH;
		dx2 *= dx2;
		dx = dx * dx;

		dy = y - points[ix].location.y;
		dy1 = dy - WIN_HEIGHT;
		dy1 *= dy1;
		dy2 = dy + WIN_HEIGHT;
		dy2 *= dy2;
		dy = dy * dy;

		min = SDL_min(min, dx + dy);
		min = SDL_min(min, dx1 + dy);
		min = SDL_min(min, dx2 + dy);

		min = SDL_min(min, dx + dy1);
		min = SDL_min(min, dx + dy2);

		ix++;
	}
	return (SDL_sqrt(min));
}
