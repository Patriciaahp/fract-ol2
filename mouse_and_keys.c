#include "fractol.h"

int	key_hook(int keycode, t_fractal *fractal)
{
	double shift = (fractal->max_re - fractal->min_re) * 0.05;

	if (keycode == 53 || keycode == 65307) // ESC
		exit_fractal(fractal);
	else if (keycode == 123) // flecha izquierda
	{
		fractal->min_re -= shift;
		fractal->max_re -= shift;
	}
	else if (keycode == 124) // flecha derecha
	{
		fractal->min_re += shift;
		fractal->max_re += shift;
	}
	else if (keycode == 126) // flecha arriba
	{
		fractal->min_im += shift;
		fractal->max_im += shift;
	}
	else if (keycode == 125) // flecha abajo
	{
		fractal->min_im -= shift;
		fractal->max_im -= shift;
	}
	draw_fractal(fractal, fractal->name);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_fractal *fractal)
{
	double zoom_factor;
	double mouse_re;
	double mouse_im;

	if (button == 4 || button == 5)
	{
		zoom_factor = (button == 4) ? 0.9 : 1.1;
		mouse_re = fractal->min_re + x * (fractal->max_re - fractal->min_re) / fractal->width;
		mouse_im = fractal->min_im + y * (fractal->max_im - fractal->min_im) / fractal->height;

		double new_width = (fractal->max_re - fractal->min_re) * zoom_factor;
		double new_height = (fractal->max_im - fractal->min_im) * zoom_factor;

		fractal->min_re = mouse_re - (mouse_re - fractal->min_re) * zoom_factor;
		fractal->max_re = fractal->min_re + new_width;

		fractal->min_im = mouse_im - (mouse_im - fractal->min_im) * zoom_factor;
		fractal->max_im = fractal->min_im + new_height;

		draw_fractal(fractal, fractal->name);
	}
	return (0);
}
