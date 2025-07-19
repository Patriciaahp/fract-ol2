#include "fractol.h"

void draw_mandelbrot(t_fractal *fractal)
{
	int x, y, iter, color;
	double zx, zy, tmp, cx, cy;

	y = 0;
	while (y < fractal->height)
	{
		x = 0;
		while (x < fractal->width)
		{
			cx = (x - fractal->width / 2) / (0.5 * fractal->zoom * fractal->width) + fractal->offset_x;
			cy = (y - fractal->height / 2) / (0.5 * fractal->zoom * fractal->height) + fractal->offset_y;
			zx = 0;
			zy = 0;
			iter = 0;
			while (zx * zx + zy * zy < 4 && iter < fractal->max_iter)
			{
				tmp = zx * zx - zy * zy + cx;
				zy = 2 * zx * zy + cy;
				zx = tmp;
				iter++;
			}
			color = get_color(iter, fractal->max_iter, fractal->color_shift);
			((int *)fractal->image_addr)[y * fractal->width + x] = color;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->img, 0, 0);
}
