/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mato <rde-mato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 19:40:43 by rde-mato          #+#    #+#             */
/*   Updated: 2017/02/10 19:50:11 by rde-mato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hud.h"

int			free4all(t_hud *env)
{
	free(env->mlx);
	free(env->win);
	free(env->img);
	free(env->pixel_img);
	exit(0);
	return (666);
}

void		initstruct(t_hud *env)
{
	env->alt = 100;
	env->head = 180;
	refreshimg(env);
}

void		initmlx(t_hud *env)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WI, HE, NAME);
	env->img = mlx_new_image(env->mlx, WI, HE);
	env->pixel_img = mlx_get_data_addr(env->img, &(env->bpp), &(env->s_line), &(env->ed));
}

int			main(int ac, char **av)
{
	t_hud	env;

	initmlx(&env);
	initstruct(&env);
	mlx_key_hook(env.win, hook_keypressed, &env);
	mlx_loop(env.mlx);
	return (0);
}
