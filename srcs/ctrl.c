/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mato <rde-mato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 16:25:23 by rde-mato          #+#    #+#             */
/*   Updated: 2017/02/10 19:48:22 by rde-mato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hud.h"
//
//void		scale(int keycode, t_fdf *e)
//{
//	if (keycode == PLUS)
//	{
//		if (e->ctrl.zoom < ZMMAX - 5)
//		{
//			e->ctrl.zoom += 5;
//			e->ctrl.h += 1;
//		}
//	}
//	else
//	{
//		if (e->ctrl.zoom > 5)
//		{
//			e->ctrl.zoom -= 5;
//			e->ctrl.h -= 1;
//		}
//	}
//	refreshimg(e);
//}
//
//void		scaleheight(int keycode, t_fdf *e)
//{
//	if (keycode == PUP)
//		e->ctrl.h++;
//	else
//		e->ctrl.h--;
//	refreshimg(e);
//}
//
//void		straf(int keycode, t_fdf *e)
//{
//	if (keycode == LEFT)
//		e->xoffset++;
//	else if (keycode == RIGHT)
//		e->xoffset--;
//	if (keycode == UP)
//		e->yoffset++;
//	else if (keycode == DOWN)
//		e->yoffset--;
//	refreshimg(e);
//}
//
//int			hook_mousemove(int x, int y, t_fdf *e)
//{
//	e->ctrl.mpx = x + WI / 4;
//	e->ctrl.mpy = y;
//	refreshimg(e);
//	return (0);
//}
//
//int			hook_keypressed(int keycode, t_fdf *e)
//{
//	e->ctrl.code = keycode;
//	if (keycode == ESC)
//		free4all(e);
//	else if (keycode > 122 && keycode < 127)
//		straf(keycode, e);
//	else if (keycode == PLUS || keycode == MINU)
//		scale(keycode, e);
//	e	colorselect(keycode, e);
//	else if (keycode == SPACE)
//		initstruct(e);
//	else if (keycode == 4)
//	{
//		e->helper = !e->helper;
//		refreshimg(e);
//	}
//	else if (keycode == TSB)
//		tsb(e);
//	return (0);
//}
//
//void		scaleheight(int keycode, t_fdf *e)
//{
//	if (keycode == PUP)
//		e->ctrl.h++;
//	else
//		e->ctrl.h--;
//	refreshimg(e);
//}
//
//void		straf(int keycode, t_fdf *e)
//{
//	if (keycode == LEFT)
//		e->xoffset++;
//	else if (keycode == RIGHT)
//		e->xoffset--;
//	if (keycode == UP)
//		e->yoffset++;
//	else if (keycode == DOWN)
//		e->yoffset--;
//	refreshimg(e);
//}
//
//int			hook_mousemove(int x, int y, t_fdf *e)
//{
//	e->ctrl.mpx = x + WI / 4;
//	e->ctrl.mpy = y;
//	refreshimg(e);
//	return (0);
//}
//
int			hook_keypressed(int keycode, t_hud *env)
{
	if (keycode == LEFT || keycode == RIGHT)
		heading(keycode, env);
	if (keycode == UP || keycode == DOWN)
		altitude(keycode, env);
	return (0);
}

void		altitude(int keycode, t_hud *env)
{
	if (keycode == UP)
		env->alt++;
	else
		env->alt--;
	refreshimg(env);
}

void		heading(int keycode, t_hud *env)
{
	if (keycode == RIGHT)
		env->head == 359 ? env->head = 0 : env->head++;
	else
		env->head == 0 ? env->head = 359 : env->head--;
	refreshimg(env);
}