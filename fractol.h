#ifndef FRACTOL_H
#define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <math.h>

# define WIDTH 600
# define HEIGHT 600

typedef struct s_fractal
{
	void	*mlx;
	void	*window;
	void	*img;
	char	*image_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	int		width;
	int		height;

	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;

	double	zoom;
	double	offset_x;
	double	offset_y;

	int		max_iter;
	int		color_shift;

	double	c_re;
	double	c_im;

	char	*name;
}	t_fractal;

void	draw_fractal(t_fractal *fractal, char *name);
void	draw_mandelbrot(t_fractal *fractal);
void	draw_julia(t_fractal *fractal);
void	init_fractal(t_fractal *fractal, char *name);
void	init_mlx(t_fractal *fractal);

int		exit_fractal(t_fractal *fractal);
int		key_hook(int keycode, t_fractal *fractal);
int		mouse_hook(int button, int x, int y, t_fractal *fractal);
int		get_color(int iter, int max_iter, int shift);

void	zoom(t_fractal *fractal, double zoom_factor, int x, int y);
void	set_random_julia(t_fractal *fractal);
void	change_iterations(t_fractal *fractal, int change);

#endif
