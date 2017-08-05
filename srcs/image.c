/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mato <rde-mato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 18:22:54 by rde-mato          #+#    #+#             */
/*   Updated: 2017/01/30 16:16:45 by rde-mato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hud.h"

void		mlx_pixel_put_image(t_hud *env)
{
	int		i;

	i = ((env->l.x * env->bpp / 8) + (env->l.y * env->s_line));
	if (i >= 0 && i < env->s_line * HE && env->l.x >= 0 && env->l.x < WI)
	{
		env->pixel_img[i] = env->l.color;
		env->pixel_img[++i] = env->l.color >> 8;
		env->pixel_img[++i] = env->l.color >> 16;
	}
}

void		clearimage(t_hud *env)
{
	int		i;

	i = -1;
	while (++i < WI * HE * 4)
		env->pixel_img[i] = 127;
}

void		refreshimg(t_hud *env)
{
	clearimage(env);
	drawhud(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	mlx_string_put(env->mlx, env->win, 10, 10, WHI, ft_itoa(env->alt));
}
