/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/05 18:18:34 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/09 15:47:56 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "fractol_utils.h"
#include "colors.h"
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	t_nbr_i	const_i;
	short	fract_type;
	int		exit_status;

	const_i.imag = 0;
	const_i.real = 0;
	if (argc == 2 && ft_streq("mandelbrot", argv[1], true))
	{
		fract_type = MANDELBROT;
	}
	else if (argc == 4 && ft_streq("julia", argv[1], true) \
&& valid_real(argv[2]) && valid_imag(argv[3]))
	{
		const_i = julia_parse(argv[2], argv[3]);
		fract_type = JULIA;
	}
	else
		return (ft_printf(COLOR_BRIGHT_MAGENTA EXPECTED_INPT COLOR_RESET), 1);
	exit_status = render(fract_type, const_i);
	exit(exit_status);
}
