#include "fractol.h"

int key_hook(int keycode, t_fractal *fractal)
{
	if (keycode == 53 || keycode == 65307) // ESC
		exit_fractal(fractal);
	else if (keycode == 69 || keycode == 61) // +
		change_iterations(fractal, 10);
	else if (keycode == 78 || keycode == 45) // -
		change_iterations(fractal, -10);
	else if (keycode == 123) // left
		fractal->offset_x -= 30 / fractal->zoom;
	else if (keycode == 124) // right
		fractal->offset_x += 30 / fractal->zoom;
	else if (keycode == 125) // down
		fractal->offset_y += 30 / fractal->zoom;
	else if (keycode == 126) // up
		fractal->offset_y -= 30 / fractal->zoom;
	draw_fractal(fractal, fractal->name);
	return (0);
}

int mouse_hook(int button, int x, int y, t_fractal *fractal)
{
	if (button == 4 || button == 5)
	{
		double factor = (button == 4) ? 0.8 : 1.2;
		zoom(fractal, factor, x, y);
		draw_fractal(fractal, fractal->name);
	}
	return (0);
}
