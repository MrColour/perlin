/***************************************************************************
 * FILENAME:    pellets.c
 * DESCRIPTION: Functions about pellets
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

void	update_pellets(t_pellet *pellets, size_t size)
{
	size_t	ix;

	ix = 0;
	while (ix < size)
	{
		pellets[ix].locationf.x += pellets[ix].vel.x;
		pellets[ix].locationf.y += pellets[ix].vel.y;

		pellets[ix].location.x = pellets[ix].locationf.x;
		pellets[ix].location.x %= WIN_WIDTH;
		pellets[ix].location.x += WIN_WIDTH;
		pellets[ix].location.x %= WIN_WIDTH;
		pellets[ix].location.y = pellets[ix].locationf.y;
		pellets[ix].location.y %= WIN_HEIGHT;
		pellets[ix].location.y += WIN_HEIGHT;
		pellets[ix].location.y %= WIN_HEIGHT;

		ix++;
	}
}