/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 18:27:04 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/07/19 03:55:23 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int	ft_image_create(t_data *prm)
{
	prm->img.img_ptr = mlx_new_image(prm->mlx_ptr,
			prm->img_width, prm->img_height);
	if (!prm->img.img_ptr)
		return (1);
	prm->img.img_addr = mlx_get_data_addr(prm->img.img_ptr,
			&prm->img.bpp, &prm->img.line_length, &prm->img.endian);
	if (!prm->img.img_addr)
		return (1);
	return (0);
}

int	ft_image_update(t_data *prm)
{
	prm->set_ptr[prm->set - 1](prm);
	mlx_put_image_to_window(prm->mlx_ptr, prm->win_ptr,
		prm->img.img_ptr, 0, 0);
	return (0);
}

int	ft_my_mlx_pixel_put(t_img img, int x, int y, int color)
{
	char	*dst;

	dst = img.img_addr + (y * img.line_length + x * (img.bpp / 8));
	if (!dst)
		return (1);
	*(unsigned int *)dst = color;
	return (0);
}
