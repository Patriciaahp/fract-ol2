#include "fractol.h"
#include "libft.h"

int main(int argc, char **argv)
{
	t_fractal fractal;

	if (argc != 2)
	{
		write(2, "Usage: ./fractol <mandelbrot|julia>\n", 36);
		return (1);
	}

	init_fractal(&fractal, argv[1]);
	init_mlx(&fractal);

	mlx_key_hook(fractal.window, key_hook, &fractal);
	mlx_mouse_hook(fractal.window, mouse_hook, &fractal);
	mlx_hook(fractal.window, 17, 0, exit_fractal, &fractal);

	draw_fractal(&fractal, fractal.name);
	mlx_loop(fractal.mlx);
	return (0);
}
