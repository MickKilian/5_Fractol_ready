/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 01:16:17 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/07/19 04:41:49 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	ft_bzero(void *ptr, const size_t size)
{
	size_t	i;
	char	*str;

	if (!ptr)
		return ;
	i = 0;
	str = (char *)ptr;
	while (i < size)
	{
		str[i] = 0;
		i++;
	}
}

int	ft_init_data_0(t_data *prm)
{
	prm->prtfct = 1000000000;
	prm->nb_handled_sets = 4;
	prm->set_ptr[0] = ft_drawmandelbrot;
	prm->set_ptr[1] = ft_drawjulia;
	prm->set_ptr[2] = ft_drawnewton;
	prm->set_ptr[3] = ft_drawmandelbrot_mod;
	prm->handled_sets[0] = "mandelbrot";
	prm->handled_sets[1] = "julia";
	prm->handled_sets[2] = "newton";
	prm->handled_sets[3] = "mandelbrot_mod";
	prm->c[0] = -0.82;
	prm->c[1] = -0.19;
	prm->mx_itr = 50;
	prm->inc_itr = 10;
	return (0);
}

int	ft_init_data_1(t_data *prm)
{
	prm->win_width = 1000;
	prm->win_height = 1000;
	prm->img_width = prm->win_width;
	prm->img_height = prm->win_height;
	ft_bzero(&prm->img, sizeof(t_img));
	prm->zoom_init[0] = (prm->set != 2 && prm->set != 3) * -2.5
		+ !(prm->set != 2 && prm->set != 3) * -2.0;
	prm->zoom_init[1] = (prm->set != 2 && prm->set != 3) * 1.5
		+ !(prm->set != 2 && prm->set != 3) * 2.0;
	prm->zoom_init[2] = -2.0;
	ft_update_zoom_level(prm, prm->zoom_init[0], prm->zoom_init[1],
		prm->zoom_init[2]);
	prm->inset = 0;
	prm->zoom_factor = 2;
	prm->zoom_now = 1;
	prm->zoom_total = 1;
	prm->coord[0] = prm->win_width / 2;
	prm->coord[1] = prm->win_height / 2;
	ft_assign_coord(prm, prm->win_width / 2, prm->win_height / 2);
	prm->move[0] = prm->win_width / 2;
	prm->move[1] = prm->win_height / 2;
	prm->mouse[0] = 0;
	prm->mouse[1] = 0;
	ft_init_data_2(prm);
	return (0);
}

int	ft_init_data_2(t_data *prm)
{
	if (prm->set != 2)
	{
		prm->c[0] = 0;
		prm->c[1] = 0;
	}
	if (prm->set != 3)
		prm->clr_md = 1;
	ft_bzero(&prm->clr, sizeof(t_img));
	prm->clr_md1[1] = 1;
	prm->clr_md1[2] = 0;
	prm->clr_md1[3] = 0;
	prm->hm[0] = 1;
	prm->hm[1] = 0;
	prm->hm[2] = 1;
	prm->hm[3] = 1;
	prm->tol = 0.000001;
	prm->newton_roots[0][0] = 1.0;
	prm->newton_roots[0][1] = 0.0;
	prm->newton_roots[1][0] = -.5;
	prm->newton_roots[1][1] = 0.866025404;
	prm->newton_roots[2][0] = -.5;
	prm->newton_roots[2][1] = -0.866025404;
	prm->newton_root = 0;
	return (0);
}

int	ft_init_mlxwinimg(t_data *prm)
{
	prm->mlx_ptr = mlx_init();
	if (!prm->mlx_ptr)
		return (1);
	prm->win_ptr = mlx_new_window(prm->mlx_ptr,
			prm->win_width, prm->win_height, "Fract'ol");
	if (!prm->win_ptr)
		return (1);
	if (ft_image_create(prm))
		return (1);
	return (0);
}
