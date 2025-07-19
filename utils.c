#include "fractol.h"

int	exit_fractal(t_fractal *fractal)
{
	if (fractal->window)
		mlx_destroy_window(fractal->mlx, fractal->window);
	exit(0);
	return (0);
}

int	get_color(int iter, int max_iter, int shift)
{
	if (iter == max_iter)
		return (0x000000);
	return ((iter * 0xABCDEF >> shift) & 0xFFFFFF);
}

void	zoom(t_fractal *fractal, double zoom_factor, int x, int y)
{
	double	mouse_re = fractal->min_re + (double)x / fractal->width
		* (fractal->max_re - fractal->min_re);
	double	mouse_im = fractal->min_im + (double)y / fractal->height
		* (fractal->max_im - fractal->min_im);
	double	range_re = (fractal->max_re - fractal->min_re) * zoom_factor;
	double	range_im = (fractal->max_im - fractal->min_im) * zoom_factor;

	fractal->min_re = mouse_re - range_re / 2;
	fractal->max_re = mouse_re + range_re / 2;
	fractal->min_im = mouse_im - range_im / 2;
	fractal->max_im = mouse_im + range_im / 2;
}

void	set_random_julia(t_fractal *fractal)
{
	fractal->c_re = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
	fractal->c_im = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
}

void	change_iterations(t_fractal *fractal, int change)
{
	fractal->max_iter += change;
	if (fractal->max_iter < 10)
		fractal->max_iter = 10;
}
