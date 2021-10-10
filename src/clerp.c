/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clerp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 03:20:28 by home              #+#    #+#             */
/*   Updated: 2021/10/08 19:10:04 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/**
* \brief Linear interpolates between min and max
* \param min the min value
* \param max the max value
* \param t propotion of interpolation, value between 0 and tmax
* \param tmax the max value t can take
*
* \brief
* Does not handle overflow or underflows well. BEWARE!
*/
int	lerp(int min, int max, int t, int tmax)
{
	return (min + ((max - min) * t) / tmax);
}

void	ctoRGB(int color, int *r, int *g, int *b)
{
	*r = (color >> 16) & 0xFF;
	*g = (color >>  8) & 0xFF;
	*b = (color >>  0) & 0xFF;
}

int		clerp(int color1, int color2, int t, int tmax)
{
	int	r1, g1, b1;
	int	r2, g2, b2;

	int	r_res, g_res, b_res;
	int result;

	ctoRGB(color1, &r1, &g1, &b1);
	ctoRGB(color2, &r2, &g2, &b2);

	r_res = lerp(r1, r2, t, tmax);
	g_res = lerp(g1, g2, t, tmax);
	b_res = lerp(b1, b2, t, tmax);

	result = (r_res << 16) |  (g_res <<  8) | (b_res <<  0);
	return (result);
}

void	set_color(int val, int *r, int *g, int *b)
{
	int result;
	// const double	scale = 15;
	const double	scale = 1;

	result = 0;
	if (val < (17 * scale))
		result = clerp(0xFFFFFF, 0xD700E4, val - (0 * scale), 17 * scale);
	else if (val < (43 * scale))
		result = clerp(0xD700E4, 0x5CC09B, val - (17 * scale), 26 * scale);
	else if (val < (121 * scale))
		result = clerp(0x5CC09B, 0x000000, val - (43 * scale), 78 * scale);
	else if (val < (256 * scale))
		result = clerp(0x000000, 0x000000, val - (121 * scale), 135 * scale);
	ctoRGB(result, r, g, b);
}





