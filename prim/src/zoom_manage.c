/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_manage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 05:31:14 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/07/19 03:57:59 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int	ft_update_zoom_level(t_data *prm, double min_re,
		double max_re, double min_im)
{
	prm->min_re = min_re;
	prm->max_re = max_re;
	prm->min_im = min_im;
	prm->max_im = prm->min_im + (prm->max_re - prm->min_re)
		* (prm->img_height / prm->img_width);
	prm->re_factor = (prm->max_re - prm->min_re) / (prm->img_width - 1);
	prm->im_factor = (prm->max_im - prm->min_im) / (prm->img_height - 1);
	return (0);
}

int	ft_zoom(t_data *prm)
{
	if (prm->zoom_factor != 1 && prm->zoom_now == prm->zoom_factor)
		prm->zoom_total += 1;
	else if (prm->zoom_factor != 1 && prm->zoom_now != 1)
		prm->zoom_total -= 1;
	ft_printf("Zoom : x2^%d\n", prm->zoom_total - 1);
	ft_update_zoom_level(prm, prm->cmplx[0]
		- (prm->max_re - prm->min_re) / 2 / prm->zoom_now,
		prm->cmplx[0] + (prm->max_re - prm->min_re) / 2 / prm->zoom_now,
		prm->cmplx[1] - (prm->max_im - prm->min_im) / 2 / prm->zoom_now);
	ft_image_update(prm);
	ft_assign_coord(prm, prm->img_width / 2, prm->img_height / 2);
	return (0);
}
