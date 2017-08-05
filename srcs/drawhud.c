#include "../includes/hud.h"
#include "../includes/charset.h"

void	printchar(int posx, int posy, unsigned char n, t_hud *env)
{
	int x = -1;
	int y = -1;
	int i = -1;
	int j = 0;
	
	posx = posx * 12;
	posy = posy * 18;
	while (++y < 18)
	{
		x = -1;
		j = 0;
		while (++x < 3)
		{
			i = 4;
			while (i)
			{
				if (((c[n][y][x] >> ((i - 1) * 2)) & 0x3) == 0b00)
					env->l.color = 0;
				else if (((c[n][y][x] >> ((i - 1) * 2)) & 0x3) == 0b10)
					env->l.color = 0x00FFFFFF;
				else if (((c[n][y][x] >> ((i - 1) * 2)) & 0x3) == 0b01)
					env->l.color = 0x007F7F7F;
				else
					env->l.color = 0x00FF0000;
				env->l.x = x + j + posx;
				env->l.y = y + posy;
				mlx_pixel_put_image(env);
				j++;
				i--;
			}
			j--;
		}
	}
}

void	drawaltbar(t_hud *env)
{
	int y = -1;

	y = -1;
	printchar(3, 1, 0, env);
	while (++y < 12)
		printchar(3, y + 2, env->alt % 9 + 1, env);
	printchar(3, 14, 10, env);
}


void	drawheading(t_hud *env)
{
	int x = -1;

	x = -1;
	printchar(5, 1, 11, env);
	while (++x < 18)
		printchar(6 + x, 1, env->head % 6 + 12, env);
	printchar(6 + x, 1, 18, env);
}

void	drawhud(t_hud *env)
{
	drawaltbar(env);
	drawheading(env);
}

