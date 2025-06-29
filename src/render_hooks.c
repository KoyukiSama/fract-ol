/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_hooks.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/11 19:19:41 by kclaes        #+#    #+#                 */
/*   Updated: 2025/06/29 21:32:52 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_utils.h"
#include "fractol.h"
#include "MLX42.h"
#include "fractol_move_utils.h"

// render_hooks.c
void	scroll_hook(double xdelta, double ydelta, void *render)
{
	(void) xdelta;
	zoom((t_render *) render, ydelta);
	render_fract((t_render *) render);
}

void	key_hook(mlx_key_data_t keydata, void *render)
{
	if (keydata.key == MLX_KEY_X)
	{
		close_hook(render);
	}
}

void	resize_hook(int32_t width, int32_t height, void *render)
{
	if (height > width)
		height = width;
	else
		width = height;
	mlx_resize_image(((t_render *) render)->img, width, height);
	render_fract((t_render *) render);
}

void	close_hook(void *render)
{
	mlx_close_window(((t_render *) render)->mlx);
}
