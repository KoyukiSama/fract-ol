/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colors.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/05 19:34:16 by kclaes        #+#    #+#                 */
/*   Updated: 2025/06/05 19:34:32 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# define COLOR_RESET "\033[0m"

# define COLOR_BLACK "\033[30m"
# define COLOR_RED "\033[31m"
# define COLOR_GREEN "\033[32m"
# define COLOR_YELLOW "\033[33m"
# define COLOR_BLUE "\033[34m"
# define COLOR_MAGENTA "\033[35m"
# define COLOR_CYAN "\033[36m"
# define COLOR_WHITE "\033[37m"

# define COLOR_BRIGHT_BLACK "\033[90m"
# define COLOR_BRIGHT_RED "\033[91m"
# define COLOR_BRIGHT_GREEN "\033[92m"
# define COLOR_BRIGHT_YELLOW "\033[93m"
# define COLOR_BRIGHT_BLUE "\033[94m"
# define COLOR_BRIGHT_MAGENTA "\033[95m"
# define COLOR_BRIGHT_CYAN "\033[96m"
# define COLOR_BRIGHT_WHITE "\033[97m"

# define BG_BLACK "\033[40m"
# define BG_RED "\033[41m"
# define BG_GREEN "\033[42m"
# define BG_YELLOW "\033[43m"
# define BG_BLUE "\033[44m"
# define BG_MAGENTA "\033[45m"
# define BG_CYAN "\033[46m"
# define BG_WHITE "\033[47m"

# define BG_BRIGHT_BLACK "\033[100m"
# define BG_BRIGHT_RED "\033[101m"
# define BG_BRIGHT_GREEN "\033[102m"
# define BG_BRIGHT_YELLOW "\033[103m"
# define BG_BRIGHT_BLUE "\033[104m"
# define BG_BRIGHT_MAGENTA "\033[105m"
# define BG_BRIGHT_CYAN "\033[106m"
# define BG_BRIGHT_WHITE "\033[107m"

# define STYLE_BOLD "\033[1m"
# define STYLE_DIM "\033[2m"
# define STYLE_UNDERLINE "\033[4m"
# define STYLE_BLINK "\033[5m"
# define STYLE_REVERSE "\033[7m"
# define STYLE_HIDDEN "\033[8m"

#endif
