/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_fract.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/18 14:27:51 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/09 15:43:50 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_utils.h"
#include "fractol.h"

static void	get_scale_init_nbri(t_render render, double *scale_width,\
								double *scale_height, t_nbr_i *nbr_i);
static void	render_pixel(t_render *render, t_nbr_i nbr_i, t_nbr_i c,\
							t_pixel_curr px);

void	render_fract(t_render *render)
{
	double			scale_width;
	double			scale_height;
	t_nbr_i			nbr_i;
	t_pixel_curr	px;

	px.x = 0;
	px.y = 0;
	get_scale_init_nbri((*render), &scale_width, &scale_height, &nbr_i);
	while (px.y <= (*render).img->height)
	{
		while (px.x <= (*render).img->width)
		{
			render_pixel(render, nbr_i, (*render).fract.c, px);
			nbr_i.real += scale_width;
			px.x++;
		}
		px.y++;
		px.x = 0;
		nbr_i.imag += scale_height;
		nbr_i.real = (*render).fract.r_start;
	}
}

static void	render_pixel(t_render *render, t_nbr_i nbr_i, t_nbr_i c,\
							t_pixel_curr px)
{
	int				in_fractol;
	int				iters;
	static double	time = 0;

	if (px.x < 0 || px.y < 0 || px.x >= WIDTH || px.y >= HEIGHT)
		return ;
	in_fractol = 0;
	if ((*render).fract.type == MANDELBROT)
		in_fractol = is_mandelbrot(nbr_i, get_itersmax(render), &iters);
	else if ((*render).fract.type == JULIA)
		in_fractol = is_julia(nbr_i, c, get_itersmax(render), &iters);
	else
		close_hook(render);
	if (!in_fractol)
	{
		if (px.x == 0 && px.y == 0)
			time = mlx_get_time();
		mlx_put_pixel((*render).img, px.x, px.y, \
get_color(iters, *render, time));
	}
	else
		mlx_put_pixel((*render).img, px.x, px.y, 0x191970);
}

static void	get_scale_init_nbri(t_render render, double *scale_width,\
								double *scale_height, t_nbr_i *nbr_i)
{
	(*scale_width) = (render.fract.r_end - render.fract.r_start) \
/ render.img->width;
	(*scale_height) = (render.fract.i_end - render.fract.i_start) \
/ render.img->height;
	(*nbr_i).real = render.fract.r_start;
	(*nbr_i).imag = render.fract.i_start;
}
