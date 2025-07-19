#include "fractol.h"

void draw_mandelbrot(t_fractal *f)
{
	int x, y, iter;
	double zx, zy, tmp, cx, cy;

	y = 0;
	while (y < f->height)
	{
		x = 0;
		while (x < f->width)
		{
			cx = f->min_re + x * (f->max_re - f->min_re) / f->width;
			cy = f->min_im + y * (f->max_im - f->min_im) / f->height;
			zx = 0;
			zy = 0;
			iter = 0;
			while (zx * zx + zy * zy < 4 && iter < f->max_iter)
			{
				tmp = zx * zx - zy * zy + cx;
				zy = 2 * zx * zy + cy;
				zx = tmp;
				iter++;
			}
			int color = (iter == f->max_iter) ? 0x000000 : iter * 0x001122;
			((int *)f->image_addr)[y * f->width + x] = color;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->window, f->img, 0, 0);
}
