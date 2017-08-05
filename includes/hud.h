#ifndef HUD_H
# define HUD_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "../includes/mlx.h"
# include "../includes/libft.h"

# define WHI        0x00FFFFFF
# define RED        0x00FF0000
# define GRE        0x0000FF00
# define BLU        0x000000FF
# define C1         0x00550000
# define C2         0x00AA0000
# define C4         0x00005500
# define C5         0x0000AA00
# define C7         0x00000055
# define C8         0x000000AA

#ifdef linux
	# include "/usr/include/X11/keysymdef.h"
	# define ESC        0xff1b
	# define UP         0xff52
	# define DOWN       0xff54
	# define RIGHT      0xff53
	# define LEFT       0xff51
	# define PLUS       0x0070
	# define MINU       0x0069
	# define PUP        0xff55
	# define PDN        0xff56
	# define SPACE      0x0072
	# define TSB        0x006d
#else
	# define ESC        53
	# define UP         126
	# define DOWN       125
	# define RIGHT      124
	# define LEFT       123
	# define PLUS       24
	# define MINU       27
	# define PUP        116
	# define PDN        121
	# define SPACE      49
	# define TSB        46
#endif

# define NAME       "HUD debug"
# define WI         360 //size of pixel matrix MAX7456
# define HE         288

typedef struct	s_ctrl
{
	int			mpx;
	int			mpy;
	int			code;
	int			zoom;
	int			h;
}				t_ctrl;

typedef struct	s_l
{
	int			x;
	int			y;
	int			x0;
	int			y0;
	int			x1;
	int			y1;
	int			color;
	int			dx;
	int			dy;
	int			xinc;
	int			yinc;
}				t_l;

typedef struct	s_hud
{
	char		*title;
	void		*mlx;
	void		*win;
	void		*img;
	char		*pixel_img;
	int			bpp;
	int			s_line;
	int			ed;
	t_ctrl		ctrl;
	t_l			l;
	int			alt;
	int			head;
}				t_hud;

/*
**              ctrl.c
*/
void			altitude(int keycode, t_hud *env);
void			heading(int keycode, t_hud *env);
//void			scaleheight(int keycode, t_fdf *e);
//void			straf(int keycode, t_fdf *e);
//int				hook_mousemove(int x, int y, t_fdf *e);
int				hook_keypressed(int keycode, t_hud *env);

///*
//**              drawline.c
//*/
//void			drawlineh(t_fdf *e);
//void			drawlinev(t_fdf *e);
//void			drawline(t_fdf *e);

/*
**              drawmap.c							
*/
void			drawhud(t_hud *env);

/*
**              image.c
*/
void			mlx_pixel_put_image(t_hud *env);
void			clearimage(t_hud *env);
void			refreshimg(t_hud *env);

/*
**              main.c
*/

int				free4all(t_hud *env);
void			initstruct(t_hud *env);
void			initmlx(t_hud *env);

#endif
