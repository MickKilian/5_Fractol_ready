/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 02:13:12 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/07/19 03:57:14 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int	ft_drawmandelbrot(t_data *prm)
{
	prm->coord[1] = 0;
	while (prm->coord[1] < prm->img_height)
	{
		prm->coord[0] = 0;
		while (prm->coord[0] < prm->img_width)
		{
			ft_coord2cmplx(prm);
			prm->inset = !ft_isinmandelbrotset(prm);
			ft_assign_color(prm);
			ft_my_mlx_pixel_put(prm->img,
				prm->coord[0], prm->coord[1], prm->clr.val);
			prm->coord[0]++;
		}
		prm->coord[1]++;
	}
	return (0);
}

int	ft_isinmandelbrotset(t_data *prm)
{
	unsigned int	n;
	double			z0[2];
	double			z[2];

	n = 0;
	z[0] = 0;
	z[1] = 0;
	while (n++ < prm->mx_itr)
	{
		if (((z[0] * z[0]) + (z[1] * z[1])) > 4)
		{
			prm->stp_itr = n - 1;
			return (1);
		}
		z0[0] = z[0];
		z0[1] = z[1];
		z[0] = (z0[0] * z0[0]) - (z0[1] * z0[1]) + prm->cmplx[0];
		z[1] = (2 * z0[0] * z0[1]) + prm->cmplx[1];
	}
	return (0);
}
