/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 18:08:04 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/07/19 05:30:48 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_img
{
	void	*img_ptr;
	char	*img_addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_color
{
	int		val;
	int		trgb[4];
	double	thsv[4];
}	t_color;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_img			img;
	int				win_width;
	int				win_height;
	int				img_width;
	int				img_height;
	double			min_re;
	double			max_re;
	double			min_im;
	double			max_im;
	double			re_factor;
	double			im_factor;
	int				set;
	char			*handled_sets[15];
	int				nb_handled_sets;
	double			c[2];
	int				prtfct;
	double			zoom_factor;
	double			zoom_now;
	int				zoom_total;
	int				ctrl_zoom;
	double			zoom_init[3];
	double			focus[2];
	int				coord[2];
	double			cmplx[2];
	int				clr_md;
	t_color			clr;
	double			clr_lvl;
	int				clr_sch[11];
	int				clr_md1[4];
	double			hm[4];
	unsigned int	mx_itr;
	unsigned int	inc_itr;
	unsigned int	max_newton;
	unsigned int	stp_itr;
	int				inset;
	int				move[2];
	int				mouse[2];
	double			tol;
	double			newton_roots[3][2];
	int				newton_root;
	int				(*set_ptr[4])(struct s_data *prm);
} t_data;

typedef struct s_clcai
{
	int	n;
	int	sign;
	int	countzero;
	int	len;
	int	i;
}	t_clcai;

typedef struct s_clcnewton
{
	unsigned int	n;
	unsigned int	i;
	double			z[2];
	double			f1[2];
	double			f2[2];
}	t_clcnewton;

enum
{
	ON_MOUSELEFTCLICK = 1,
	ON_MOUSEUP = 4,
	ON_MOUSEDOWN = 5,
	ON_MOUSEMOVE = 6,
	ON_DESTROY = 65307,
	ON_ARROWLEFT = 65361,
	ON_ARROWUP = 65362,
	ON_ARROWRIGHT = 65363,
	ON_ARROWDOWN = 65364
};

enum
{
	RED = 1,
	GREEN,
	BLUE
};
// fractol.c
int		ft_fractol(int argc, char **argv);
int		ft_exit(t_data *prm);

// check_input_1.c
int		ft_checkinput(int argc, char **argv, t_data *prm);
int		check_argv1(int argc, char **argv, t_data *prm);
int		check_argv2(int argc, char **argv, t_data *prm);
int		check_argv4(int argc, char **argv, t_data *prm);
void	ft_listsets(void);

// check_input_2.c
int		check_argv6(int argc, char **argv, t_data *prm);
int		check_argv7(int argc, char **argv, t_data *prm);
int		ft_errorprompt(void);

// edit_image.c
int		ft_image_create(t_data *prm);
int		ft_image_update(t_data *prm);
int		ft_my_mlx_pixel_put(t_img img, int x, int y, int color);

// initialize.c
void	ft_bzero(void *ptr, const size_t size);
int		ft_init_data_0(t_data *prm);
int		ft_init_data_1(t_data *prm);
int		ft_init_data_2(t_data *prm);
int		ft_init_mlxwinimg(t_data *prm);

// coord_mamnage.c
int		ft_assign_coord(t_data *prm, int x, int y);
int		ft_assign_cmplx(t_data *prm, long double x, long double y);
int		ft_coord2cmplx(t_data *prm);
int		ft_cmplx2coord(t_data *prm);

// mandelbrot.c
int		ft_drawmandelbrot(t_data *prm);
int		ft_isinmandelbrotset(t_data *prm);

// mandelbrot_mod.c
int		ft_drawmandelbrot_mod(t_data *prm);
int		ft_isinmandelbrot_modset(t_data *prm);

// julia.c
int		ft_drawjulia(t_data *prm);
int		ft_isinjuliaset(t_data *prm);

// newton.c
int		ft_drawnewton(t_data *prm);
int		ft_isinnewtonset(t_data *prm, t_clcnewton *var_newton);
int		ft_function(t_clcnewton *var_newton);

// color_convert.c
int		ft_trgb2val(t_color *color);
int		ft_val2trgb(t_color *color);
int		ft_thsv2trgb(t_color *c);

// events.c
int		key_hook(int keycode, t_data *prm);
int		mouse_hook(int keycode, int x, int y, t_data *prm);
int		mouse_leftclick(t_data *prm, int x, int y);
int		key_thsv(t_data *prm, int keycode);
int		key_thsv_2(t_data *prm, int keycode);


// events_key_actions_1.c
int		key_0(t_data *prm, int keycode);
int		key_1to6(t_data *prm, int keycode);
int		key_7(t_data *prm, int keycode);
int		key_rsl(t_data *prm, int keycode);
int		key_arrows(t_data *prm, int keycode);

// events_key_actions_1.c
int		key_const(t_data *prm, int keycode);

// zoom_manage.c
int		ft_update_zoom_level(t_data *prm, double min_re, double max_re, double min_im);
int		ft_zoom(t_data *prm);

// color_manage.c
int		ft_assign_color(t_data *prm);
int		ft_assign_color_simple(t_data *prm);
int		ft_assign_color_setmode(t_data *prm);
int		ft_assign_color_thsv(t_data *prm);
int		ft_assign_color_newton(t_data *prm);

// color_sets.c
int		ft_get_color_set(t_data *prm);
int		ft_set_clr_md_4(t_data *prm);
int		ft_set_clr_md_5(t_data *prm);
int		ft_set_clr_md_6(t_data *prm);

// utils_1.c
double	ft_abs(double a);
double	ft_modulo(double x, double y);

// utils_2.c
int		ft_getsize(int n);
int		ft_findmin(int a, int b);
int		ft_findmax(int a, int b);

// utils_3.c
int		ft_strcmp(const char *s1, const char *s2);

// utils_4.c
size_t	ft_strlen(const char *s);
int		ft_power(int p);

// utils_5.c
int		ft_atoi(char *nptr);
t_clcai	ft_atoi_b(char *nptr, t_clcai clc);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s);

// printf.c
int		ft_printf(const char *format, ...);
int		ft_checkspecifier(int c, va_list ptr);

// printf_utils_1.c
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_puthexa_min(unsigned int n);
int		ft_puthexa_maj(unsigned int n);

// printf_utils_2.c
int		ft_putpointerhexa(unsigned long int n);
int		ft_putpointer(unsigned long int n);
int		ft_putitoa(int n);
int		ft_putunsigned(unsigned int n);

#endif
