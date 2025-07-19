#include "fractol.h"

void draw_julia(t_fractal *fractal)
{
	int x, y, iter, color;
	double zx, zy, tmp;

	y = 0;
	while (y < fractal->height)
	{
		x = 0;
		while (x < fractal->width)
		{
			zx = (x - fractal->width / 2.0) / (0.5 * fractal->zoom * fractal->width) + fractal->offset_x;
			zy = (y - fractal->height / 2.0) / (0.5 * fractal->zoom * fractal->height) + fractal->offset_y;
			iter = 0;
			while ((zx * zx + zy * zy) <= 4 && iter < fractal->max_iter)
			{
				tmp = zx * zx - zy * zy + fractal->c_re;
				zy = 2.0 * zx * zy + fractal->c_im;
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
