/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/05 18:39:39 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/08 14:35:30 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// color palette
# define PALETTE_SIZE 256//don't touch
# define HUE_START 140// min is 0
# define HUE_END 360// max is 360 
# define HUE_SPREAD 10// the more you want the colors to be apart, min is 1
# define SAT 0.5 //min is 0, max is 1
# define VAL 0.8 //min is 0, max is 1
# define BREATH 1// min is 1, the bigger the faster, 
// disable breath by typing # define BREATH time
# define ESCP_RAD 4
# define MAX_FRACT 2 // max boundry of the fractal
# define MIN_FRACT -2 // min boundry of the fractal

// move speed + scroll speed
# define MOVE_SPEED 1 // amount of pixels it travels, please don't put 0
# define SCROLL_SPEED 1.5

// window // has to be square
# define WIDTH 1000
# define HEIGHT 1000

#endif
