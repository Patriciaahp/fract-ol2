#include "fractol.h"

void init_mlx(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	fractal->window = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, "Fract-ol");
	fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	fractal->image_addr = mlx_get_data_addr(fractal->img, &fractal->bits_per_pixel,
											&fractal->line_length, &fractal->endian);
}

void init_fractal(t_fractal *fractal, char *name)
{
	fractal->width = WIDTH;
	fractal->height = HEIGHT;

	fractal->min_re = -2.0;
	fractal->max_re = 2.0;
	fractal->min_im = -2.0;
	fractal->max_im = 2.0;

	fractal->zoom = 1.0;
	fractal->offset_x = 0.0;
	fractal->offset_y = 0.0;

	fractal->max_iter = 100;
	fractal->color_shift = 0;

	fractal->c_re = -0.7;
	fractal->c_im = 0.27015;

	fractal->name = name;
}
