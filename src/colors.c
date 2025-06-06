/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/07 17:59:21 by kclaes        #+#    #+#                 */
/*   Updated: 2025/06/07 18:41:58 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stddef.h>
#include <stdint.h>

static void	generate_palette(uint32_t palette[]);
static void	get_init_hsv(double *hue, double *sat, double *val, \
						double *hue_spread);

uint32_t get_color(int iters, int z)
{
	static uint32_t palette[PALETTE_SIZE] = {0};
	
	if (palette[0] == 0)
		generate_palette(palette);
}

static void	generate_palette(uint32_t palette[])
{
	double	hue;
	double	hue_spread;
	double	sat;
	double	val;
	int		i;

	hue = HUE_START;
	sat = SAT;
	val = VAL;
	get_init_hsv(&hue, &sat, &val, &hue_spread);
	while (i < PALETTE_SIZE)
	{
		palette[i++] = hsv_to_rgb(hue, sat, val);
		hue += hue_spread;
	}
}
