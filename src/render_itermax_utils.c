/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_itermax_utils.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/11 15:17:28 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/09 15:40:04 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_utils.h"
#include <math.h>

static int	pick_itersmax(double zoom);

int	get_itersmax(t_render *render)
{
	static double	last_zoom = 50;
	double			width;
	double			height;
	double			zoom;

	width = render->fract.r_end - render->fract.r_start;
	height = render->fract.i_end - render->fract.i_start;
	zoom = fmax(fabs(width), fabs(height));
	if (fabs(zoom - last_zoom) < 1e-12)
		return (render->fract.iter_max);
	last_zoom = zoom;
	render->fract.iter_max = pick_itersmax(zoom);
	return (render->fract.iter_max);
}

static int	pick_itersmax(double zoom)
{
	return (fmaxf((log10(1 / zoom) * 15) + 25, 50));
}

// #include <stdio.h>
// int main(void)
// {
// 	double	zoom = 0.00000000001;
// 	int		iters_max = 0;
//
// 	iters_max = calc_itersmax(zoom);
// 	printf("zoom: %f, iter: %i\n", zoom, iters_max);
//
// 	// same zoom
// 	iters_max = calc_itersmax(zoom);
// 	printf("zoom: %f, iter: %i\n", zoom, iters_max);
//
// 	zoom = 0.00001;
// 	iters_max = calc_itersmax(zoom);
// 	printf("zoom: %f, iter: %i\n", zoom, iters_max);
// }