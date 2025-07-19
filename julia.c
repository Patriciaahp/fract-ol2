#include "fractol.h"

void draw_julia(t_fractal *f)
{
	int x, y, iter;
	double zx, zy, tmp;

	y = 0;
	while (y < f->height)
	{
		x = 0;
		while (x < f->width)
		{
			zx = f->min_re + x * (f->max_re - f->min_re) / f->width;
			zy = f->min_im + y * (f->max_im - f->min_im) / f->height;
			iter = 0;
			while ((zx * zx + zy * zy) < 4 && iter < f->max_iter)
			{
				tmp = zx * zx - zy * zy + f->c_re;
				zy = 2 * zx * zy + f->c_im;
				zx = tmp;
				iter++;
			}
			int color = (iter == f->max_iter) ? 0x000000 : iter * 0x330033;
			((int *)f->image_addr)[y * f->width + x] = color;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->window, f->img, 0, 0);
}
