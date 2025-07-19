#include "fractol.h"
#include "libft.h"

void draw_fractal(t_fractal *fractal, char *name)
{
	if (!ft_strncmp(name, "mandelbrot", 11))
		draw_mandelbrot(fractal);
	else if (!ft_strncmp(name, "julia", 5))
		draw_julia(fractal);
	else
	{
		ft_putendl_fd("Invalid fractal name", 2);
		exit(1);
	}
}
